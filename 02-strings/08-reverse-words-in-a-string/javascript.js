// Method 1: Brute
// Time: O(n) | Space: O(n)
// Library split/filter/reverse/join still copies the string.
// How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

function reverseWords(s) {
  const words = s.split(" ").filter(function (w) { return w.length > 0; });
  words.reverse();
  return words.join(" ");
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
// How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

function reverseWords(s) {
  const words = [];
  let i = 0;
  while (i < s.length) {
    while (i < s.length && s[i] === " ") i++;
    if (i >= s.length) break;
    let j = i;
    while (j < s.length && s[j] !== " ") j++;
    words.push(s.slice(i, j));
    i = j;
  }
  let out = "";
  for (let k = words.length - 1; k >= 0; k--) {
    if (out.length) out += " ";
    out += words[k];
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
// How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

function reverseWords(s) {
  function reverse(arr, left, right) {
    while (left < right) {
      const t = arr[left];
      arr[left] = arr[right];
      arr[right] = t;
      left++;
      right--;
    }
  }
  const chars = [];
  for (let i = 0; i < s.length; i++) {
    if (s[i] === " " && (chars.length === 0 || chars[chars.length - 1] === " ")) continue;
    chars.push(s[i]);
  }
  while (chars.length && chars[chars.length - 1] === " ") chars.pop();
  reverse(chars, 0, chars.length - 1);
  let start = 0;
  for (let i = 0; i <= chars.length; i++) {
    if (i === chars.length || chars[i] === " ") {
      reverse(chars, start, i - 1);
      start = i + 1;
    }
  }
  return chars.join("");
}
