// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each pass scans the whole string and removes one pair. Up to n/2 passes.
// How it works: while any "()", "[]", or "{}" remains, split-join it away. Success is an empty string.

function isValid(s) {
  let cur = s;
  let changed = true;
  while (changed) {
    const next = cur.split("()").join("").split("[]").join("").split("{}").join("");
    changed = next !== cur;
    cur = next;
  }
  return cur.length === 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One pass. Stack holds at most n openers.
// How it works: push openers. On a closer, pop and check it is the matching opener. Leftover openers fail.

function isValid(s) {
  const stack = [];
  for (let i = 0; i < s.length; i++) {
    const ch = s[i];
    if (ch === "(" || ch === "[" || ch === "{") {
      stack.push(ch);
    } else {
      const top = stack.pop();
      if (ch === ")" && top !== "(") return false;
      if (ch === "]" && top !== "[") return false;
      if (ch === "}" && top !== "{") return false;
    }
  }
  return stack.length === 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same O(n) bound. A pair map avoids three mismatch branches, and odd length fails immediately.
// How it works: if the character is a key in pairs, it is a closer: pop must equal pairs[ch]. Else it is an opener: push.

function isValid(s) {
  if (s.length % 2 === 1) return false;
  const pairs = { ")": "(", "]": "[", "}": "{" };
  const stack = [];
  for (let i = 0; i < s.length; i++) {
    const ch = s[i];
    if (pairs[ch]) {
      if (stack.pop() !== pairs[ch]) return false;
    } else {
      stack.push(ch);
    }
  }
  return stack.length === 0;
}
