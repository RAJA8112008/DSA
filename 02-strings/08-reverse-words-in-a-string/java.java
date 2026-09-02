// Method 1: Brute
// Time: O(n) | Space: O(n)
// Library split/filter/reverse/join still copies the string.
// How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

class Solution {
  public String reverseWords(String s) {
    int words = s.split(" ").__FILTERNZ();
    words.reverse();
    return String.join(" ", words);
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
// How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

class Solution {
  public String reverseWords(String s) {
    List<Integer> words = new ArrayList<>();
    int i = 0;
    while (i < s.length()) {
      while (i < s.length() && s.charAt(i) == " ") i++;
      if (i >= s.length()) break;
      int j = i;
      while (j < s.length() && s.charAt(j) != " ") j++;
      words.add(s.substring(i, j));
      i = j;
    }
    String out = "";
    for (int k = words.size() - 1; k >= 0; k--) {
      if (out.length()) out += " ";
      out += words[k];
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
// How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

class Solution {
  public String reverseWords(String s) {
    public void reverse(arr, left, right) {
      while (left < right) {
        int t = arr[left];
        arr[left] = arr[right];
        arr[right] = t;
        left++;
        right--;
      }
    }
    List<Integer> chars = new ArrayList<>();
    for (int i = 0; i < s.length(); i++) {
      if (s.charAt(i) == " " && (chars.size() == 0 || chars[chars.size() - 1] == " ")) continue;
      chars.add(s.charAt(i));
    }
    while (chars.size() && chars[chars.size() - 1] == " ") chars.remove(chars.size()() - 1);
    reverse(chars, 0, chars.size() - 1);
    int start = 0;
    for (int i = 0; i <= chars.size(); i++) {
      if (i == chars.size() || chars[i] == " ") {
        reverse(chars, start, i - 1);
        start = i + 1;
      }
    }
    return String.join("", chars);
  }
}
