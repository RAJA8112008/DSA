// Method 1: Brute
// Time: O(n³) | Space: O(n)
// O(n²) substrings, and each uniqueness check can scan the slice again.
// How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

// vector, unordered_map, string
int lengthOfLongestSubstring(string s) {
  int n = (int)s.size();
  int best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      unordered_set<int> seen;
      bool unique = true;
      for (int k = i; k <= j; k++) {
        if (seen.count(s[k])) { unique = false; break; }
        seen.insert(s[k]);
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

// vector, unordered_map, string
int lengthOfLongestSubstring(string s) {
  int best = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    unordered_set<int> seen;
    for (int j = i; j < n; j++) {
      if (seen.count(s[j])) break;
      seen.insert(s[j]);
      if (j - i + 1 > best) best = j - i + 1;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each index is a right endpoint once. left only moves forward. Map stores last indexes.
// How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

// vector, unordered_map, string
int lengthOfLongestSubstring(string s) {
  unordered_map<int,int> last;
  int left = 0;
  int best = 0;
  for (int right = 0; right < (int)s.size(); right++) {
    char ch = s[right];
    if (last.count(ch) && last[ch] >= left) left = last[ch] + 1;
    last[ch] = right;
    int len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}
