// Method 1: Brute
// Time: O(n + u · k) | Space: O(u)
// Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

#include <stdlib.h>
int* topKFrequent(int* nums, int n, int k, int* returnSize) {
  int* keys = (int*)malloc(sizeof(int)*n);
  int* cnt = (int*)malloc(sizeof(int)*n);
  int u = 0;
  for (int i = 0; i < n; i++) {
    int f = -1;
    for (int j = 0; j < u; j++) if (keys[j] == nums[i]) { f = j; break; }
    if (f < 0) { keys[u] = nums[i]; cnt[u] = 1; u++; }
    else cnt[f]++;
  }
  int* ans = (int*)malloc(sizeof(int)*k);
  int used[256]; /* mark removed unique slots; u is small in interviews */
  int* gone = (int*)calloc(u, sizeof(int));
  for (int t = 0; t < k; t++) {
    int best = -1, bi = 0;
    for (int j = 0; j < u; j++) if (!gone[j] && cnt[j] > best) { best = cnt[j]; bi = j; }
    ans[t] = keys[bi]; gone[bi] = 1;
  }
  free(keys); free(cnt); free(gone);
  *returnSize = k;
  return ans;
}


// Method 2: Optimal
// Time: O(n + u log u) | Space: O(u)
// Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

#include <stdlib.h>
int* topKFrequent(int* nums, int n, int k, int* returnSize) {
  int* keys = (int*)malloc(sizeof(int)*n);
  int* cnt = (int*)malloc(sizeof(int)*n);
  int u = 0;
  for (int i = 0; i < n; i++) {
    int f = -1;
    for (int j = 0; j < u; j++) if (keys[j] == nums[i]) { f = j; break; }
    if (f < 0) { keys[u] = nums[i]; cnt[u] = 1; u++; }
    else cnt[f]++;
  }
  for (int i = 0; i < u; i++) {
    int bi = i;
    for (int j = i + 1; j < u; j++) if (cnt[j] > cnt[bi]) bi = j;
    int tk = keys[i]; keys[i] = keys[bi]; keys[bi] = tk;
    int tc = cnt[i]; cnt[i] = cnt[bi]; cnt[bi] = tc;
  }
  *returnSize = k;
  free(cnt);
  return keys; /* first k */
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

#include <stdlib.h>
int* topKFrequent(int* nums, int n, int k, int* returnSize) {
  int* keys = (int*)malloc(sizeof(int)*n);
  int* cnt = (int*)malloc(sizeof(int)*n);
  int u = 0;
  for (int i = 0; i < n; i++) {
    int f = -1;
    for (int j = 0; j < u; j++) if (keys[j] == nums[i]) { f = j; break; }
    if (f < 0) { keys[u] = nums[i]; cnt[u] = 1; u++; }
    else cnt[f]++;
  }
  /* buckets[f] = list of keys with count f; store as linked via arrays */
  int* bhead = (int*)malloc(sizeof(int)*(n+1));
  int* bnext = (int*)malloc(sizeof(int)*u);
  for (int i = 0; i <= n; i++) bhead[i] = -1;
  for (int j = 0; j < u; j++) { bnext[j] = bhead[cnt[j]]; bhead[cnt[j]] = j; }
  int* ans = (int*)malloc(sizeof(int)*k);
  int p = 0;
  for (int f = n; f >= 0 && p < k; f--) {
    for (int j = bhead[f]; j != -1 && p < k; j = bnext[j]) ans[p++] = keys[j];
  }
  free(keys); free(cnt); free(bhead); free(bnext);
  *returnSize = k;
  return ans;
}
