// Method 1: Brute
// Time: O(S) | Space: O(m)
// S is the total number of characters. Each word is compared to the current prefix from scratch.
// How it works: prefix starts as strs[0]. For each next word, cut prefix while it is not a prefix of that word.

function longestCommonPrefix(strs) {
  if (!strs.length) return "";
  let prefix = strs[0];
  for (let i = 1; i < strs.length; i++) {
    while (strs[i].indexOf(prefix) !== 0) {
      prefix = prefix.slice(0, prefix.length - 1);
      if (prefix === "") return "";
    }
  }
  return prefix;
}


// Method 2: Optimal
// Time: O(n log n + m) | Space: O(m)
// Sort the n words, then only the first and last can disagree. m is the shorter of those two.
// How it works: after sort, walk columns of first vs last until they differ. That slice is the prefix of the whole set.

function longestCommonPrefix(strs) {
  if (!strs.length) return "";
  const list = strs.slice().sort();
  const first = list[0];
  const last = list[list.length - 1];
  let i = 0;
  while (i < first.length && i < last.length && first[i] === last[i]) i++;
  return first.slice(0, i);
}


// Method 3: More optimal
// Time: O(S) | Space: O(1)
// No sort copy. Extra memory is a few indexes. Worst case still reads every character of every word until a mismatch.
// How it works: for column i of strs[0], every other word must have the same character. Return the slice before the first failure.

function longestCommonPrefix(strs) {
  if (!strs.length) return "";
  const first = strs[0];
  for (let i = 0; i < first.length; i++) {
    const ch = first[i];
    for (let j = 1; j < strs.length; j++) {
      if (i >= strs[j].length || strs[j][i] !== ch) return first.slice(0, i);
    }
  }
  return first;
}
