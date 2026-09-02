// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

import java.math.BigInteger;
class Solution {
  public int[] plusOne(int[] digits) {
    StringBuilder sb = new StringBuilder();
    for (int d : digits) sb.append(d);
    BigInteger n = new BigInteger(sb.toString()).add(BigInteger.ONE);
    String t = n.toString();
    int[] out = new int[t.length()];
    for (int i = 0; i < t.length(); i++) out[i] = t.charAt(i) - '0';
    return out;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

class Solution {
  public int[] plusOne(int[] digits) {
    int n = digits.length;
    int[] out = digits.clone();
    int carry = 1;
    for (int i = n - 1; i >= 0 && carry == 1; i--) {
      int s = out[i] + carry;
      out[i] = s % 10;
      carry = s / 10;
    }
    if (carry == 0) return out;
    int[] big = new int[n + 1];
    big[0] = 1;
    for (int i = 0; i < n; i++) big[i + 1] = out[i];
    return big;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra if no new digit
// Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

class Solution {
  public int[] plusOne(int[] digits) {
    for (int i = digits.length - 1; i >= 0; i--) {
      if (digits[i] < 9) { digits[i]++; return digits; }
      digits[i] = 0;
    }
    int[] out = new int[digits.length + 1];
    out[0] = 1;
    return out;
  }
}
