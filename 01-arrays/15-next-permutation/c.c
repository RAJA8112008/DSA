// Method 1: Brute
// Time: O(n! · n) | Space: O(n! · n)
// All unique permutations are generated and stored. n! grows immediately out of interview time limits.
// How it works: backtracking builds every perm. Sort the bag lexicographically. Find the current sequence and copy the next one (or the first) back into nums.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
void nextPermutation(int* nums, int n) {
  /* n is the given length */
  int start = nums;
  int bag[1024]; int bag_n = 0;

  void permute(/* arr, from */) {
    if (from == n) {
      /* push */(arr);
      return;
    }
    int used_keys[1024]; int used_n = 0;
    for (int i = from; i < n; i++) {
      if (map_find(used_keys, used_n, arr[i]) >= 0) continue;
      /* add */;
      int t = arr[from];
      arr[from] = arr[i];
      arr[i] = t;
      permute(arr, from + 1);
      arr[i] = arr[from];
      arr[from] = t;
    }
  }

  permute(nums, 0);
  bag.__SORTLEX();

  int idx = 0;
  for (int i = 0; i < bag_len; i++) {
    int same = 1;
    for (int j = 0; j < n; j++) {
      if (bag[i][j] != start[j]) {
        same = 0;
        break;
      }
    }
    if (same) {
        idx = i;
        break;
      }
  }
  int next = bag[(idx + 1) % bag_len];
  for (int i = 0; i < n; i++) nums[i] = next[i];
  return nums;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1)
// One reverse scan for the pivot, then a sort of the suffix. Sort of n items is the extra log factor.
// How it works: find the rightmost i with nums[i] < nums[i+1]. Find the smallest value to the right that is still larger than nums[i], swap, then sort the suffix ascending.

/* pass n for array length; simple loops */
void nextPermutation(int* nums, int n) {
  /* n is the given length */
  int i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;
  if (i >= 0) {
    int j = n - 1;
    while (nums[j] <= nums[i]) j--;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  int suffix = /* slice nums */./* sort */;
  for (int k = 0; k < suffix_len; k++) nums[i + 1 + k] = suffix[k];
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The suffix is already non-increasing, so reverse is enough instead of sort.
// How it works: same pivot and swap. Reverse nums[i+1 .. end] in place.

/* pass n for array length; simple loops */
void nextPermutation(int* nums, int n) {
  /* n is the given length */
  int i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;

  void reverse(/* left, right */) {
    while (left < right) {
      int t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      left++;
      right--;
    }
  }

  if (i >= 0) {
    int j = n - 1;
    while (nums[j] <= nums[i]) j--;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  reverse(i + 1, n - 1);
  return nums;
}
