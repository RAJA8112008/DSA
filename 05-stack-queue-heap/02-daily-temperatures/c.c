// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each day i, scan j > i until temperatures[j] > temperatures[i]. Worst case a falling array, so n² compares.

#include <stdlib.h>
int* dailyTemperatures(int* temperatures, int n, int* returnSize) {
  int* ans = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (temperatures[j] > temperatures[i]) { ans[i] = j - i; break; }
    }
  }
  *returnSize = n;
  return ans;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Stack of indices with decreasing temps. When a warmer day arrives, pop until the stack is cooler again. Each index is pushed and popped at most once.

#include <stdlib.h>
int* dailyTemperatures(int* temperatures, int n, int* returnSize) {
  int* ans = (int*)calloc(n, sizeof(int));
  int* st = (int*)malloc(sizeof(int) * n);
  int sn = 0;
  for (int i = 0; i < n; i++) {
    while (sn && temperatures[st[sn - 1]] < temperatures[i]) {
      int j = st[--sn];
      ans[j] = i - j;
    }
    st[sn++] = i;
  }
  free(st);
  *returnSize = n;
  return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Right-to-left jump: if day j is not warmer, skip ahead by ans[j] days (those days are also not warmer than j, hence not warmer than i if temps[j] <= temps[i]). Extra space is only the output. Still linear.

#include <stdlib.h>
int* dailyTemperatures(int* temperatures, int n, int* returnSize) {
  int* ans = (int*)calloc(n, sizeof(int));
  for (int i = n - 2; i >= 0; i--) {
    int j = i + 1;
    while (j < n && temperatures[j] <= temperatures[i]) {
      if (ans[j] == 0) { j = n; break; }
      j += ans[j];
    }
    if (j < n) ans[i] = j - i;
  }
  *returnSize = n;
  return ans;
}
