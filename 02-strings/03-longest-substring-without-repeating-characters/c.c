// Method 1: Brute
// Time: O(n³) | Space: O(n)
// O(n²) substrings, and each uniqueness check can scan the slice again.
// How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int lengthOfLongestSubstring(char* s) {
  /* n is the given length */
  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int seen_keys[1024]; int seen_n = 0;
      int unique = 1;
      for (int k = i; k <= j; k++) {
        if (map_find(seen_keys, seen_n, s[k]) >= 0) { unique = 0; break; }
        /* add */;
      }
      if (unique && j - i + 1 > best) best = j - i + 1;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// From each start, grow right until a repeat. Inner work is O(n), times n starts.
// How it works: seen is a Set for the current window. On a repeat, break and try the next start.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int lengthOfLongestSubstring(char* s) {
  int best = 0;
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    int seen_keys[1024]; int seen_n = 0;
    for (int j = i; j < n; j++) {
      if (map_find(seen_keys, seen_n, s[j]) >= 0) break;
      /* add */;
      if (j - i + 1 > best) best = j - i + 1;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each index is a right endpoint once. left only moves forward. Map stores last indexes.
// How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int lengthOfLongestSubstring(char* s) {
  int last_keys[1024]; int last_vals[1024]; int last_n = 0;
  int left = 0;
  int best = 0;
  for (int right = 0; right < strlen(s); right++) {
    int ch = s[right];
    if (map_find(last_keys, last_n, ch) >= 0 && last.get(ch) >= left) left = last.get(ch) + 1;
    /* set last */;
    int len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}
