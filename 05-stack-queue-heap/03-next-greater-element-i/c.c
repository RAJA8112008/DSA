// Method 1: Brute
// Time: O(n · m) | Space: O(1)
// For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

#include <stdlib.h>
int* nextGreaterElement(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
  int* ans = (int*)malloc(sizeof(int) * n1);
  for (int i = 0; i < n1; i++) {
    int found = 0, next = -1;
    for (int j = 0; j < n2; j++) {
      if (!found) { if (nums2[j] == nums1[i]) found = 1; continue; }
      if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
    }
    ans[i] = next;
  }
  *returnSize = n1;
  return ans;
}


// Method 2: Optimal
// Time: O(n · m) | Space: O(m)
// Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

#include <stdlib.h>
/* linear search as a tiny map: find first index of x in nums2 */
int find_idx(int* a, int n, int x) {
  for (int i = 0; i < n; i++) if (a[i] == x) return i;
  return -1;
}
int* nextGreaterElement(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
  int* ans = (int*)malloc(sizeof(int) * n1);
  for (int i = 0; i < n1; i++) {
    int j0 = find_idx(nums2, n2, nums1[i]);
    int next = -1;
    for (int j = j0 + 1; j < n2; j++) if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
    ans[i] = next;
  }
  *returnSize = n1;
  return ans;
}


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

#include <stdlib.h>
/* next_of[val+offset] since values are small in the problem; here we scan a pair table */
int* nextGreaterElement(int* nums1, int n1, int* nums2, int n2, int* returnSize) {
  int* st = (int*)malloc(sizeof(int) * n2);
  int sn = 0;
  int* keys = (int*)malloc(sizeof(int) * n2);
  int* vals = (int*)malloc(sizeof(int) * n2);
  int m = 0;
  for (int i = 0; i < n2; i++) {
    while (sn && st[sn - 1] < nums2[i]) { keys[m] = st[--sn]; vals[m] = nums2[i]; m++; }
    st[sn++] = nums2[i];
  }
  int* ans = (int*)malloc(sizeof(int) * n1);
  for (int i = 0; i < n1; i++) {
    int next = -1;
    for (int k = 0; k < m; k++) if (keys[k] == nums1[i]) { next = vals[k]; break; }
    ans[i] = next;
  }
  free(st); free(keys); free(vals);
  *returnSize = n1;
  return ans;
}
