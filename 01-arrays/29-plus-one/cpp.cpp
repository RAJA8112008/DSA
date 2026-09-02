// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

vector<int> plusOne(vector<int>& digits) {
  /* treat as base-10 array instead of a native big int */
  vector<int> out = digits;
  int i = (int)out.size() - 1, carry = 1;
  while (i >= 0 && carry) {
    int s = out[i] + carry;
    out[i] = s % 10;
    carry = s / 10;
    i--;
  }
  if (carry) out.insert(out.begin(), 1);
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

vector<int> plusOne(vector<int>& digits) {
  vector<int> out = digits;
  int carry = 1;
  for (int i = (int)out.size() - 1; i >= 0 && carry; i--) {
    int s = out[i] + carry;
    out[i] = s % 10;
    carry = s / 10;
  }
  if (carry) out.insert(out.begin(), 1);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra if no new digit
// Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

vector<int> plusOne(vector<int>& digits) {
  for (int i = (int)digits.size() - 1; i >= 0; i--) {
    if (digits[i] < 9) { digits[i]++; return digits; }
    digits[i] = 0;
  }
  vector<int> out((int)digits.size() + 1);
  out[0] = 1;
  return out;
}
