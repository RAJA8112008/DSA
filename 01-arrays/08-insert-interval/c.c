// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Add the new interval, then reuse the quadratic merge-until-stable idea.
// How it works: push a copy of newInterval onto a copied list, then glue overlaps with nested scans until the list is stable.

/* pass n for array length; simple loops */
int insertInterval(int intervals[][2], int n, int ns, int ne, int out[][2]) {
  int out[1024]; int out_n = 0;
  for (int i = 0; i < n; i++) {
    /* push */([intervals[i][0], intervals[i][1]]);
  }
  /* push */([newInterval[0], newInterval[1]]);
  int changed = 1;
  while (changed) {
    changed = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (out[i][0] <= out[j][1] && out[j][0] <= out[i][1]) {
          out[i][0] = (out[i][0] < out[j][0] ? out[i][0] : out[j][0]);
          out[i][1] = (out[i][1] > out[j][1] ? out[i][1] : out[j][1]);
          /* erase */;
          changed = 1;
          break;
        }
      }
      if (changed) break;
    }
  }
  /* sort out by start */;
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three buckets, one scan. No sort needed because the input is already sorted.
// How it works: before holds intervals fully to the left. after holds fully to the right. The middle ones stretch start/end of the new interval. Concatenate before + merged + after.

/* pass n for array length; simple loops */
int insertInterval(int intervals[][2], int n, int ns, int ne, int out[][2]) {
  int before[1024]; int before_n = 0;
  int after[1024]; int after_n = 0;
  int start = newInterval[0];
  int end = newInterval[1];
  for (int i = 0; i < n; i++) {
    int cur = intervals[i];
    if (cur[1] < start) /* push */([cur[0], cur[1]]);
    else if (cur[0] > end) /* push */([cur[0], cur[1]]);
    else {
      start = (start < cur[0] ? start : cur[0]);
      end = (end > cur[1] ? end : cur[1]);
    }
  }
  return before;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass, one result list, no extra before/after arrays (the result plays that role).
// How it works: copy intervals that end before the new start. Merge while the next interval starts at or before the new end. Then copy the tail.

/* pass n for array length; simple loops */
int insertInterval(int intervals[][2], int n, int ns, int ne, int out[][2]) {
  int out[1024]; int out_n = 0;
  /* n is the given length */
  int i = 0;
  int start = newInterval[0];
  int end = newInterval[1];
  while (i < n && intervals[i][1] < start) {
    /* push */([intervals[i][0], intervals[i][1]]);
    i++;
  }
  while (i < n && intervals[i][0] <= end) {
    start = (start < intervals[i][0] ? start : intervals[i][0]);
    end = (end > intervals[i][1] ? end : intervals[i][1]);
    i++;
  }
  /* push */([start, end]);
  while (i < n) {
    /* push */([intervals[i][0], intervals[i][1]]);
    i++;
  }
  return out;
}
