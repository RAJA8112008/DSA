// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Count with nested scans: for each character type, walk the whole string. Slow counting, same final formula.
// How it works: collect unique letters. For each letter, count occurrences with a full scan. Add even parts; remember if any odd exists; add 1 for a center.

function longestPalindrome(s) {
  const letters = [];
  for (let i = 0; i < s.length; i++) {
    if (letters.indexOf(s[i]) === -1) letters.push(s[i]);
  }
  let len = 0;
  let odd = false;
  for (let L = 0; L < letters.length; L++) {
    let c = 0;
    for (let i = 0; i < s.length; i++) if (s[i] === letters[L]) c++;
    len += c - (c % 2);
    if (c % 2 === 1) odd = true;
  }
  return odd ? len + 1 : len;
}


// Method 2: Optimal
// Time: O(n) | Space: O(k)
// One pass to count, one pass over unique keys. k is the alphabet size.
// How it works: object/map frequencies. Even contribution is count - count%2. One leftover odd becomes the center.

function longestPalindrome(s) {
  const count = {};
  for (let i = 0; i < s.length; i++) {
    const ch = s[i];
    count[ch] = (count[ch] || 0) + 1;
  }
  let len = 0;
  let odd = false;
  for (const ch in count) {
    len += count[ch] - (count[ch] % 2);
    if (count[ch] % 2 === 1) odd = true;
  }
  return odd ? len + 1 : len;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// 128 slots cover ASCII letters used in the usual prompt. Extra memory is constant.
// How it works: count[charCode]++. Same even/odd rule on the 128 numbers. Equivalent: len += count[i] & ~1, then if len < s.length add 1.

function longestPalindrome(s) {
  const count = new Array(128).fill(0);
  for (let i = 0; i < s.length; i++) count[s.charCodeAt(i)]++;
  let len = 0;
  for (let i = 0; i < 128; i++) len += count[i] - (count[i] % 2);
  if (len < s.length) len += 1;
  return len;
}
