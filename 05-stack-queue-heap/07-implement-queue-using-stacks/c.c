// Method 1: Brute
// Time: O(n) pop/peek | Space: O(n)
// On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

#include <stdlib.h>
typedef struct { int *a; int n, cap; } MyQueue;
void q_init(MyQueue* q) { q->a=NULL; q->n=q->cap=0; }
void q_push(MyQueue* q, int x) {
  if (q->n==q->cap) { q->cap = q->cap? q->cap*2:8; q->a=(int*)realloc(q->a,sizeof(int)*q->cap); }
  q->a[q->n++] = x;
}
int q_pop(MyQueue* q) {
  int* tmp = (int*)malloc(sizeof(int)*q->n);
  int tn = 0;
  while (q->n) tmp[tn++] = q->a[--q->n];
  int val = tmp[--tn];
  while (tn) q->a[q->n++] = tmp[--tn];
  free(tmp);
  return val;
}
int q_peek(MyQueue* q) {
  int* tmp = (int*)malloc(sizeof(int)*q->n);
  int tn = 0;
  while (q->n) tmp[tn++] = q->a[--q->n];
  int val = tmp[tn-1];
  while (tn) q->a[q->n++] = tmp[--tn];
  free(tmp);
  return val;
}
int q_empty(MyQueue* q) { return q->n == 0; }


// Method 2: Optimal
// Time: O(1) amortized | Space: O(n)
// push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

#include <stdlib.h>
typedef struct { int *in, *out; int ni, no, ci, co; } MyQueue;
void q_init(MyQueue* q) { q->in=q->out=NULL; q->ni=q->no=q->ci=q->co=0; }
void q_pour(MyQueue* q) {
  if (q->no) return;
  while (q->ni) {
    if (q->no==q->co) { q->co = q->co? q->co*2:8; q->out=(int*)realloc(q->out,sizeof(int)*q->co); }
    q->out[q->no++] = q->in[--q->ni];
  }
}
void q_push(MyQueue* q, int x) {
  if (q->ni==q->ci) { q->ci = q->ci? q->ci*2:8; q->in=(int*)realloc(q->in,sizeof(int)*q->ci); }
  q->in[q->ni++] = x;
}
int q_pop(MyQueue* q) { q_pour(q); return q->out[--q->no]; }
int q_peek(MyQueue* q) { q_pour(q); return q->out[q->no-1]; }
int q_empty(MyQueue* q) { return !q->ni && !q->no; }


// Method 3: More optimal
// Time: O(1) amortized | Space: O(n)
// Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

#include <stdlib.h>
typedef struct { int *in, *out; int ni, no, ci, co; } MyQueue;
void q_init(MyQueue* q) { q->in=q->out=NULL; q->ni=q->no=q->ci=q->co=0; }
void q_push(MyQueue* q, int x) {
  if (q->ni==q->ci) { q->ci = q->ci? q->ci*2:8; q->in=(int*)realloc(q->in,sizeof(int)*q->ci); }
  q->in[q->ni++] = x;
}
int q_peek(MyQueue* q) {
  if (!q->no) {
    while (q->ni) {
      if (q->no==q->co) { q->co = q->co? q->co*2:8; q->out=(int*)realloc(q->out,sizeof(int)*q->co); }
      q->out[q->no++] = q->in[--q->ni];
    }
  }
  return q->out[q->no-1];
}
int q_pop(MyQueue* q) { q_peek(q); return q->out[--q->no]; }
int q_empty(MyQueue* q) { return !q->ni && !q->no; }
