// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each merge pass can scan all remaining pairs. Several passes still stay quadratic for typical n.
// How it works: copy intervals. While any two overlap, replace them with their union and restart the pair scan.

// vector, unordered_map, string
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<int> out;
  for (int i = 0; i < (int)intervals.size(); i++) {
    out.push_back([intervals[i][0], intervals[i][1]]);
  }
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < (int)out.size(); i++) {
      for (int j = i + 1; j < (int)out.size(); j++) {
        int a = out[i];
        int b = out[j];
        if (a[0] <= b[1] && b[0] <= a[1]) {
          a[0] = min(a[0], b[0]);
          a[1] = max(a[1], b[1]);
          out.erase(out.begin()+(j));
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

// vector, unordered_map, string
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  if ((int)intervals.size() == 0) return {};
  int list = intervals /* copy pairs */;
  sort(list.begin(), list.end());
  int merged = [list[0]];
  for (int i = 1; i < (int)list.size(); i++) {
    int last = merged[(int)merged.size() - 1];
    if (list[i][0] <= last[1]) {
      last[1] = max(last[1], list[i][1]);
    } else {
      merged.push_back(list[i]);
    }
  }
  return merged;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same O(n log n) bound: you must sort unless the input is already ordered. This version sorts a copy once and writes merged ranges without extra pass flags.
// How it works: identical merge walk, with an early return for an empty list and copies so caller intervals stay untouched.

// vector, unordered_map, string
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  int n = (int)intervals.size();
  if (n == 0) return {};
  vector<int> list = vector<int>(n);
  for (int i = 0; i < n; i++) list[i] = [intervals[i][0], intervals[i][1]];
  sort(list.begin(), list.end());
  vector<int> merged;
  int start = list[0][0];
  int end = list[0][1];
  for (int i = 1; i < n; i++) {
    if (list[i][0] <= end) {
      if (list[i][1] > end) end = list[i][1];
    } else {
      merged.push_back([start, end]);
      start = list[i][0];
      end = list[i][1];
    }
  }
  merged.push_back([start, end]);
  return merged;
}
