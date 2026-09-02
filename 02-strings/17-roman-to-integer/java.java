// Method 1: Brute
// Time: O(n) | Space: O(n)
// You copy the string and rewrite pairs, then sum. Extra string memory.
// How it works: replace CM, CD, XC, XL, IX, IV with single tokens, then add a map of remaining symbols including those tokens.

class Solution {
  public int romanToInt(String s) {
    int t = s;
    t = t.split("CM").join("a");
    t = t.split("CD").join("b");
    t = t.split("XC").join("c");
    t = t.split("XL").join("d");
    t = t.split("IX").join("e");
    t = t.split("IV").join("f");
    int val = { M: 1000, D: 500, C: 100, L: 50, X: 10, V: 5, I: 1, a: 900, b: 400, c: 90, d: 40, e: 9, f: 4 };
    int sum = 0;
    for (int i = 0; i < t.length; i++) sum += val[t[i]];
    return sum;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// One pass, a fixed map. When a subtractive pair is seen, add the pair value and skip two characters.
// How it works: if val[s[i]] < val[s[i+1]], add the difference and i += 2. Else add val[s[i]] and i += 1.

class Solution {
  public int romanToInt(String s) {
    int val = { I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000 };
    int sum = 0;
    int i = 0;
    while (i < s.length()) {
      int cur = val[s[i]];
      int next = i + 1 < s.length() ? val[s[i + 1]] : 0;
      if (cur < next) {
        sum += next - cur;
        i += 2;
      } else {
        sum += cur;
        i += 1;
      }
    }
    return sum;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Same linear scan, no skip logic: always add the current value, but subtract it instead when it is smaller than the next.
// How it works: for each i, if val[s[i]] < val[s[i+1]] then sum -= val[s[i]], else sum += val[s[i]].

class Solution {
  public int romanToInt(String s) {
    int val = { I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000 };
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
      int cur = val[s[i]];
      int next = i + 1 < s.length() ? val[s[i + 1]] : 0;
      if (cur < next) sum -= cur;
      else sum += cur;
    }
    return sum;
  }
}
