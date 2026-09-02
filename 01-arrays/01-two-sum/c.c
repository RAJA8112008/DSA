// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every pair is checked. For n numbers that is about n*(n-1)/2 additions.
// How it works: the outer loop picks the first index. The inner loop picks a later index. The first pair whose sum equals target is returned.

/* pass n for array length; simple loops */
int twoSum(int* nums, int n, int target, int* ans) {
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] + nums[j] == target) { ans[0] = i; ans[1] = j; return 1; };
    }
  }
  return 0;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting is the extra cost. After that, two pointers only walk the copied list once.
// How it works: store {value, index} so sorting does not lose positions. Move left up when the sum is too small, right down when it is too big.

/* pass n for array length; simple loops */
int twoSum(int* nums, int n, int target, int* ans) {
  int pairs[1024]; int pairs_n = 0;
  for (int i = 0; i < n; i++) {
    /* push */([nums[i], i ]);
  }
  /* sort pairs */;

  int left = 0;
  int right = pairs_len - 1;
  while (left < right) {
    int sum = pairs[left].value + pairs[right].value;
    if (sum == target) /* return pairs[left */ return 1.index, pairs[right].index];
    if (sum < target) left++;
    else right--;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Each lookup in the map is average O(1), so the whole walk is O(n).
// How it works: for x, look up target - x. If it was stored, return those indexes. If not, store x and its index, then continue.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int twoSum(int* nums, int n, int target, int* ans) {
  int seen_keys[1024]; int seen_vals[1024]; int seen_n = 0;
  for (int i = 0; i < n; i++) {
    int need = target - nums[i];
    if (map_find(seen_keys, seen_n, need) >= 0) { ans[0] = seen.get(need); ans[1] = i; return 1; };
    /* set seen */;
  }
  return 0;
}
