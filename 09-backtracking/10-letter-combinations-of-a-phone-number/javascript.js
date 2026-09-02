// Method 1: Brute
// Time: O(4^n * n) | Space: O(4^n * n)
// Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

function letterCombinations(digits) {
  if (!digits.length) return [];
  const map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
  const ans = [];
  function go(i, path) {
    if (i === digits.length) { ans.push(path); return; }
    const letters = map[digits.charCodeAt(i) - 48];
    for (let j = 0; j < letters.length; j++) go(i + 1, path + letters[j]);
  }
  go(0, "");
  return ans;
}


// Method 2: Optimal
// Time: O(4^n * n) | Space: O(n)
// One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

function letterCombinations(digits) {
  if (!digits.length) return [];
  const map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
  const ans = [];
  const path = [];
  function go(i) {
    if (i === digits.length) { ans.push(path.join("")); return; }
    const letters = map[digits.charCodeAt(i) - 48];
    for (let j = 0; j < letters.length; j++) {
      path.push(letters[j]);
      go(i + 1);
      path.pop();
    }
  }
  go(0);
  return ans;
}


// Method 3: More optimal
// Time: O(4^n * n) | Space: O(4^n * n)
// Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

function letterCombinations(digits) {
  if (!digits.length) return [];
  const map = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];
  let cur = [""];
  for (let i = 0; i < digits.length; i++) {
    const letters = map[digits.charCodeAt(i) - 48];
    const next = [];
    for (let p = 0; p < cur.length; p++) {
      for (let j = 0; j < letters.length; j++) next.push(cur[p] + letters[j]);
    }
    cur = next;
  }
  return cur;
}
