// Method 1: Brute
// Time: O(n² · k) | Space: O(k)
// Every i..j window rebuilds counts against t. k is the alphabet / unique letters in t.
// How it works: covers() copies t’s need map and decrements for each character of the slice. Keep the shortest slice that covers.

class Solution {
  public String minWindow(String s, String t) {
    public void covers(slice) {
      Map<Character, Integer> need = new HashMap<>();
      for (int i = 0; i < t.length(); i++) {
        need.put(t.charAt(i), (need.getOrDefault(t.charAt(i), 0)) + 1);
      }
      for (int i = 0; i < slice.length(); i++) {
        char ch = slice.charAt(i);
        if (need.containsKey(ch)) {
          need.put(ch, need.get(ch) - 1);
          if (need.get(ch) == 0) need.remove(ch);
        }
      }
      return need.size() == 0;
    }
    String best = "";
    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j < s.length(); j++) {
        String slice = s.substring(i, j + 1);
        if (covers(slice) && (best == "" || slice.length() < best.length())) best = slice;
      }
    }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(k)
// From each left, grow right until t is covered, then record and try the next left. Still quadratic starts.
// How it works: missing starts as t.length. A need map counts t. As right adds characters, missing drops. First time missing hits 0, that window is a candidate.

class Solution {
  public String minWindow(String s, String t) {
    if (t.length() > s.length()) return "";
    String best = "";
    for (int left = 0; left < s.length(); left++) {
      Map<Character, Integer> need = new HashMap<>();
      for (int i = 0; i < t.length(); i++) need.put(t.charAt(i), (need.getOrDefault(t.charAt(i), 0)) + 1);
      int missing = t.length();
      for (int right = left; right < s.length(); right++) {
        char ch = s.charAt(right);
        if (need.containsKey(ch) && need.get(ch) > 0) missing--;
        if (need.containsKey(ch)) need.put(ch, need.get(ch) - 1);
        if (missing == 0) {
          String slice = s.substring(left, right + 1);
          if (best == "" || slice.length() < best.length()) best = slice;
          break;
        }
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// right walks n times, left walks n times. formed tracks how many unique t-characters are satisfied.
// How it works: grow right, update have. While the window is complete, record if smaller, drop s[left], move left. needCount is the number of unique keys in t.

class Solution {
  public String minWindow(String s, String t) {
    if (t.length() > s.length()) return "";
    Map<Character, Integer> need = new HashMap<>();
    for (int i = 0; i < t.length(); i++) need.put(t.charAt(i), (need.getOrDefault(t.charAt(i), 0)) + 1);
    Map<Character, Integer> have = new HashMap<>();
    int formed = 0;
    int needCount = need.size();
    int bestL = 0;
    int bestR = -1;
    int left = 0;
    for (int right = 0; right < s.length(); right++) {
      char ch = s.charAt(right);
      have.put(ch, (have.getOrDefault(ch, 0)) + 1);
      if (need.containsKey(ch) && have.get(ch) == need.get(ch)) formed++;
      while (formed == needCount) {
        if (bestR == -1 || right - left < bestR - bestL) {
          bestL = left;
          bestR = right;
        }
        char drop = s.charAt(left);
        have.put(drop, have.get(drop) - 1);
        if (need.containsKey(drop) && have.get(drop) < need.get(drop)) formed--;
        left++;
      }
    }
    return bestR == -1 ? "" : s.substring(bestL, bestR + 1);
  }
}
