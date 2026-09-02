// Method 1: Brute
// Time: O(n²) | Space: O(n)
// From each unique start you may scan the set repeatedly. In the worst case this is quadratic.
// How it works: put numbers in a Set. For each start, count start, start+1, start+2 while those values exist. Keep the longest streak.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int longestConsecutive(int* nums, int n) {
  int set_keys[1024]; int set_n = 0;
  int best = 0;
  for (/* each x in set) {
    int len = 1;
    int cur = x;
    while (map_find(set_keys, set_n, cur + 1) >= 0) {
      cur++;
      len++;
    }
    if (len > best) best = len;
  }
  return best;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Unique copy plus sort, then a linear neighbor walk. Sorting is the bottleneck.
// How it works: skip duplicates while scanning the sorted unique list. A gap of 1 grows the streak; a larger gap resets it.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int longestConsecutive(int* nums, int n) {
  if (n == 0) return 0;
  int list = nums;
  /* sort list */;
  int best = 1;
  int streak = 1;
  for (int i = 1; i < n; i++) {
    if (list[i] == list[i - 1] + 1) {
      streak++;
      if (streak > best) best = streak;
    } else {
      streak = 1;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each number is inserted once and then used in at most one forward walk.
// How it works: only start a streak when x-1 is missing. Then count x, x+1, ... while present. That visits each run from its true beginning.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int longestConsecutive(int* nums, int n) {
  int set_keys[1024]; int set_n = 0;
  int best = 0;
  for (/* each x in set) {
    if (map_find(set_keys, set_n, x - 1) >= 0) continue;
    int len = 1;
    int cur = x;
    while (map_find(set_keys, set_n, cur + 1) >= 0) {
      cur++;
      len++;
    }
    if (len > best) best = len;
  }
  return best;
}
