// Method 1: Brute
// Time: O(k^t) | Space: O(k)
// At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

class Solution {
  int best;
  int left(unordered_map<char,int>& count) {
    int s = 0; for (auto& p : count) s += p.second; return s;
  }
  void dfs(int time, unordered_map<char,int>& count, unordered_map<char,int>& cool, int n) {
    if (time >= best) return;
    if (!left(count)) { best = time; return; }
    bool placed = false;
    vector<char> types;
    for (auto& p : count) types.push_back(p.first);
    for (char t : types) {
      if (count[t] == 0) continue;
      if (cool[t] > time) continue;
      placed = true;
      count[t]--;
      int old = cool[t];
      cool[t] = time + n + 1;
      dfs(time + 1, count, cool, n);
      cool[t] = old;
      count[t]++;
    }
    if (!placed) dfs(time + 1, count, cool, n);
  }
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> count, cool;
    for (char t : tasks) count[t]++;
    best = INT_MAX;
    dfs(0, count, cool, n);
    return best;
  }
};


// Method 2: Optimal
// Time: O(t log k) | Space: O(k)
// Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

class Solution {
  vector<int> h;
  void up(int i) {
    while (i > 0) { int p=(i-1)>>1; if (h[i] <= h[p]) break; swap(h[i], h[p]); i=p; }
  }
  void down(int i) {
    int n=(int)h.size();
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && h[l]>h[s]) s=l; if (r<n && h[r]>h[s]) s=r;
      if (s==i) break; swap(h[i], h[s]); i=s; }
  }
  void push(int x) { h.push_back(x); up((int)h.size()-1); }
  int pop() { int top=h[0]; h[0]=h.back(); h.pop_back(); if (!h.empty()) down(0); return top; }
public:
  int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {};
    for (char t : tasks) freq[t - 65]++;
    for (int i = 0; i < 26; i++) if (freq[i]) push(freq[i]);
    queue<pair<int,int>> cool;
    int time = 0;
    while (!h.empty() || !cool.empty()) {
      time++;
      if (!h.empty()) {
        int left = pop() - 1;
        if (left) cool.push({left, time + n});
      }
      if (!cool.empty() && cool.front().second == time) { push(cool.front().first); cool.pop(); }
    }
    return time;
  }
};


// Method 3: More optimal
// Time: O(t) | Space: O(1)
// The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    int freq[26] = {};
    for (char t : tasks) freq[t - 65]++;
    int maxF = 0, maxCount = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > maxF) { maxF = freq[i]; maxCount = 1; }
      else if (freq[i] == maxF) maxCount++;
    }
    int frame = (maxF - 1) * (n + 1) + maxCount;
    return max(frame, (int)tasks.size());
  }
};
