// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Generic sort does not use the fact there are only three values. Engine sort also uses extra memory.
// How it works: nums.sort with a numeric comparator. Correct, but not the point of the problem.

/* pass n for array length; simple loops */
void sortColors(int* nums, int n) {
  /* sort nums */;
  return nums;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// Two linear passes and three counters. Extra memory is three integers.
// How it works: count zeros, ones, and twos. Write that many 0s, then 1s, then 2s into nums.

/* pass n for array length; simple loops */
void sortColors(int* nums, int n) {
  int zeros = 0;
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] == 0) zeros++;
    else if (nums[i] == 1) ones++;
    else twos++;
  }
  int i = 0;
  while (zeros > 0) { zeros--; nums[i] = 0; i++; }
  while (ones > 0) { ones--; nums[i] = 1; i++; }
  while (twos > 0) { twos--; nums[i] = 2; i++; }
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass, constant extra memory. Each index is visited a constant number of times.
// How it works: low writes 0s, high writes 2s, mid walks. After a swap with high, mid stays so the swapped-in value is classified.

/* pass n for array length; simple loops */
void sortColors(int* nums, int n) {
  int low = 0;
  int mid = 0;
  int high = n - 1;
  while (mid <= high) {
    if (nums[mid] == 0) {
      int t = nums[low];
      nums[low] = nums[mid];
      nums[mid] = t;
      low++;
      mid++;
    } else if (nums[mid] == 2) {
      int t = nums[high];
      nums[high] = nums[mid];
      nums[mid] = t;
      high--;
    } else {
      mid++;
    }
  }
  return nums;
}
