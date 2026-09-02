// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL) {} };
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> vals;
    for (auto p : lists) while (p) { vals.push_back(p->val); p = p->next; }
    sort(vals.begin(), vals.end());
    ListNode dummy(0), *cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
  }
};


// Method 2: Optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL) {} };
class Solution {
  vector<ListNode*> h;
  int key(ListNode* x) { return x->val; }
  void up(int i) {
    while (i > 0) { int p=(i-1)>>1; if (key(h[i])>=key(h[p])) break; swap(h[i], h[p]); i=p; }
  }
  void down(int i) {
    int n=(int)h.size();
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && key(h[l])<key(h[s])) s=l; if (r<n && key(h[r])<key(h[s])) s=r;
      if (s==i) break; swap(h[i], h[s]); i=s; }
  }
  void push(ListNode* node) { h.push_back(node); up((int)h.size()-1); }
  ListNode* pop() {
    ListNode* top = h[0]; ListNode* last = h.back(); h.pop_back();
    if (!h.empty()) { h[0] = last; down(0); }
    return top;
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    for (auto node : lists) if (node) push(node);
    ListNode dummy(0), *cur = &dummy;
    while (!h.empty()) {
      ListNode* node = pop();
      cur->next = node; cur = node;
      if (node->next) push(node->next);
    }
    return dummy.next;
  }
};


// Method 3: More optimal
// Time: O(n log k) | Space: O(log k)
// Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(NULL) {} };
class Solution {
  ListNode* mergeTwo(ListNode* a, ListNode* b) {
    ListNode dummy(0), *cur = &dummy;
    while (a && b) {
      if (a->val <= b->val) { cur->next = a; a = a->next; }
      else { cur->next = b; b = b->next; }
      cur = cur->next;
    }
    cur->next = a ? a : b;
    return dummy.next;
  }
  ListNode* split(vector<ListNode*>& lists, int lo, int hi) {
    if (lo == hi) return lists[lo];
    int mid = (lo + hi) >> 1;
    return mergeTwo(split(lists, lo, mid), split(lists, mid + 1, hi));
  }
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;
    return split(lists, 0, (int)lists.size() - 1);
  }
};
