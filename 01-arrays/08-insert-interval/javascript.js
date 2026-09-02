// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Add the new interval, then reuse the quadratic merge-until-stable idea.
// How it works: push a copy of newInterval onto a copied list, then glue overlaps with nested scans until the list is stable.

function insert(intervals, newInterval) {
  const out = [];
  for (let i = 0; i < intervals.length; i++) {
    out.push([intervals[i][0], intervals[i][1]]);
  }
  out.push([newInterval[0], newInterval[1]]);
  let changed = true;
  while (changed) {
    changed = false;
    for (let i = 0; i < out.length; i++) {
      for (let j = i + 1; j < out.length; j++) {
        if (out[i][0] <= out[j][1] && out[j][0] <= out[i][1]) {
          out[i][0] = Math.min(out[i][0], out[j][0]);
          out[i][1] = Math.max(out[i][1], out[j][1]);
          out.splice(j, 1);
          changed = true;
          break;
        }
      }
      if (changed) break;
    }
  }
  out.sort(function (a, b) { return a[0] - b[0]; });
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three buckets, one scan. No sort needed because the input is already sorted.
// How it works: before holds intervals fully to the left. after holds fully to the right. The middle ones stretch start/end of the new interval. Concatenate before + merged + after.

function insert(intervals, newInterval) {
  const before = [];
  const after = [];
  let start = newInterval[0];
  let end = newInterval[1];
  for (let i = 0; i < intervals.length; i++) {
    const cur = intervals[i];
    if (cur[1] < start) before.push([cur[0], cur[1]]);
    else if (cur[0] > end) after.push([cur[0], cur[1]]);
    else {
      start = Math.min(start, cur[0]);
      end = Math.max(end, cur[1]);
    }
  }
  return before.concat([[start, end]], after);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass, one result list, no extra before/after arrays (the result plays that role).
// How it works: copy intervals that end before the new start. Merge while the next interval starts at or before the new end. Then copy the tail.

function insert(intervals, newInterval) {
  const out = [];
  const n = intervals.length;
  let i = 0;
  let start = newInterval[0];
  let end = newInterval[1];
  while (i < n && intervals[i][1] < start) {
    out.push([intervals[i][0], intervals[i][1]]);
    i++;
  }
  while (i < n && intervals[i][0] <= end) {
    start = Math.min(start, intervals[i][0]);
    end = Math.max(end, intervals[i][1]);
    i++;
  }
  out.push([start, end]);
  while (i < n) {
    out.push([intervals[i][0], intervals[i][1]]);
    i++;
  }
  return out;
}
