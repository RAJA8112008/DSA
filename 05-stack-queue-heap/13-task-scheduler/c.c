// Method 1: Brute
// Time: O(k^t) | Space: O(k)
// At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

#include <string.h>
#include <limits.h>
/* 26 letters: count[26], cool[26] next free time */
int best_g;
int left26(int* count) { int s=0; for (int i=0;i<26;i++) s+=count[i]; return s; }
void dfs_ts(int time, int* count, int* cool, int n) {
  if (time >= best_g) return;
  if (!left26(count)) { best_g = time; return; }
  int placed = 0;
  for (int t = 0; t < 26; t++) {
    if (count[t] == 0) continue;
    if (cool[t] > time) continue;
    placed = 1;
    count[t]--;
    int old = cool[t];
    cool[t] = time + n + 1;
    dfs_ts(time + 1, count, cool, n);
    cool[t] = old;
    count[t]++;
  }
  if (!placed) dfs_ts(time + 1, count, cool, n);
}
int leastInterval(char* tasks, int ntasks, int n) {
  int count[26] = {0}, cool[26] = {0};
  for (int i = 0; i < ntasks; i++) count[tasks[i]-'A']++;
  best_g = INT_MAX;
  dfs_ts(0, count, cool, n);
  return best_g;
}


// Method 2: Optimal
// Time: O(t log k) | Space: O(k)
// Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

#include <stdlib.h>
/* max-heap of remaining counts; cool queue of (left, readyTime) */
void upmax(int* h, int i) {
  while (i > 0) { int p=(i-1)>>1; if (h[i] <= h[p]) break; int t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
}
void downmax(int* h, int n, int i) {
  while (1) { int s=i, l=i*2+1, r=l+1;
    if (l<n && h[l]>h[s]) s=l; if (r<n && h[r]>h[s]) s=r;
    if (s==i) break; int t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
}
int leastInterval(char* tasks, int ntasks, int n) {
  int freq[26] = {0};
  for (int i = 0; i < ntasks; i++) freq[tasks[i]-65]++;
  int h[26], sz = 0;
  for (int i = 0; i < 26; i++) if (freq[i]) { h[sz++] = freq[i]; upmax(h, sz-1); }
  int cl[26], ct[26], ch=0, ct1=0; /* cool queue */
  int time = 0;
  while (sz || ch < ct1) {
    time++;
    if (sz) {
      int left = h[0] - 1;
      h[0] = h[--sz]; if (sz) downmax(h, sz, 0);
      if (left) { cl[ct1] = left; ct[ct1] = time + n; ct1++; }
    }
    if (ch < ct1 && ct[ch] == time) {
      h[sz++] = cl[ch++]; upmax(h, sz-1);
    }
  }
  return time;
}


// Method 3: More optimal
// Time: O(t) | Space: O(1)
// The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

int leastInterval(char* tasks, int ntasks, int n) {
  int freq[26] = {0};
  for (int i = 0; i < ntasks; i++) freq[tasks[i]-65]++;
  int maxF = 0, maxCount = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > maxF) { maxF = freq[i]; maxCount = 1; }
    else if (freq[i] == maxF) maxCount++;
  }
  int frame = (maxF - 1) * (n + 1) + maxCount;
  return frame > ntasks ? frame : ntasks;
}
