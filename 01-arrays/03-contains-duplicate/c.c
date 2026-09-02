// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Each pair is compared. Fine for tiny lists, too slow for large n.
// How it works: if nums[i] equals nums[j] for j > i, a duplicate exists.

/* pass n for array length; simple loops */
int containsDuplicate(int* nums, int n) {
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] == nums[j]) return 1;
    }
  }
  return 0;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Copy then sort, then a linear neighbor check. Sorting dominates.
// How it works: equals become neighbors after sort. If two neighbors match, return true.

/* pass n for array length; simple loops */
int containsDuplicate(int* nums, int n) {
  int copy = nums;
  /* sort copy */;
  for (int i = 1; i < n; i++) {
    if (copy[i] == copy[i - 1]) return 1;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Set.has is average O(1).
// How it works: if the set already has the number, it is a duplicate. Otherwise add it.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int containsDuplicate(int* nums, int n) {
  int seen_keys[1024]; int seen_n = 0;
  for (int i = 0; i < n; i++) {
    if (map_find(seen_keys, seen_n, nums[i]) >= 0) return 1;
    /* add */;
  }
  return 0;
}
