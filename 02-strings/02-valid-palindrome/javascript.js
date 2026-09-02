// Method 1: Brute
// Time: O(n) | Space: O(n)
// Linear scan, but a full cleaned copy plus a reversed copy.
// How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

function isPalindrome(s) {
  let cleaned = "";
  for (let i = 0; i < s.length; i++) {
    const ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) cleaned += ch;
  }
  const reversed = cleaned.split("").reverse().join("");
  return cleaned === reversed;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Still a cleaned array, but comparison is two pointers instead of building a reversed string.
// How it works: push kept characters into chars, then left/right must match.

function isPalindrome(s) {
  const chars = [];
  for (let i = 0; i < s.length; i++) {
    const ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) chars.push(ch);
  }
  let left = 0;
  let right = chars.length - 1;
  while (left < right) {
    if (chars[left] !== chars[right]) return false;
    left++;
    right--;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// No extra string of length n. Two indexes on the original text.
// How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

function isPalindrome(s) {
  function ok(ch) {
    const c = ch.toLowerCase();
    return (c >= "a" && c <= "z") || (c >= "0" && c <= "9");
  }
  let left = 0;
  let right = s.length - 1;
  while (left < right) {
    while (left < right && !ok(s[left])) left++;
    while (left < right && !ok(s[right])) right--;
    if (s[left].toLowerCase() !== s[right].toLowerCase()) return false;
    left++;
    right--;
  }
  return true;
}
