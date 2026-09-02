// Method 1: Brute
// Time: O(n · out) | Space: O(n · out)
// Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

#include <stdlib.h>
#include <string.h>
typedef struct { char* text; int i; } Pair;
Pair parse(const char* s, int i) {
  int cap = 32, n = 0;
  char* out = (char*)malloc(cap); out[0] = 0;
  while (s[i] && s[i] != ']') {
    if (s[i] < '0' || s[i] > '9') {
      if (n + 2 > cap) { cap *= 2; out = (char*)realloc(out, cap); }
      out[n++] = s[i]; out[n] = 0; i++; continue;
    }
    int k = 0;
    while (s[i] >= '0' && s[i] <= '9') { k = k * 10 + (s[i] - '0'); i++; }
    i++; /* skip '[' */
    Pair inner = parse(s, i);
    int inlen = (int)strlen(inner.text);
    for (int t = 0; t < k; t++) {
      if (n + inlen + 1 > cap) { cap = (n + inlen + 1) * 2; out = (char*)realloc(out, cap); }
      memcpy(out + n, inner.text, inlen); n += inlen; out[n] = 0;
    }
    i = inner.i + 1; /* skip ']' */
    free(inner.text);
  }
  Pair p; p.text = out; p.i = i; return p;
}
char* decodeString(const char* s) { return parse(s, 0).text; }


// Method 2: Optimal
// Time: O(n + out) | Space: O(n + out)
// One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

#include <stdlib.h>
#include <string.h>
char* decodeString(const char* s) {
  char* prevs[128]; int ks[128], sn = 0;
  int cap = 64, n = 0;
  char* cur = (char*)malloc(cap); cur[0] = 0;
  int k = 0;
  for (int i = 0; s[i]; i++) {
    char ch = s[i];
    if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
    else if (ch == '[') {
      prevs[sn] = cur; ks[sn] = k; sn++;
      cap = 64; n = 0; cur = (char*)malloc(cap); cur[0] = 0; k = 0;
    } else if (ch == ']') {
      char* prev = prevs[--sn]; int ck = ks[sn];
      int pn = (int)strlen(prev), cn = (int)strlen(cur);
      char* next = (char*)malloc(pn + cn * ck + 1);
      memcpy(next, prev, pn);
      for (int t = 0; t < ck; t++) memcpy(next + pn + t * cn, cur, cn);
      next[pn + cn * ck] = 0;
      free(prev); free(cur); cur = next;
    } else {
      int cn = (int)strlen(cur);
      cur = (char*)realloc(cur, cn + 2);
      cur[cn] = ch; cur[cn+1] = 0;
    }
  }
  return cur;
}


// Method 3: More optimal
// Time: O(n + out) | Space: O(n + out)
// Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

#include <stdlib.h>
#include <string.h>
char* decodeString(const char* s) {
  char* strs[128]; int counts[128], sn = 0, cn = 0;
  int cap = 64;
  char* cur = (char*)malloc(cap); cur[0] = 0;
  int k = 0;
  for (int i = 0; s[i]; i++) {
    char ch = s[i];
    if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
    else if (ch == '[') {
      counts[cn++] = k; strs[sn++] = cur;
      cap = 64; cur = (char*)malloc(cap); cur[0] = 0; k = 0;
    } else if (ch == ']') {
      int ck = counts[--cn];
      char* prev = strs[--sn];
      int pn = (int)strlen(prev), cl = (int)strlen(cur);
      char* next = (char*)malloc(pn + cl * ck + 1);
      memcpy(next, prev, pn);
      for (int t = 0; t < ck; t++) memcpy(next + pn + t * cl, cur, cl);
      next[pn + cl * ck] = 0;
      free(prev); free(cur); cur = next;
    } else {
      int cl = (int)strlen(cur);
      cur = (char*)realloc(cur, cl + 2);
      cur[cl] = ch; cur[cl+1] = 0;
    }
  }
  return cur;
}
