// Method 1: Brute
// Time: O(n³) | Space: O(n)
// O(n²) substrings, and each uniqueness check can scan the slice again.
// How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

class Solution {
  public int lengthOfLongestSubstring(String s) {
    int n = s.length();
    int best = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        Set<Integer> seen = new HashSet<>();
        boolean unique = true;
        for (int k = i; k <= j; k++) {
          if (seen.contains(s.charAt(k))) { unique = false; break; }
          seen.add(s.charAt(k));
        }
        if (unique && j - i + 1 > best) best = j - i + 1;
      }
    }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// From each start, grow right until a repeat. Inner work is O(n), times n starts.
// How it works: seen is a Set for the current window. On a repeat, break and try the next start.

class Solution {
  public int lengthOfLongestSubstring(String s) {
    int best = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
      Set<Integer> seen = new HashSet<>();
      for (int j = i; j < n; j++) {
        if (seen.contains(s.charAt(j))) break;
        seen.add(s.charAt(j));
        if (j - i + 1 > best) best = j - i + 1;
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each index is a right endpoint once. left only moves forward. Map stores last indexes.
// How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

class Solution {
  public int lengthOfLongestSubstring(String s) {
    Map<Character, Integer> last = new HashMap<>();
    int left = 0;
    int best = 0;
    for (int right = 0; right < s.length(); right++) {
      char ch = s.charAt(right);
      if (last.containsKey(ch) && last.get(ch) >= left) left = last.get(ch) + 1;
      last.put(ch, right);
      int len = right - left + 1;
      if (len > best) best = len;
    }
    return best;
  }
}
