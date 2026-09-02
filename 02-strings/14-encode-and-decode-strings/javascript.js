// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
// How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

function encode(strs) {
  return JSON.stringify(strs);
}
function decode(s) {
  return JSON.parse(s);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
// How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

function encode(strs) {
  let header = String(strs.length);
  for (let i = 0; i < strs.length; i++) {
    header += "," + String(strs[i].length);
  }
  let body = "";
  for (let i = 0; i < strs.length; i++) body += strs[i];
  return header + "#" + body;
}
function decode(s) {
  const hash = s.indexOf("#");
  const parts = s.slice(0, hash).split(",");
  const n = Number(parts[0]);
  const out = [];
  let pos = hash + 1;
  for (let i = 0; i < n; i++) {
    const len = Number(parts[i + 1]);
    out.push(s.slice(pos, pos + len));
    pos += len;
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
// How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

function encode(strs) {
  let out = "";
  for (let i = 0; i < strs.length; i++) {
    out += String(strs[i].length) + "#" + strs[i];
  }
  return out;
}
function decode(s) {
  const out = [];
  let i = 0;
  while (i < s.length) {
    let j = i;
    while (s[j] !== "#") j++;
    const len = Number(s.slice(i, j));
    const word = s.slice(j + 1, j + 1 + len);
    out.push(word);
    i = j + 1 + len;
  }
  return out;
}
