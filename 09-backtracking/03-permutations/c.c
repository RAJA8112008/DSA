// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

void go(int* left, int nleft, int* path, int len) {
  int i, k, t, tmp;
  if (nleft == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (i = 0; i < nleft; i++) {
    path[len] = left[i];
    tmp = left[i];
    for (k = i; k < nleft - 1; k++) left[k] = left[k + 1];
    go(left, nleft - 1, path, len + 1);
    for (k = nleft - 1; k > i; k--) left[k] = left[k - 1];
    left[i] = tmp;
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

void go(int* nums, int n, int* used, int* path, int len) {
  int j, k;
  if (len == n) {
    for (k = 0; k < n; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (j = 0; j < n; j++) {
    if (used[j]) continue;
    used[j] = 1; path[len] = nums[j];
    go(nums, n, used, path, len + 1);
    used[j] = 0;
  }
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

void go(int* nums, int n, int start) {
  int i, k, t;
  if (start == n) {
    for (k = 0; k < n; k++) printf("%d ", nums[k]);
    printf("\n");
    return;
  }
  for (i = start; i < n; i++) {
    t = nums[start]; nums[start] = nums[i]; nums[i] = t;
    go(nums, n, start + 1);
    t = nums[start]; nums[start] = nums[i]; nums[i] = t;
  }
}
