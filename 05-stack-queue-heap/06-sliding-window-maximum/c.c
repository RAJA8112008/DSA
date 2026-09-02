// Method 1: Brute
// Time: O(n · k) | Space: O(1)
// For each window start, scan k items for the max. Simple and too slow when k is n/2.

#include <stdlib.h>
int* maxSlidingWindow(int* nums, int n, int k, int* returnSize) {
  int m = n - k + 1;
  int* out = (int*)malloc(sizeof(int) * m);
  for (int i = 0; i < m; i++) {
    int mx = nums[i];
    for (int j = i + 1; j < i + k; j++) if (nums[j] > mx) mx = nums[j];
    out[i] = mx;
  }
  *returnSize = m;
  return out;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

#include <stdlib.h>
/* min-heap of (key, idx); store -value as key so max comes first */
void up(int* k, int* ix, int i) {
  while (i > 0) { int p = (i-1)>>1; if (k[i] >= k[p]) break;
    int t=k[i]; k[i]=k[p]; k[p]=t; t=ix[i]; ix[i]=ix[p]; ix[p]=t; i=p; }
}
void down(int* k, int* ix, int n, int i) {
  while (1) { int s=i, l=i*2+1, r=l+1;
    if (l<n && k[l]<k[s]) s=l; if (r<n && k[r]<k[s]) s=r;
    if (s==i) break; int t=k[i]; k[i]=k[s]; k[s]=t; t=ix[i]; ix[i]=ix[s]; ix[s]=t; i=s; }
}
int* maxSlidingWindow(int* nums, int n, int k, int* returnSize) {
  int* hk = (int*)malloc(sizeof(int)*n);
  int* hi = (int*)malloc(sizeof(int)*n);
  int sz = 0;
  int* out = (int*)malloc(sizeof(int)*(n-k+1));
  int p = 0;
  for (int i = 0; i < n; i++) {
    hk[sz] = -nums[i]; hi[sz] = i; sz++; up(hk, hi, sz-1);
    if (i < k-1) continue;
    while (hi[0] <= i-k) {
      sz--; if (sz) { hk[0]=hk[sz]; hi[0]=hi[sz]; down(hk, hi, sz, 0); }
    }
    out[p++] = -hk[0];
  }
  free(hk); free(hi);
  *returnSize = p;
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

#include <stdlib.h>
int* maxSlidingWindow(int* nums, int n, int k, int* returnSize) {
  int* dq = (int*)malloc(sizeof(int)*n);
  int head = 0, tail = 0;
  int* out = (int*)malloc(sizeof(int)*(n-k+1));
  int p = 0;
  for (int i = 0; i < n; i++) {
    while (head < tail && nums[dq[tail-1]] <= nums[i]) tail--;
    dq[tail++] = i;
    if (dq[head] <= i - k) head++;
    if (i >= k - 1) out[p++] = nums[dq[head]];
  }
  free(dq);
  *returnSize = p;
  return out;
}
