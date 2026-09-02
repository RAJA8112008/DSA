// Method 1: Brute
// Time: O(n) | Space: O(n)
// Linear scan, but a full cleaned copy plus a reversed copy.
// How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

class Solution {
  public boolean isPalindrome(String s) {
    String cleaned = "";
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i).toLowerCase();
      if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) cleaned += ch;
    }
    int reversed = cleaned.split("").reverse().join("");
    return cleaned == reversed;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Still a cleaned array, but comparison is two pointers instead of building a reversed string.
// How it works: push kept characters into chars, then left/right must match.

class Solution {
  public boolean isPalindrome(String s) {
    List<Integer> chars = new ArrayList<>();
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i).toLowerCase();
      if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) chars.add(ch);
    }
    int left = 0;
    int right = chars.size() - 1;
    while (left < right) {
      if (chars[left] != chars[right]) return false;
      left++;
      right--;
    }
    return true;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// No extra string of length n. Two indexes on the original text.
// How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

class Solution {
  public boolean isPalindrome(String s) {
    public void ok(ch) {
      int c = Character.toLowerCase(ch);
      return (c >= "a" && c <= "z") || (c >= "0" && c <= "9");
    }
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
      while (left < right && !ok(s.charAt(left))) left++;
      while (left < right && !ok(s.charAt(right))) right--;
      if (s.charAt(left).toLowerCase() != s.charAt(right).toLowerCase()) return false;
      left++;
      right--;
    }
    return true;
  }
}
