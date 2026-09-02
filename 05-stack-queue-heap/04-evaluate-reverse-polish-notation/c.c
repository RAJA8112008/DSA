// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int calc(int a, int b, const char* op) {
  if (op[0] == '+') return a + b;
  if (op[0] == '-' && op[1] == 0) return a - b;
  if (op[0] == '*') return a * b;
  return a / b; /* trunc toward 0 in C for ints */
}
int isop(const char* t) {
  return !strcmp(t, "+") || !strcmp(t, "-") || !strcmp(t, "*") || !strcmp(t, "/");
}
int evalRPN(char** tokens, int n) {
  char** a = (char**)malloc(sizeof(char*) * n);
  int m = n;
  for (int i = 0; i < n; i++) a[i] = tokens[i];
  char buf[32][16]; int bi = 0;
  while (m > 1) {
    int i = 0;
    while (!isop(a[i])) i++;
    int val = calc(atoi(a[i-2]), atoi(a[i-1]), a[i]);
    sprintf(buf[bi], "%d", val);
    a[i-2] = buf[bi++];
    for (int j = i - 1; j < m - 2; j++) a[j] = a[j + 2];
    m -= 2;
  }
  int ans = atoi(a[0]);
  free(a);
  return ans;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

#include <stdlib.h>
#include <string.h>
int evalRPN(char** tokens, int n) {
  int* st = (int*)malloc(sizeof(int) * n);
  int sn = 0;
  for (int i = 0; i < n; i++) {
    char* t = tokens[i];
    if (strcmp(t, "+") && strcmp(t, "-") && strcmp(t, "*") && strcmp(t, "/")) {
      st[sn++] = atoi(t);
      continue;
    }
    int b = st[--sn], a = st[--sn];
    if (t[0] == '+') st[sn++] = a + b;
    else if (t[0] == '-' && t[1] == 0) st[sn++] = a - b;
    else if (t[0] == '*') st[sn++] = a * b;
    else st[sn++] = a / b;
  }
  int ans = st[0];
  free(st);
  return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

#include <stdlib.h>
#include <string.h>
int apply(const char* op, int a, int b) {
  if (op[0] == '+') return a + b;
  if (op[0] == '-' && op[1] == 0) return a - b;
  if (op[0] == '*') return a * b;
  return a / b;
}
int evalRPN(char** tokens, int n) {
  int* st = (int*)malloc(sizeof(int) * n);
  int sn = 0;
  for (int i = 0; i < n; i++) {
    char* t = tokens[i];
    if (!strcmp(t, "+") || !strcmp(t, "-") || !strcmp(t, "*") || !strcmp(t, "/")) {
      int b = st[--sn], a = st[--sn];
      st[sn++] = apply(t, a, b);
    } else st[sn++] = atoi(t);
  }
  int ans = st[0];
  free(st);
  return ans;
}
