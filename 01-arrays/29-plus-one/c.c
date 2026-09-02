// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

/* convert to a decimal string, add 1 by hand from the right */


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

int plusOne(int* digits, int n, int* out) {
  int i, carry = 1;
  for (i = 0; i < n; i++) out[i + 1] = digits[i];
  for (i = n; i >= 1 && carry; i--) {
    int s = out[i] + carry;
    out[i] = s % 10;
    carry = s / 10;
  }
  if (carry) { out[0] = 1; return n + 1; }
  for (i = 0; i < n; i++) out[i] = out[i + 1];
  return n;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra if no new digit
// Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

int plusOneInPlace(int* digits, int n, int* out) {
  int i;
  for (i = n - 1; i >= 0; i--) {
    if (digits[i] < 9) { digits[i]++; for (i = 0; i < n; i++) out[i] = digits[i]; return n; }
    digits[i] = 0;
  }
  out[0] = 1;
  for (i = 0; i < n; i++) out[i + 1] = 0;
  return n + 1;
}
