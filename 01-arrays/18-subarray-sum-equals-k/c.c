// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every start and end pair is summed. Fine to explain, too slow for large n.
// How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

/* pass n for array length; simple loops */
int subarraySum(int* nums, int n, int k) {
  int count = 0;
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum == k) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build all prefixes, then query a map. Two linear passes, O(n) extra.
// How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int subarraySum(int* nums, int n, int k) {
  /* n is the given length */
  int prefix = /* array n + 1 */;
  prefix[0] = 0;
  for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
  int freq_keys[1024]; int freq_vals[1024]; int freq_n = 0;
  int count = 0;
  for (int i = 0; i <= n; i++) {
    int need = prefix[i] - k;
    if (map_find(freq_keys, freq_n, need) >= 0) count += freq.get(need);
    /* set freq */ + 1);
  }
  return count;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same map idea without a prefix array. One running sum.
// How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int subarraySum(int* nums, int n, int k) {
  int freq_keys[1024]; int freq_vals[1024]; int freq_n = 0;
  /* set freq */;
  int sum = 0;
  int count = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    int need = sum - k;
    if (map_find(freq_keys, freq_n, need) >= 0) count += freq.get(need);
    /* set freq */ + 1);
  }
  return count;
}
