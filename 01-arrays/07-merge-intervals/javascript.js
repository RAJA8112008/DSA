// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each merge pass can scan all remaining pairs. Several passes still stay quadratic for typical n.
// How it works: copy intervals. While any two overlap, replace them with their union and restart the pair scan.

function merge(intervals) {
  const out = [];
  for (let i = 0; i < intervals.length; i++) {
    out.push([intervals[i][0], intervals[i][1]]);
  }
  let changed = true;
  while (changed) {
    changed = false;
    for (let i = 0; i < out.length; i++) {
      for (let j = i + 1; j < out.length; j++) {
        const a = out[i];
        const b = out[j];
        if (a[0] <= b[1] && b[0] <= a[1]) {
          a[0] = Math.min(a[0], b[0]);
          a[1] = Math.max(a[1], b[1]);
          out.splice(j, 1);
          changed = true;
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

function merge(intervals) {
  if (intervals.length === 0) return [];
  const list = intervals.map(function (p) { return [p[0], p[1]]; });
  list.sort(function (a, b) { return a[0] - b[0]; });
  const merged = [list[0]];
  for (let i = 1; i < list.length; i++) {
    const last = merged[merged.length - 1];
    if (list[i][0] <= last[1]) {
      last[1] = Math.max(last[1], list[i][1]);
    } else {
      merged.push(list[i]);
    }
  }
  return merged;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same O(n log n) bound: you must sort unless the input is already ordered. This version sorts a copy once and writes merged ranges without extra pass flags.
// How it works: identical merge walk, with an early return for an empty list and copies so caller intervals stay untouched.

function merge(intervals) {
  const n = intervals.length;
  if (n === 0) return [];
  const list = new Array(n);
  for (let i = 0; i < n; i++) list[i] = [intervals[i][0], intervals[i][1]];
  list.sort(function (a, b) { return a[0] - b[0]; });
  const merged = [];
  let start = list[0][0];
  let end = list[0][1];
  for (let i = 1; i < n; i++) {
    if (list[i][0] <= end) {
      if (list[i][1] > end) end = list[i][1];
    } else {
      merged.push([start, end]);
      start = list[i][0];
      end = list[i][1];
    }
  }
  merged.push([start, end]);
  return merged;
}
