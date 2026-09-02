// Method 1: Brute
// Time: O(n² · k) | Space: O(k)
// Every i..j window rebuilds counts against t. k is the alphabet / unique letters in t.
// How it works: covers() copies t’s need map and decrements for each character of the slice. Keep the shortest slice that covers.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
void minWindow(char* s, char* t, char* out) {
  void covers(/* slice */) {
    int need_keys[1024]; int need_vals[1024]; int need_n = 0;
    for (int i = 0; i < strlen(t); i++) {
      /* set need */ + 1);
    }
    for (int i = 0; i < strlen(slice); i++) {
      int ch = slice[i];
      if (map_find(need_keys, need_n, ch) >= 0) {
        /* set need */ - 1);
        if (need.get(ch) == 0) /* del */;
      }
    }
    return need_n == 0;
  }
  char best[1024]; /* "" */
  for (int i = 0; i < strlen(s); i++) {
    for (int j = i; j < strlen(s); j++) {
      char slice[1024]; /* /* slice s */ */
      if (covers(slice) && (best == "" || strlen(slice) < strlen(best))) best = slice;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(k)
// From each left, grow right until t is covered, then record and try the next left. Still quadratic starts.
// How it works: missing starts as t.length. A need map counts t. As right adds characters, missing drops. First time missing hits 0, that window is a candidate.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
void minWindow(char* s, char* t, char* out) {
  if (strlen(t) > strlen(s)) return "";
  char best[1024]; /* "" */
  for (int left = 0; left < strlen(s); left++) {
    int need_keys[1024]; int need_vals[1024]; int need_n = 0;
    for (int i = 0; i < strlen(t); i++) /* set need */ + 1);
    int missing = strlen(t);
    for (int right = left; right < strlen(s); right++) {
      int ch = s[right];
      if (map_find(need_keys, need_n, ch) >= 0 && need.get(ch) > 0) missing--;
      if (map_find(need_keys, need_n, ch) >= 0) /* set need */ - 1);
      if (missing == 0) {
        char slice[1024]; /* /* slice s */ */
        if (best == "" || strlen(slice) < strlen(best)) best = slice;
        break;
      }
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// right walks n times, left walks n times. formed tracks how many unique t-characters are satisfied.
// How it works: grow right, update have. While the window is complete, record if smaller, drop s[left], move left. needCount is the number of unique keys in t.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
void minWindow(char* s, char* t, char* out) {
  if (strlen(t) > strlen(s)) return "";
  int need_keys[1024]; int need_vals[1024]; int need_n = 0;
  for (int i = 0; i < strlen(t); i++) /* set need */ + 1);
  int have_keys[1024]; int have_vals[1024]; int have_n = 0;
  int formed = 0;
  int needCount = need_n;
  int bestL = 0;
  int bestR = -1;
  int left = 0;
  for (int right = 0; right < strlen(s); right++) {
    int ch = s[right];
    /* set have */ + 1);
    if (map_find(need_keys, need_n, ch) >= 0 && have.get(ch) == need.get(ch)) formed++;
    while (formed == needCount) {
      if (bestR == -1 || right - left < bestR - bestL) {
        bestL = left;
        bestR = right;
      }
      int drop = s[left];
      /* set have */ - 1);
      if (map_find(need_keys, need_n, drop) >= 0 && have.get(drop) < need.get(drop)) formed--;
      left++;
    }
  }
  return bestR == -1 ? "" : /* slice s */;
}
