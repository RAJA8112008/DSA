// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

function evalRPN(tokens) {
  const a = tokens.slice();
  const ops = { "+": 1, "-": 1, "*": 1, "/": 1 };
  function calc(a, b, op) {
    if (op === "+") return a + b;
    if (op === "-") return a - b;
    if (op === "*") return a * b;
    return a / b < 0 ? Math.ceil(a / b) : Math.floor(a / b);
  }
  while (a.length > 1) {
    let i = 0;
    while (!ops[a[i]]) i++;
    const val = calc(Number(a[i - 2]), Number(a[i - 1]), a[i]);
    a.splice(i - 2, 3, String(val));
  }
  return Number(a[0]);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

function evalRPN(tokens) {
  const st = [];
  for (let i = 0; i < tokens.length; i++) {
    const t = tokens[i];
    if (t !== "+" && t !== "-" && t !== "*" && t !== "/") {
      st.push(Number(t));
      continue;
    }
    const b = st.pop();
    const a = st.pop();
    if (t === "+") st.push(a + b);
    else if (t === "-") st.push(a - b);
    else if (t === "*") st.push(a * b);
    else st.push(a / b < 0 ? Math.ceil(a / b) : Math.floor(a / b));
  }
  return st[0];
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

function evalRPN(tokens) {
  const st = [];
  function apply(op, a, b) {
    if (op === "+") return a + b;
    if (op === "-") return a - b;
    if (op === "*") return a * b;
    return Math.trunc(a / b);
  }
  for (let i = 0; i < tokens.length; i++) {
    const t = tokens[i];
    if (t === "+" || t === "-" || t === "*" || t === "/") {
      const b = st.pop();
      const a = st.pop();
      st.push(apply(t, a, b));
    } else st.push(Number(t));
  }
  return st[0];
}
