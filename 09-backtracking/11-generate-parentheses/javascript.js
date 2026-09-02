// Method 1: Brute
// Time: O(n * 2^{2n}) | Space: O(n * 2^{2n})
// Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

function generateParenthesis(n) {
  const ans = [];
  const total = 1 << (2 * n);
  for (let mask = 0; mask < total; mask++) {
    let s = "";
    for (let b = 0; b < 2 * n; b++) s += (mask & (1 << b)) ? "(" : ")";
    let bal = 0, ok = 1;
    for (let i = 0; i < s.length; i++) {
      bal += s[i] === "(" ? 1 : -1;
      if (bal < 0) { ok = 0; break; }
    }
    if (ok && bal === 0) ans.push(s);
  }
  return ans;
}


// Method 2: Optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

function generateParenthesis(n) {
  const ans = [];
  function valid(s) {
    let bal = 0;
    for (let i = 0; i < s.length; i++) {
      bal += s[i] === "(" ? 1 : -1;
      if (bal < 0) return false;
    }
    return bal === 0;
  }
  function go(path) {
    if (path.length === 2 * n) {
      const s = path.join("");
      if (valid(s)) ans.push(s);
      return;
    }
    path.push("("); go(path); path.pop();
    path.push(")"); go(path); path.pop();
  }
  go([]);
  return ans;
}


// Method 3: More optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

function generateParenthesis(n) {
  const ans = [];
  function go(open, close, path) {
    if (path.length === 2 * n) { ans.push(path.join("")); return; }
    if (open < n) { path.push("("); go(open + 1, close, path); path.pop(); }
    if (close < open) { path.push(")"); go(open, close + 1, path); path.pop(); }
  }
  go(0, 0, []);
  return ans;
}
