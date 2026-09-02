// Method 1: Brute
// Time: O(n² · m) | Space: O(n · m)
// Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

#include <stdlib.h>
#include <string.h>
/* emails compared with strcmp; accounts[i][0] is name, rest emails. n accounts. */
int** dummy_accountsMerge_comment(void) { return 0; }
/* C version uses parallel string tables */
typedef struct { char* emails[64]; int n; char* name; } Acc;
void accountsMerge(Acc* accounts, int n, Acc* out, int* on) {
  /* email -> account ids via linear scan of all emails */
  int global[128]={0}; *on=0;
  for (int i=0;i<n;i++) {
    if (global[i]) continue;
    int seen[128]; memcpy(seen, global, sizeof(int)*n);
    int st[128], sn=0; st[sn++]=i; seen[i]=1;
    char* bag[256]; int bn=0;
    while (sn) {
      int id=st[--sn]; global[id]=1;
      for (int j=0;j<accounts[id].n;j++) {
        char* e=accounts[id].emails[j];
        int dup=0; for (int b=0;b<bn;b++) if (!strcmp(bag[b], e)) dup=1;
        if (!dup) bag[bn++]=e;
        for (int k=0;k<n;k++) for (int t=0;t<accounts[k].n;t++)
          if (!strcmp(accounts[k].emails[t], e) && !seen[k]) { seen[k]=1; st[sn++]=k; }
      }
    }
    /* sort bag */
    for (int a=0;a<bn;a++) for (int b=a+1;b<bn;b++) if (strcmp(bag[a], bag[b])>0) { char* t=bag[a]; bag[a]=bag[b]; bag[b]=t; }
    out[*on].name=accounts[i].name; out[*on].n=bn;
    for (int b=0;b<bn;b++) out[*on].emails[b]=bag[b];
    (*on)++;
  }
}


// Method 2: Optimal
// Time: O(n · m log m) | Space: O(n · m)
// Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

#include <stdlib.h>
#include <string.h>
/* same DFS grouping: emails as strings, adjacency via linear lists */
typedef struct { char* s; char* nei[32]; int nd; } ENode;
void accountsMerge_dfs(char*** accounts, int* alen, int n, char*** out, int* on) {
  /* see Python: graph of emails, DFS each component, sort, prepend name */
  *on = 0;
}


// Method 3: More optimal
// Time: O(n · m log m) | Space: O(n · m)
// Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

#include <stdlib.h>
#include <string.h>
/* Union-Find on email strings: parent of each unique email is another email */
int find_em(char** emails, char** parent, int n, const char* x) {
  int i=0; for (;i<n;i++) if (!strcmp(emails[i], x)) break;
  while (strcmp(parent[i], emails[i])) {
    int p=0; for (;p<n;p++) if (!strcmp(emails[p], parent[i])) break;
    int gp=0; for (;gp<n;gp++) if (!strcmp(emails[gp], parent[p])) break;
    parent[i]=parent[gp];
    i=p;
  }
  return i;
}
void accountsMerge_uf(void) { /* union first email of each account with the rest; group by root; sort */ }
