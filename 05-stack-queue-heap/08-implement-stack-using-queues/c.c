// Method 1: Brute
// Time: O(n) pop | Space: O(n)
// Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

#include <stdlib.h>
/* two queues as ring buffers in arrays */
typedef struct { int *q1, *q2; int h1, t1, h2, t2, c1, c2; } MyStack;
void s_init(MyStack* s) { s->q1=s->q2=NULL; s->h1=s->t1=s->h2=s->t2=0; s->c1=s->c2=8;
  s->q1=(int*)malloc(sizeof(int)*8); s->q2=(int*)malloc(sizeof(int)*8); }
int s_len1(MyStack* s) { return s->t1 - s->h1; }
void s_push(MyStack* s, int x) { s->q1[s->t1++] = x; }
int s_pop(MyStack* s) {
  while (s_len1(s) > 1) s->q2[s->t2++] = s->q1[s->h1++];
  int val = s->q1[s->h1++];
  int *tq=s->q1; s->q1=s->q2; s->q2=tq;
  int th=s->h1, tt=s->t1; s->h1=s->h2; s->t1=s->t2; s->h2=th; s->t2=tt;
  return val;
}
int s_top(MyStack* s) { int v = s_pop(s); s_push(s, v); return v; }
int s_empty(MyStack* s) { return s_len1(s) == 0; }


// Method 2: Optimal
// Time: O(n) push, O(1) pop | Space: O(n)
// One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

#include <stdlib.h>
typedef struct { int *q; int h, t, cap; } MyStack;
void s_init(MyStack* s) { s->cap=16; s->q=(int*)malloc(sizeof(int)*16); s->h=s->t=0; }
int s_len(MyStack* s) { return s->t - s->h; }
void s_push(MyStack* s, int x) {
  s->q[s->t++] = x;
  int n = s_len(s);
  for (int i = 0; i < n - 1; i++) s->q[s->t++] = s->q[s->h++];
}
int s_pop(MyStack* s) { return s->q[s->h++]; }
int s_top(MyStack* s) { return s->q[s->h]; }
int s_empty(MyStack* s) { return s_len(s) == 0; }


// Method 3: More optimal
// Time: O(1) push, O(n) pop | Space: O(n)
// One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

#include <stdlib.h>
typedef struct { int *q; int h, t, cap; } MyStack;
void s_init(MyStack* s) { s->cap=16; s->q=(int*)malloc(sizeof(int)*16); s->h=s->t=0; }
int s_len(MyStack* s) { return s->t - s->h; }
void s_push(MyStack* s, int x) { s->q[s->t++] = x; }
int s_pop(MyStack* s) {
  int n = s_len(s);
  for (int i = 0; i < n - 1; i++) s->q[s->t++] = s->q[s->h++];
  return s->q[s->h++];
}
int s_top(MyStack* s) { return s->q[s->t - 1]; }
int s_empty(MyStack* s) { return s_len(s) == 0; }
