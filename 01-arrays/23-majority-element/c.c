// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate you count how many times it appears. Quadratic comparisons.
// How it works: if a value’s count is > n/2, return it.

/* pass n for array length; simple loops */
int majorityElement(int* nums, int n) {
  /* n is the given length */
  int need = (n / 2);
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (nums[j] == nums[i]) count++;
    }
    if (count > need) return nums[i];
  }
  return nums[0];
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One pass over the list, extra map of distinct values.
// How it works: increment counts. As soon as a count exceeds n/2, return that key.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int majorityElement(int* nums, int n) {
  int freq_keys[1024]; int freq_vals[1024]; int freq_n = 0;
  int need = (n / 2);
  for (int i = 0; i < n; i++) {
    int x = nums[i];
    /* set freq */ + 1);
    if (freq.get(x) > need) return x;
  }
  return nums[0];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Boyer–Moore: two integers, one pass. Because a majority exists, the last candidate is it.
// How it works: vote for the current candidate. Matching values add a vote; others subtract. At 0, pick a new candidate.

/* pass n for array length; simple loops */
int majorityElement(int* nums, int n) {
  int candidate = nums[0];
  int vote = 0;
  for (int i = 0; i < n; i++) {
    if (vote == 0) candidate = nums[i];
    vote += nums[i] == candidate ? 1 : -1;
  }
  return candidate;
}
