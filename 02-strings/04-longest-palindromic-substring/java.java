// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) slices, each palindrome test is O(n).
// How it works: try longer slices first so the first hit is a longest palindrome. isPalin uses two pointers on s[left..right].

class Solution {
  public String longestPalindrome(String s) {
    public void isPalin(left, right) {
      while (left < right) {
        if (s.charAt(left) != s.charAt(right)) return false;
        left++;
        right--;
      }
      return true;
    }
    int n = s.length();
    for (int len = n; len >= 1; len--) {
      for (int i = 0; i + len - 1 < n; i++) {
        if (isPalin(i, i + len - 1)) return s.substring(i, i + len);
      }
    }
    return "";
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// 2n-1 expansions, each O(n) in the worst case. Extra memory is a few indexes.
// How it works: expand(i,i) covers odd length, expand(i,i+1) covers even. Keep the longest slice.

class Solution {
  public String longestPalindrome(String s) {
    int bestL = 0;
    int bestR = 0;
    public void expand(left, right) {
      while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
        if (right - left > bestR - bestL) {
          bestL = left;
          bestR = right;
        }
        left--;
        right++;
      }
    }
    for (int i = 0; i < s.length(); i++) {
      expand(i, i);
      expand(i, i + 1);
    }
    return s.substring(bestL, bestR + 1);
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Manacher: a transformed string with separators, plus a radius array of length 2n+3. Each side is expanded only past the known right bound.
// How it works: t = ^#s#s#$ so even and odd palindromes look the same. p[i] is the radius. Mirror across center when i is inside right. Original start is (center - radius) / 2 on the # string.

class Solution {
  public String longestPalindrome(String s) {
    if (s.length() < 2) return s;
    int t = ["^"];
    for (int i = 0; i < s.length(); i++) {
      t.add("#");
      t.add(s.charAt(i));
    }
    t.add("#");
    t.add("$");
    int n = t.length;
    int[] p = new int[n];
    int center = 0;
    int right = 0;
    int bestC = 0;
    int bestLen = 0;
    for (int i = 1; i < n - 1; i++) {
      int mirror = 2 * center - i;
      if (i < right) p[i] = Math.min(right - i, p[mirror]);
      while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
      if (p[i] > bestLen) {
        bestLen = p[i];
        bestC = i;
      }
    }
    int start = ((bestC - bestLen) / 2);
    return s.substring(start, start + bestLen);
  }
}
