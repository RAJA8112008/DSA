// Method 1: Brute
// Time: O(n² · 26) | Space: O(1)
// Every window rebuilds 26 counts and checks whether length - maxCount <= k.
// How it works: if the letters that are not the most common letter fit in k replacements, the window is valid. Keep the max valid length.

// vector, unordered_map, string
int characterReplacement(string s, int k) {
  int best = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    vector<int> count = vector<int>(26, 0);
    int maxCount = 0;
    for (int j = i; j < n; j++) {
      int idx = (int)s[j] - 65;
      count[idx]++;
      if (count[idx] > maxCount) maxCount = count[idx];
      int len = j - i + 1;
      if (len - maxCount <= k && len > best) best = len;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n · 26) | Space: O(1)
// One window. When invalid, left moves and you recompute maxCount by scanning 26 slots.
// How it works: grow right. While length - maxCount > k, decrement s[left] and recount maxCount. Then update best.

// vector, unordered_map, string
int characterReplacement(string s, int k) {
  vector<int> count = vector<int>(26, 0);
  int left = 0;
  int best = 0;
  for (int right = 0; right < (int)s.size(); right++) {
    count[(int)s[right] - 65]++;
    auto maxInCount = [&]() {
      int m = 0;
      for (int i = 0; i < 26; i++) if (count[i] > m) m = count[i];
      return m;
    }
    while (right - left + 1 - maxInCount() > k) {
      count[(int)s[left] - 65]--;
      left++;
    }
    int len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// maxCount only increases when a better majority appears. For the longest window, you never need a smaller maxCount.
// How it works: grow right, update maxCount. If window is too dirty, move left once (not a while with a rescan). Window size still only grows when valid history allows it.

// vector, unordered_map, string
int characterReplacement(string s, int k) {
  vector<int> count = vector<int>(26, 0);
  int left = 0;
  int maxCount = 0;
  int best = 0;
  for (int right = 0; right < (int)s.size(); right++) {
    int idx = (int)s[right] - 65;
    count[idx]++;
    if (count[idx] > maxCount) maxCount = count[idx];
    if (right - left + 1 - maxCount > k) {
      count[(int)s[left] - 65]--;
      left++;
    }
    int len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}
