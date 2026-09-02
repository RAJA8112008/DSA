// Method 1: Brute
// Time: O(4^n * n) | Space: O(n)
// Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

void go(const char* num, int target, int i, char* expr, int len) {
  const char* ops[4] = {"", "+", "-", "*"};
  int o, k;
  if (num[i] == '\0') { expr[len] = '\0'; printf("%s\n", expr); return; }
  if (i == 0) { expr[0] = num[0]; go(num, target, 1, expr, 1); return; }
  for (o = 0; o < 4; o++) {
    k = len;
    for (int p = 0; ops[o][p]; p++) expr[k++] = ops[o][p];
    expr[k++] = num[i];
    go(num, target, i + 1, expr, k);
  }
}


// Method 2: Optimal
// Time: O(4^n) | Space: O(n)
// From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

void go(const char* num, int n, long long target, int i, char* expr, int len, long long cur, long long last) {
  int j, k, plen;
  long long val = 0;
  if (i == n) { if (cur == target) { expr[len] = '\0'; printf("%s\n", expr); } return; }
  for (j = i; j < n; j++) {
    if (j > i && num[i] == '0') break;
    val = val * 10 + (num[j] - '0');
    plen = j - i + 1;
    if (i == 0) {
      for (k = 0; k < plen; k++) expr[k] = num[k];
      go(num, n, target, j + 1, expr, plen, val, val);
    } else {
      expr[len] = '+'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur + val, val);
      expr[len] = '-'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur - val, -val);
      expr[len] = '*'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur - last + last * val, last * val);
    }
  }
}


// Method 3: More optimal
// Time: O(4^n) | Space: O(n)
// Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

void go(const char* num, int n, long long target, int i, char* expr, int len, long long cur, long long last) {
  int j, k, plen;
  long long val = 0;
  if (i == n) { if (cur == target) { expr[len] = '\0'; printf("%s\n", expr); } return; }
  for (j = i; j < n; j++) {
    if (j > i && num[i] == '0') break;
    val = val * 10 + (num[j] - '0');
    plen = j - i + 1;
    if (i == 0) {
      for (k = 0; k < plen; k++) expr[k] = num[k];
      go(num, n, target, j + 1, expr, plen, val, val);
    } else {
      expr[len] = '+'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur + val, val);
      expr[len] = '-'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur - val, -val);
      expr[len] = '*'; for (k = 0; k < plen; k++) expr[len + 1 + k] = num[i + k];
      go(num, n, target, j + 1, expr, len + 1 + plen, cur - last + last * val, last * val);
    }
  }
}
