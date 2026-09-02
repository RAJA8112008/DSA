// Method 1: Brute
// Time: O(n) getMin | Space: O(n)
// A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

#include <stdlib.h>
/* stack in a[0..n-1]; getMin scans */
typedef struct { int *a; int n, cap; } MinStack;
void ms_init(MinStack* s) { s->a = NULL; s->n = s->cap = 0; }
void ms_push(MinStack* s, int val) {
  if (s->n == s->cap) { s->cap = s->cap ? s->cap * 2 : 8; s->a = (int*)realloc(s->a, sizeof(int)*s->cap); }
  s->a[s->n++] = val;
}
void ms_pop(MinStack* s) { s->n--; }
int ms_top(MinStack* s) { return s->a[s->n - 1]; }
int ms_getMin(MinStack* s) {
  int m = s->a[0];
  for (int i = 1; i < s->n; i++) if (s->a[i] < m) m = s->a[i];
  return m;
}


// Method 2: Optimal
// Time: O(1) | Space: O(n)
// mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

#include <stdlib.h>
/* st[0..n-1] values, mins[0..mn-1] current mins */
typedef struct { int *st, *mins, n, mn, cap, mcap; } MinStack;
void ms_init(MinStack* s) { s->st = s->mins = NULL; s->n = s->mn = s->cap = s->mcap = 0; }
void ms_push(MinStack* s, int val) {
  if (s->n == s->cap) { s->cap = s->cap ? s->cap * 2 : 8; s->st = (int*)realloc(s->st, sizeof(int)*s->cap); }
  s->st[s->n++] = val;
  if (!s->mn || val <= s->mins[s->mn - 1]) {
    if (s->mn == s->mcap) { s->mcap = s->mcap ? s->mcap * 2 : 8; s->mins = (int*)realloc(s->mins, sizeof(int)*s->mcap); }
    s->mins[s->mn++] = val;
  }
}
void ms_pop(MinStack* s) {
  int val = s->st[--s->n];
  if (val == s->mins[s->mn - 1]) s->mn--;
}
int ms_top(MinStack* s) { return s->st[s->n - 1]; }
int ms_getMin(MinStack* s) { return s->mins[s->mn - 1]; }


// Method 3: More optimal
// Time: O(1) | Space: O(n)
// One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

#include <stdlib.h>
/* pair stack: val[i], mn[i] = min of prefix */
typedef struct { int *val, *mn, n, cap; } MinStack;
void ms_init(MinStack* s) { s->val = s->mn = NULL; s->n = s->cap = 0; }
void ms_push(MinStack* s, int v) {
  if (s->n == s->cap) {
    s->cap = s->cap ? s->cap * 2 : 8;
    s->val = (int*)realloc(s->val, sizeof(int)*s->cap);
    s->mn = (int*)realloc(s->mn, sizeof(int)*s->cap);
  }
  int m = s->n ? (s->mn[s->n-1] < v ? s->mn[s->n-1] : v) : v;
  s->val[s->n] = v; s->mn[s->n] = m; s->n++;
}
void ms_pop(MinStack* s) { s->n--; }
int ms_top(MinStack* s) { return s->val[s->n - 1]; }
int ms_getMin(MinStack* s) { return s->mn[s->n - 1]; }
