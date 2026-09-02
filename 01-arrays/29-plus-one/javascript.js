// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

function plusOne(digits) {
  let s = "";
  for (let i = 0; i < digits.length; i++) s += String(digits[i]);
  const t = String(BigInt(s) + 1n);
  const out = [];
  for (let i = 0; i < t.length; i++) out.push(t.charCodeAt(i) - 48);
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

function plusOne(digits) {
  const out = digits.slice();
  let carry = 1;
  for (let i = out.length - 1; i >= 0 && carry; i--) {
    const s = out[i] + carry;
    out[i] = s % 10;
    carry = (s / 10) | 0;
  }
  if (carry) out.unshift(1);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra if no new digit
// Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

function plusOne(digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i]++;
      return digits;
    }
    digits[i] = 0;
  }
  const out = Array(digits.length + 1).fill(0);
  out[0] = 1;
  return out;
}
