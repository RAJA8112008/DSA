// Method 1: Brute
// Time: O(4^n * n) | Space: O(n)
// Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

bool ok(const string& expr) {
  for (int i = 0; i < (int)expr.size(); ) {
    if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*') { i++; continue; }
    int j = i;
    while (j < (int)expr.size() && isdigit(expr[j])) j++;
    if (j - i > 1 && expr[i] == '0') return false;
    i = j;
  }
  return true;
}
void go(string& num, int target, int i, string expr, vector<string>& ans) {
  if (i == (int)num.size()) {
    if (ok(expr)) ans.push_back(expr);
    return;
  }
  if (i == 0) { go(num, target, 1, string(1, num[0]), ans); return; }
  string ops[4] = {"", "+", "-", "*"};
  for (int o = 0; o < 4; o++) go(num, target, i + 1, expr + ops[o] + num[i], ans);
}


// Method 2: Optimal
// Time: O(4^n) | Space: O(n)
// From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

void go(string& num, long target, int i, string& expr, long cur, long last, vector<string>& ans) {
  if (i == (int)num.size()) { if (cur == target) ans.push_back(expr); return; }
  long val = 0;
  int len = (int)expr.size();
  for (int j = i; j < (int)num.size(); j++) {
    if (j > i && num[i] == '0') break;
    val = val * 10 + (num[j] - '0');
    string piece = num.substr(i, j - i + 1);
    if (i == 0) { expr += piece; go(num, target, j + 1, expr, val, val, ans); expr.resize(len); }
    else {
      expr += "+" + piece; go(num, target, j + 1, expr, cur + val, val, ans); expr.resize(len);
      expr += "-" + piece; go(num, target, j + 1, expr, cur - val, -val, ans); expr.resize(len);
      expr += "*" + piece; go(num, target, j + 1, expr, cur - last + last * val, last * val, ans); expr.resize(len);
    }
  }
}


// Method 3: More optimal
// Time: O(4^n) | Space: O(n)
// Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

void go(string& num, long target, int i, string& expr, long cur, long last, vector<string>& ans) {
  if (i == (int)num.size()) { if (cur == target) ans.push_back(expr); return; }
  long val = 0;
  int len = (int)expr.size();
  for (int j = i; j < (int)num.size(); j++) {
    if (j > i && num[i] == '0') break;
    val = val * 10 + (num[j] - '0');
    string piece = num.substr(i, j - i + 1);
    if (i == 0) { expr += piece; go(num, target, j + 1, expr, val, val, ans); expr.resize(len); }
    else {
      expr += "+" + piece; go(num, target, j + 1, expr, cur + val, val, ans); expr.resize(len);
      expr += "-" + piece; go(num, target, j + 1, expr, cur - val, -val, ans); expr.resize(len);
      expr += "*" + piece; go(num, target, j + 1, expr, cur - last + last * val, last * val, ans); expr.resize(len);
    }
  }
}
