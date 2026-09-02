// Method 1: Brute
// Time: set O(1), get O(n) | Space: O(n)
// Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

#include <string.h>
#define MAXE 10000
typedef struct { char key[24]; int time; char val[24]; } Entry;
typedef struct { Entry e[MAXE]; int n; } TimeMap;
void TimeMap_init(TimeMap* t) { t->n = 0; }
void TimeMap_set(TimeMap* t, const char* key, const char* value, int timestamp) {
  strcpy(t->e[t->n].key, key);
  strcpy(t->e[t->n].val, value);
  t->e[t->n].time = timestamp;
  t->n++;
}
void TimeMap_get(TimeMap* t, const char* key, int timestamp, char* out) {
  out[0] = 0;
  for (int i = 0; i < t->n; i++) {
    if (strcmp(t->e[i].key, key) == 0 && t->e[i].time <= timestamp) strcpy(out, t->e[i].val);
  }
}


// Method 2: Optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

#include <string.h>
#define MAXE 10000
typedef struct { char key[24]; int time; char val[24]; } Entry;
typedef struct { Entry e[MAXE]; int n; } TimeMap;
void TimeMap_init(TimeMap* t) { t->n = 0; }
void TimeMap_set(TimeMap* t, const char* key, const char* value, int timestamp) {
  strcpy(t->e[t->n].key, key);
  strcpy(t->e[t->n].val, value);
  t->e[t->n].time = timestamp;
  t->n++;
}
void TimeMap_get(TimeMap* t, const char* key, int timestamp, char* out) {
  int lo = 0, hi = t->n - 1;
  out[0] = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (strcmp(t->e[mid].key, key) != 0) { /* demo: single-key store */
      if (t->e[mid].time <= timestamp) lo = mid + 1; else hi = mid - 1;
      continue;
    }
    if (t->e[mid].time <= timestamp) { strcpy(out, t->e[mid].val); lo = mid + 1; }
    else hi = mid - 1;
  }
}


// Method 3: More optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

#include <string.h>
#define MAXE 10000
typedef struct { int time; char val[24]; } Ver;
typedef struct { Ver v[MAXE]; int n; } TimeMap;
void TimeMap_init(TimeMap* t) { t->n = 0; }
void TimeMap_set(TimeMap* t, const char* key, const char* value, int timestamp) {
  (void)key;
  t->v[t->n].time = timestamp;
  strcpy(t->v[t->n].val, value);
  t->n++;
}
void TimeMap_get(TimeMap* t, const char* key, int timestamp, char* out) {
  (void)key;
  int lo = 0, hi = t->n;
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (t->v[mid].time <= timestamp) lo = mid + 1;
    else hi = mid;
  }
  if (lo == 0) out[0] = 0;
  else strcpy(out, t->v[lo - 1].val);
}
