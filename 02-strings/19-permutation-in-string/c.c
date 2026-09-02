// Method 1: Brute
// Time: O(m! · n) | Space: O(m! · m)
// All unique perms of s1 are generated, then each is searched in s2. Factorial in m.
// How it works: backtracking builds permutations. indexOf each perm in s2; any hit is true.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int checkInclusion(char* s1, char* s2) {
  int bag[1024]; int bag_n = 0;
  void permute(/* arr, from */) {
    if (from == arr_len) {
      /* push */(/* join arr */);
      return;
    }
    int used_keys[1024]; int used_n = 0;
    for (int i = from; i < arr_len; i++) {
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
  permute(/* split s1 */, 0);
  for (int i = 0; i < bag_len; i++) {
    if (/* indexOf */ != -1) return 1;
  }
  return 0;
}


// Method 2: Optimal
// Time: O(n · 26) | Space: O(1)
// Window of size m slides across s2. Each position compares two 26-slot arrays.
// How it works: need counts s1. have counts the current window. If they match, true. Slide by dropping left and adding right.

/* pass n for array length; simple loops */
int checkInclusion(char* s1, char* s2) {
  int m = strlen(s1);
  /* n is the given length */
  if (m > n) return 0;
  int need = /* zeros 26 */;
  int have = /* zeros 26 */;
  for (int i = 0; i < m; i++) {
    need[(int)s1[i] - 97]++;
    have[(int)s2[i] - 97]++;
  }
  void same(/*  */) {
    for (int i = 0; i < 26; i++) if (need[i] != have[i]) return 0;
    return 1;
  }
  if (same()) return 1;
  for (int right = m; right < n; right++) {
    have[(int)s2[right] - 97]++;
    have[(int)s2[right - m] - 97]--;
    if (same()) return 1;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// matches tracks how many of the 26 letters currently have the right count. Each add/drop updates matches in O(1).
// How it works: when have[i] hits need[i], matches++. When it leaves, matches--. matches === 26 (or the number of letters that appear in s1) means the window is a permutation. Here we compare all 26 including zeros, so 26 is the target.

/* pass n for array length; simple loops */
int checkInclusion(char* s1, char* s2) {
  int m = strlen(s1);
  /* n is the given length */
  if (m > n) return 0;
  int need = /* zeros 26 */;
  int have = /* zeros 26 */;
  for (int i = 0; i < m; i++) {
    need[(int)s1[i] - 97]++;
    have[(int)s2[i] - 97]++;
  }
  int matches = 0;
  for (int i = 0; i < 26; i++) if (need[i] == have[i]) matches++;
  if (matches == 26) return 1;
  for (int right = m; right < n; right++) {
    int add = (int)s2[right] - 97;
    int drop = (int)s2[right - m] - 97;
    have[add]++;
    if (have[add] == need[add]) matches++;
    else if (have[add] == need[add] + 1) matches--;
    have[drop]--;
    if (have[drop] == need[drop]) matches++;
    else if (have[drop] == need[drop] - 1) matches--;
    if (matches == 26) return 1;
  }
  return 0;
}
