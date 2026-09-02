// Method 1: Brute
// Time: O(n²) | Space: O(n)
// n candidate strings after deleting one index, each palindrome check is O(n).
// How it works: if s is already a palindrome, true. Else for each i, check s without index i.

class Solution {
  public boolean validPalindrome(String s) {
    public void isPalin(text) {
      int left = 0;
      int right = text.length() - 1;
      while (left < right) {
        if (text.charAt(left) != text.charAt(right)) return false;
        left++;
        right--;
      }
      return true;
    }
    if (isPalin(s)) return true;
    for (int i = 0; i < s.length(); i++) {
      if (isPalin(s.substring(0, i) + s.substring(i + 1))) return true;
    }
    return false;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One mismatch, then two extra strings of length n-1.
// How it works: walk inward. On mismatch, test skip-left and skip-right by slicing. If the whole walk succeeds, no deletion was needed.

class Solution {
  public boolean validPalindrome(String s) {
    public void isPalin(text) {
      int left = 0;
      int right = text.length() - 1;
      while (left < right) {
        if (text.charAt(left) != text.charAt(right)) return false;
        left++;
        right--;
      }
      return true;
    }
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      if (s.charAt(left) != s.charAt(right)) {
        String skipL = s.substring(left + 1, right + 1);
        String skipR = s.substring(left, right);
        return isPalin(skipL) || isPalin(skipR);
      }
      left++;
      right--;
    }
    return true;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Range checks use indexes only. No sliced copies.
// How it works: palin(l,r) checks a range. On the first mismatch, return palin(left+1, right) or palin(left, right-1).

class Solution {
  public boolean validPalindrome(String s) {
    public void palin(left, right) {
      while (left < right) {
        if (s.charAt(left) != s.charAt(right)) return false;
        left++;
        right--;
      }
      return true;
    }
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      if (s.charAt(left) != s.charAt(right)) {
        return palin(left + 1, right) || palin(left, right - 1);
      }
      left++;
      right--;
    }
    return true;
  }
}
