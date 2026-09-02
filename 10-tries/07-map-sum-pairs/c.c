// Method 1: Brute
// Time: O(n L) sum | Space: O(n L)
// A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

typedef struct { char k[48]; int v; } KV;
typedef struct { KV a[256]; int n; } MapSum;
void insert(MapSum* m, const char* key, int val) {
  int i; for (i = 0; i < m->n; i++) if (strcmp(m->a[i].k, key) == 0) { m->a[i].v = val; return; }
  strcpy(m->a[m->n].k, key); m->a[m->n].v = val; m->n++;
}
int sumPref(MapSum* m, const char* prefix) {
  int i, s = 0, n = (int)strlen(prefix);
  for (i = 0; i < m->n; i++)
    if ((int)strlen(m->a[i].k) >= n && strncmp(m->a[i].k, prefix, n) == 0) s += m->a[i].v;
  return s;
}


// Method 2: Optimal
// Time: O(L) insert and sum | Space: O(n L)
// Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

typedef struct { char k[48]; int v; } KV;
typedef struct { KV val[256]; int vn; KV pref[2048]; int pn; } MapSum;
static int getKV(KV* a, int n, const char* k) {
  int i; for (i = 0; i < n; i++) if (strcmp(a[i].k, k) == 0) return i; return -1;
}
void insert(MapSum* m, const char* key, int v) {
  int i = getKV(m->val, m->vn, key);
  int old = i >= 0 ? m->val[i].v : 0;
  int delta = v - old;
  char p[48]; int k = 0, j;
  if (i >= 0) m->val[i].v = v;
  else { strcpy(m->val[m->vn].k, key); m->val[m->vn].v = v; m->vn++; }
  p[0] = 0;
  for (j = 0; key[j]; j++) {
    p[k++] = key[j]; p[k] = 0;
    i = getKV(m->pref, m->pn, p);
    if (i >= 0) m->pref[i].v += delta;
    else { strcpy(m->pref[m->pn].k, p); m->pref[m->pn].v = delta; m->pn++; }
  }
}
int sumPref(MapSum* m, const char* prefix) {
  int i = getKV(m->pref, m->pn, prefix);
  return i >= 0 ? m->pref[i].v : 0;
}


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

typedef struct MSNode { struct MSNode* ch[26]; int sum; } MSNode;
typedef struct { MSNode* root; KV val[256]; int vn; } MapSumT;
void msInsert(MapSumT* m, const char* key, int v) {
  int i = getKV(m->val, m->vn, key);
  int old = i >= 0 ? m->val[i].v : 0;
  int delta = v - old, j;
  MSNode* cur = m->root;
  if (i >= 0) m->val[i].v = v;
  else { strcpy(m->val[m->vn].k, key); m->val[m->vn].v = v; m->vn++; }
  for (j = 0; key[j]; j++) {
    int idx = key[j] - 'a';
    if (!cur->ch[idx]) cur->ch[idx] = (MSNode*)calloc(1, sizeof(MSNode));
    cur = cur->ch[idx];
    cur->sum += delta;
  }
}
int msSum(MapSumT* m, const char* prefix) {
  MSNode* cur = m->root;
  int j;
  for (j = 0; prefix[j]; j++) {
    int idx = prefix[j] - 'a';
    if (!cur->ch[idx]) return 0;
    cur = cur->ch[idx];
  }
  return cur->sum;
}
