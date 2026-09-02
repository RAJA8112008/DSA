// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

/* extra path copy into tmp[] on every take */
void go(int* nums, int n, int i, int* path, int len, int* tmp) {
  int k;
  if (i == n) {
    printf("[");
    for (k = 0; k < len; k++) { if (k) printf(","); printf("%d", path[k]); }
    printf("]\n");
    return;
  }
  go(nums, n, i + 1, path, len, tmp);
  for (k = 0; k < len; k++) tmp[k] = path[k];
  tmp[len] = nums[i];
  go(nums, n, i + 1, tmp, len + 1, path);
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

void go(int* nums, int n, int i, int* path, int len) {
  int k;
  if (i == n) {
    printf("[");
    for (k = 0; k < len; k++) { if (k) printf(","); printf("%d", path[k]); }
    printf("]\n");
    return;
  }
  go(nums, n, i + 1, path, len);
  path[len] = nums[i];
  go(nums, n, i + 1, path, len + 1);
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

/* out[mask] written as a subset; caller allocates 1<<n slots */
void subsets(int* nums, int n, int** out, int* lens) {
  int total = 1 << n, mask, i, k;
  for (mask = 0; mask < total; mask++) {
    k = 0;
    for (i = 0; i < n; i++) if (mask & (1 << i)) out[mask][k++] = nums[i];
    lens[mask] = k;
  }
}
