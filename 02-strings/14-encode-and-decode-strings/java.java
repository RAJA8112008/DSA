// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
// How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

class Solution {
  public String encode(String[] strs) {
    return /* json */ strs.toString();
  }
  public List<String> decode(String s) {
    return /* json parse */ s;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
// How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

class Solution {
  public String encode(String[] strs) {
    int header = String.valueOf(strs.length);
    for (int i = 0; i < strs.length; i++) {
      header += "," + String.valueOf(strs[i].length);
    }
    String body = "";
    for (int i = 0; i < strs.length; i++) body += strs[i];
    return header + "#" + body;
  }
  public List<String> decode(String s) {
    int hash = s.indexOf("#");
    String parts = s.substring(0, hash).split(",");
    int n = Integer.parseInt(parts.charAt(0));
    List<Integer> out = new ArrayList<>();
    int pos = hash + 1;
    for (int i = 0; i < n; i++) {
      int len = Integer.parseInt(parts.charAt(i + 1));
      out.add(s.substring(pos, pos + len));
      pos += len;
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
// How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

class Solution {
  public String encode(String[] strs) {
    String out = "";
    for (int i = 0; i < strs.length; i++) {
      out += String.valueOf(strs[i].length) + "#" + strs[i];
    }
    return out;
  }
  public List<String> decode(String s) {
    List<Integer> out = new ArrayList<>();
    int i = 0;
    while (i < s.length()) {
      int j = i;
      while (s.charAt(j) != "#") j++;
      String len = Integer.parseInt(s.substring(i, j));
      String word = s.substring(j + 1, j + 1 + len);
      out.add(word);
      i = j + 1 + len;
    }
    return out;
  }
}
