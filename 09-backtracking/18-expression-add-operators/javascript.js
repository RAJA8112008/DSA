// Method 1: Brute
// Time: O(4^n * n) | Space: O(n)
// Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

function addOperators(num, target) {
  const ans = [];
  const ops = ["", "+", "-", "*"];
  function evalExpr(expr) {
    const tokens = [];
    let i = 0;
    while (i < expr.length) {
      if (expr[i] === "+" || expr[i] === "-") { tokens.push(expr[i]); i++; continue; }
      if (expr[i] === "*") { i++; continue; }
      let j = i, v = 0;
      if (expr[i] === "0" && i + 1 < expr.length && expr[i + 1] >= "0" && expr[i + 1] <= "9" && (i === 0 || (expr[i - 1] !== "0" && expr[i - 1] >= "0"))) {
        /* leading zero check happens in ok() */
      }
      while (j < expr.length && expr[j] >= "0" && expr[j] <= "9") { v = v * 10 + (expr.charCodeAt(j) - 48); j++; }
      if (i > 0 && expr[i - 1] === "*") tokens[tokens.length - 1] *= v;
      else tokens.push(v);
      i = j;
    }
    let sum = 0, sign = 1;
    for (let t = 0; t < tokens.length; t++) {
      if (tokens[t] === "+") sign = 1;
      else if (tokens[t] === "-") sign = -1;
      else { sum += sign * tokens[t]; sign = 1; }
    }
    return sum;
  }
  function ok(expr) {
    for (let i = 0; i < expr.length; i++) {
      if (expr[i] < "0" || expr[i] > "9") continue;
      if (expr[i] === "0" && i + 1 < expr.length && expr[i + 1] >= "0" && expr[i + 1] <= "9") {
        if (i === 0 || expr[i - 1] < "0" || expr[i - 1] > "9") return false;
      }
    }
    return true;
  }
  function go(i, expr) {
    if (i === num.length) {
      if (ok(expr) && evalExpr(expr) === target) ans.push(expr);
      return;
    }
    if (i === 0) { go(1, num[0]); return; }
    for (let o = 0; o < 4; o++) go(i + 1, expr + ops[o] + num[i]);
  }
  if (num.length) go(0, "");
  return ans;
}


// Method 2: Optimal
// Time: O(4^n) | Space: O(n)
// From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

function addOperators(num, target) {
  const ans = [];
  function go(i, expr, cur, last) {
    if (i === num.length) {
      if (cur === target) ans.push(expr);
      return;
    }
    let val = 0;
    for (let j = i; j < num.length; j++) {
      if (j > i && num[i] === "0") break;
      val = val * 10 + (num.charCodeAt(j) - 48);
      const piece = num.slice(i, j + 1);
      if (i === 0) go(j + 1, piece, val, val);
      else {
        go(j + 1, expr + "+" + piece, cur + val, val);
        go(j + 1, expr + "-" + piece, cur - val, -val);
        go(j + 1, expr + "*" + piece, cur - last + last * val, last * val);
      }
    }
  }
  go(0, "", 0, 0);
  return ans;
}


// Method 3: More optimal
// Time: O(4^n) | Space: O(n)
// Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

function addOperators(num, target) {
  const ans = [];
  function go(i, expr, cur, last) {
    if (i === num.length) {
      if (cur === target) ans.push(expr);
      return;
    }
    let val = 0;
    for (let j = i; j < num.length; j++) {
      if (j > i && num[i] === "0") break;
      val = val * 10 + (num.charCodeAt(j) - 48);
      const piece = num.slice(i, j + 1);
      if (i === 0) go(j + 1, piece, val, val);
      else {
        go(j + 1, expr + "+" + piece, cur + val, val);
        go(j + 1, expr + "-" + piece, cur - val, -val);
        go(j + 1, expr + "*" + piece, cur - last + last * val, last * val);
      }
    }
  }
  go(0, "", 0, 0);
  return ans;
}
