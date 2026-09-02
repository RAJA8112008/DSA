// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

#include <stdlib.h>
typedef struct { int val; int dist; } Pair;
int cmpPair(const void* a, const void* b) {
  const Pair* p = (const Pair*)a, *q = (const Pair*)b;
  if (p->dist != q->dist) return p->dist - q->dist;
  return p->val - q->val;
}
int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
void findClosestElements(int* arr, int n, int k, int x, int* out) {
  Pair* p = (Pair*)malloc(sizeof(Pair) * n);
  for (int i = 0; i < n; i++) { p[i].val = arr[i]; p[i].dist = arr[i] > x ? arr[i] - x : x - arr[i]; }
  qsort(p, n, sizeof(Pair), cmpPair);
  for (int i = 0; i < k; i++) out[i] = p[i].val;
  qsort(out, k, sizeof(int), cmpInt);
  free(p);
}


// Method 2: Optimal
// Time: O(n - k) | Space: O(k)
// The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

void findClosestElements(int* arr, int n, int k, int x, int* out) {
  int lo = 0, hi = n - 1;
  while (hi - lo + 1 > k) {
    int dl = arr[lo] > x ? arr[lo] - x : x - arr[lo];
    int dr = arr[hi] > x ? arr[hi] - x : x - arr[hi];
    if (dl > dr) lo++;
    else hi--;
  }
  for (int i = 0; i < k; i++) out[i] = arr[lo + i];
}


// Method 3: More optimal
// Time: O(log(n - k) + k) | Space: O(k)
// Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

void findClosestElements(int* arr, int n, int k, int x, int* out) {
  int lo = 0, hi = n - k;
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
    else hi = mid;
  }
  for (int i = 0; i < k; i++) out[i] = arr[lo + i];
}
