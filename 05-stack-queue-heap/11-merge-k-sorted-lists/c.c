// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

#include <stdlib.h>
struct ListNode { int val; struct ListNode* next; };
int cmp_int(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
  int cap = 16, n = 0;
  int* vals = (int*)malloc(sizeof(int)*cap);
  for (int i = 0; i < k; i++) {
    struct ListNode* p = lists[i];
    while (p) {
      if (n == cap) { cap *= 2; vals = (int*)realloc(vals, sizeof(int)*cap); }
      vals[n++] = p->val; p = p->next;
    }
  }
  qsort(vals, n, sizeof(int), cmp_int);
  struct ListNode dummy; dummy.next = NULL;
  struct ListNode* cur = &dummy;
  for (int i = 0; i < n; i++) {
    struct ListNode* nd = (struct ListNode*)malloc(sizeof(struct ListNode));
    nd->val = vals[i]; nd->next = NULL;
    cur->next = nd; cur = nd;
  }
  free(vals);
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

#include <stdlib.h>
struct ListNode { int val; struct ListNode* next; };
void up(struct ListNode** h, int i) {
  while (i > 0) { int p=(i-1)>>1; if (h[i]->val >= h[p]->val) break;
    struct ListNode* t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
}
void down(struct ListNode** h, int n, int i) {
  while (1) { int s=i, l=i*2+1, r=l+1;
    if (l<n && h[l]->val < h[s]->val) s=l;
    if (r<n && h[r]->val < h[s]->val) s=r;
    if (s==i) break; struct ListNode* t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
}
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
  struct ListNode** h = (struct ListNode**)malloc(sizeof(struct ListNode*)*(k+1));
  int sz = 0;
  for (int i = 0; i < k; i++) if (lists[i]) { h[sz++] = lists[i]; up(h, sz-1); }
  struct ListNode dummy; dummy.next = NULL;
  struct ListNode* cur = &dummy;
  while (sz) {
    struct ListNode* node = h[0];
    h[0] = h[--sz]; if (sz) down(h, sz, 0);
    cur->next = node; cur = node;
    if (node->next) { h[sz++] = node->next; up(h, sz-1); }
  }
  free(h);
  return dummy.next;
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(log k)
// Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

#include <stdlib.h>
struct ListNode { int val; struct ListNode* next; };
struct ListNode* mergeTwo(struct ListNode* a, struct ListNode* b) {
  struct ListNode dummy; dummy.next = NULL;
  struct ListNode* cur = &dummy;
  while (a && b) {
    if (a->val <= b->val) { cur->next = a; a = a->next; }
    else { cur->next = b; b = b->next; }
    cur = cur->next;
  }
  cur->next = a ? a : b;
  return dummy.next;
}
struct ListNode* split(struct ListNode** lists, int lo, int hi) {
  if (lo == hi) return lists[lo];
  int mid = (lo + hi) >> 1;
  return mergeTwo(split(lists, lo, mid), split(lists, mid + 1, hi));
}
struct ListNode* mergeKLists(struct ListNode** lists, int k) {
  if (k == 0) return NULL;
  return split(lists, 0, k - 1);
}
