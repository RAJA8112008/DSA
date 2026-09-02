// Method 1: Brute
// Time: O(n · k) | Space: O(n)
// Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

#include <stdlib.h>
int findKthLargest(int* nums, int n, int k) {
  int* a = (int*)malloc(sizeof(int)*n);
  int m = n, ans = 0;
  for (int i = 0; i < n; i++) a[i] = nums[i];
  for (int t = 0; t < k; t++) {
    int best = 0;
    for (int i = 1; i < m; i++) if (a[i] > a[best]) best = i;
    ans = a[best];
    for (int i = best; i < m - 1; i++) a[i] = a[i+1];
    m--;
  }
  free(a);
  return ans;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

#include <stdlib.h>
int cmp_desc(const void* a, const void* b) { return *(const int*)b - *(const int*)a; }
int findKthLargest(int* nums, int n, int k) {
  int* a = (int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) a[i] = nums[i];
  qsort(a, n, sizeof(int), cmp_desc);
  int ans = a[k - 1];
  free(a);
  return ans;
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

#include <stdlib.h>
void up(int* h, int i) {
  while (i > 0) { int p=(i-1)>>1; if (h[i]>=h[p]) break; int t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
}
void down(int* h, int n, int i) {
  while (1) { int s=i, l=i*2+1, r=l+1;
    if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
    if (s==i) break; int t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
}
int findKthLargest(int* nums, int n, int k) {
  int* h = (int*)malloc(sizeof(int)*k);
  int sz = 0;
  for (int i = 0; i < n; i++) {
    if (sz < k) { h[sz++] = nums[i]; up(h, sz-1); }
    else if (nums[i] > h[0]) {
      h[0] = h[--sz]; if (sz) down(h, sz, 0);
      h[sz++] = nums[i]; up(h, sz-1);
    }
  }
  int ans = h[0];
  free(h);
  return ans;
}
