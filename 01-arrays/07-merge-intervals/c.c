// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each merge pass can scan all remaining pairs. Several passes still stay quadratic for typical n.
// How it works: copy intervals. While any two overlap, replace them with their union and restart the pair scan.

/* pass n for array length; simple loops */
int mergeIntervals(int intervals[][2], int n, int out[][2]) {
  int out[1024]; int out_n = 0;
  for (int i = 0; i < n; i++) {
    /* push */([intervals[i][0], intervals[i][1]]);
  }
  int changed = 1;
  while (changed) {
    changed = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int a = out[i];
        int b = out[j];
        if (a[0] <= b[1] && b[0] <= a[1]) {
          a[0] = (a[0] < b[0] ? a[0] : b[0]);
          a[1] = (a[1] > b[1] ? a[1] : b[1]);
          /* erase */;
          changed = 1;
          break;
        }
      }
      if (changed) break;
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort by start, then one linear merge. Sorting is the bottleneck.
// How it works: after sort, only the last merged interval can overlap the next one. Stretch its end or push a new block.

/* pass n for array length; simple loops */
int mergeIntervals(int intervals[][2], int n, int out[][2]) {
  if (n == 0) return {};
  int list = intervals /* copy pairs */;
  /* sort list by start */;
  int merged = [list[0]];
  for (int i = 1; i < n; i++) {
    int last = merged[merged_len - 1];
    if (list[i][0] <= last[1]) {
      last[1] = (last[1] > list[i][1] ? last[1] : list[i][1]);
    } else {
      /* push */(list[i]);
    }
  }
  return merged;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same O(n log n) bound: you must sort unless the input is already ordered. This version sorts a copy once and writes merged ranges without extra pass flags.
// How it works: identical merge walk, with an early return for an empty list and copies so caller intervals stay untouched.

/* pass n for array length; simple loops */
int mergeIntervals(int intervals[][2], int n, int out[][2]) {
  /* n is the given length */
  if (n == 0) return {};
  int list = /* array n */;
  for (int i = 0; i < n; i++) list[i] = [intervals[i][0], intervals[i][1]];
  /* sort list by start */;
  int merged[1024]; int merged_n = 0;
  int start = list[0][0];
  int end = list[0][1];
  for (int i = 1; i < n; i++) {
    if (list[i][0] <= end) {
      if (list[i][1] > end) end = list[i][1];
    } else {
      /* push */([start, end]);
      start = list[i][0];
      end = list[i][1];
    }
  }
  /* push */([start, end]);
  return merged;
}
