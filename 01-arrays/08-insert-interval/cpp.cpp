// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Add the new interval, then reuse the quadratic merge-until-stable idea.
// How it works: push a copy of newInterval onto a copied list, then glue overlaps with nested scans until the list is stable.

// vector, unordered_map, string
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<int> out;
  for (int i = 0; i < (int)intervals.size(); i++) {
    out.push_back([intervals[i][0], intervals[i][1]]);
  }
  out.push_back([newInterval[0], newInterval[1]]);
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < (int)out.size(); i++) {
      for (int j = i + 1; j < (int)out.size(); j++) {
        if (out[i][0] <= out[j][1] && out[j][0] <= out[i][1]) {
          out[i][0] = min(out[i][0], out[j][0]);
          out[i][1] = max(out[i][1], out[j][1]);
          out.erase(out.begin()+(j));
          changed = true;
          break;
        }
      }
      if (changed) break;
    }
  }
  sort(out.begin(), out.end());
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three buckets, one scan. No sort needed because the input is already sorted.
// How it works: before holds intervals fully to the left. after holds fully to the right. The middle ones stretch start/end of the new interval. Concatenate before + merged + after.

// vector, unordered_map, string
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<int> before;
  vector<int> after;
  int start = newInterval[0];
  int end = newInterval[1];
  for (int i = 0; i < (int)intervals.size(); i++) {
    vector<int> cur = intervals[i];
    if (cur[1] < start) before.push_back([cur[0], cur[1]]);
    else if (cur[0] > end) after.push_back([cur[0], cur[1]]);
    else {
      start = min(start, cur[0]);
      end = max(end, cur[1]);
    }
  }
  return before;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass, one result list, no extra before/after arrays (the result plays that role).
// How it works: copy intervals that end before the new start. Merge while the next interval starts at or before the new end. Then copy the tail.

// vector, unordered_map, string
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<int> out;
  int n = (int)intervals.size();
  int i = 0;
  int start = newInterval[0];
  int end = newInterval[1];
  while (i < n && intervals[i][1] < start) {
    out.push_back([intervals[i][0], intervals[i][1]]);
    i++;
  }
  while (i < n && intervals[i][0] <= end) {
    start = min(start, intervals[i][0]);
    end = max(end, intervals[i][1]);
    i++;
  }
  out.push_back([start, end]);
  while (i < n) {
    out.push_back([intervals[i][0], intervals[i][1]]);
    i++;
  }
  return out;
}
