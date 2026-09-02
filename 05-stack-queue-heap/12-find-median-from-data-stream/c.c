// Method 1: Brute
// Time: O(n log n) find | Space: O(n)
// Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

#include <stdlib.h>
typedef struct { int *a; int n, cap; } MedianFinder;
void mf_init(MedianFinder* m) { m->a=NULL; m->n=m->cap=0; }
void mf_addNum(MedianFinder* m, int num) {
  if (m->n==m->cap) { m->cap = m->cap? m->cap*2:8; m->a=(int*)realloc(m->a,sizeof(int)*m->cap); }
  m->a[m->n++] = num;
}
int cmp_asc(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
double mf_findMedian(MedianFinder* m) {
  int* b = (int*)malloc(sizeof(int)*m->n);
  for (int i = 0; i < m->n; i++) b[i] = m->a[i];
  qsort(b, m->n, sizeof(int), cmp_asc);
  int n = m->n;
  double ans = n % 2 ? b[(n-1)/2] : (b[n/2-1] + b[n/2]) / 2.0;
  free(b);
  return ans;
}


// Method 2: Optimal
// Time: O(n) add, O(1) find | Space: O(n)
// Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

#include <stdlib.h>
typedef struct { int *a; int n, cap; } MedianFinder;
void mf_init(MedianFinder* m) { m->a=NULL; m->n=m->cap=0; }
void mf_addNum(MedianFinder* m, int num) {
  if (m->n==m->cap) { m->cap = m->cap? m->cap*2:8; m->a=(int*)realloc(m->a,sizeof(int)*m->cap); }
  int lo = 0, hi = m->n;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (m->a[mid] < num) lo = mid + 1; else hi = mid;
  }
  for (int i = m->n; i > lo; i--) m->a[i] = m->a[i-1];
  m->a[lo] = num; m->n++;
}
double mf_findMedian(MedianFinder* m) {
  int n = m->n;
  if (n % 2) return m->a[(n-1)/2];
  return (m->a[n/2-1] + m->a[n/2]) / 2.0;
}


// Method 3: More optimal
// Time: O(log n) add, O(1) find | Space: O(n)
// low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

#include <stdlib.h>
/* two array heaps: low is max via negation, high is min */
typedef struct { int *low, *high; int ln, hn, cl, ch; } MedianFinder;
void up(int* h, int i) {
  while (i > 0) { int p=(i-1)>>1; if (h[i]>=h[p]) break; int t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
}
void down(int* h, int n, int i) {
  while (1) { int s=i, l=i*2+1, r=l+1;
    if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
    if (s==i) break; int t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
}
void mf_init(MedianFinder* m) { m->low=m->high=NULL; m->ln=m->hn=m->cl=m->ch=0; }
void push_low(MedianFinder* m, int x) {
  if (m->ln==m->cl) { m->cl = m->cl? m->cl*2:8; m->low=(int*)realloc(m->low,sizeof(int)*m->cl); }
  m->low[m->ln++]=x; up(m->low, m->ln-1);
}
void push_high(MedianFinder* m, int x) {
  if (m->hn==m->ch) { m->ch = m->ch? m->ch*2:8; m->high=(int*)realloc(m->high,sizeof(int)*m->ch); }
  m->high[m->hn++]=x; up(m->high, m->hn-1);
}
int pop_low(MedianFinder* m) { int t=m->low[0]; m->low[0]=m->low[--m->ln]; if (m->ln) down(m->low, m->ln, 0); return t; }
int pop_high(MedianFinder* m) { int t=m->high[0]; m->high[0]=m->high[--m->hn]; if (m->hn) down(m->high, m->hn, 0); return t; }
void mf_addNum(MedianFinder* m, int num) {
  push_low(m, -num);
  push_high(m, -pop_low(m));
  if (m->hn > m->ln) push_low(m, -pop_high(m));
}
double mf_findMedian(MedianFinder* m) {
  if (m->ln > m->hn) return -m->low[0];
  return (-m->low[0] + m->high[0]) / 2.0;
}
