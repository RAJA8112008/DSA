// Method 1: Brute
// Time: O(k! · n · L) | Space: O(k)
// Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

#include <stdlib.h>
#include <string.h>
char ans_al[32];
int valid_al(const char* order, char** words, int nw) {
  int rank[128]={0};
  for (int i=0; order[i]; i++) rank[(int)order[i]]=i;
  for (int i=0;i<nw-1;i++) {
    char *a=words[i], *b=words[i+1];
    int na=(int)strlen(a), nb=(int)strlen(b), n=na<nb?na:nb, diff=0;
    for (int j=0;j<n;j++) if (a[j]!=b[j]) {
      if (rank[(int)a[j]]>rank[(int)b[j]]) return 0;
      diff=1; break;
    }
    if (!diff && na>nb) return 0;
  }
  return 1;
}
void dfs_al(char* letters, int k, int* used, char* path, int plen, char** words, int nw) {
  if (ans_al[0]) return;
  if (plen==k) { path[plen]=0; if (valid_al(path, words, nw)) strcpy(ans_al, path); return; }
  for (int i=0;i<k;i++) {
    if (used[i]) continue;
    used[i]=1; path[plen]=letters[i]; dfs_al(letters,k,used,path,plen+1,words,nw); used[i]=0;
  }
}
char* alienOrder(char** words, int nw) {
  char letters[32]; int k=0, seen[128]={0};
  for (int w=0;w<nw;w++) for (int i=0; words[w][i]; i++) {
    unsigned char ch=words[w][i]; if (!seen[ch]) { seen[ch]=1; letters[k++]=ch; }
  }
  ans_al[0]=0;
  int used[32]={0}; char path[32];
  dfs_al(letters,k,used,path,0,words,nw);
  char* out=(char*)malloc(32); strcpy(out, ans_al); return out;
}


// Method 2: Optimal
// Time: O(n·L + k) | Space: O(k²)
// Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

#include <stdlib.h>
#include <string.h>
int g_al[128][32], gd_al[128], state_al[128], out_al[32], on_al, cycle_al, present_al[128];
void dfs_al2(int u) {
  if (state_al[u]==1) { cycle_al=1; return; }
  if (state_al[u]==2) return;
  state_al[u]=1;
  for (int i=0;i<gd_al[u];i++) dfs_al2(g_al[u][i]);
  state_al[u]=2; out_al[on_al++]=u;
}
char* alienOrder(char** words, int nw) {
  memset(gd_al,0,sizeof(gd_al)); memset(state_al,0,sizeof(state_al)); memset(present_al,0,sizeof(present_al));
  on_al=0; cycle_al=0;
  for (int w=0;w<nw;w++) for (int i=0; words[w][i]; i++) present_al[(int)words[w][i]]=1;
  for (int i=0;i<nw-1;i++) {
    char *a=words[i], *b=words[i+1];
    int na=(int)strlen(a), nb=(int)strlen(b), n=na<nb?na:nb, found=0;
    for (int j=0;j<n;j++) if (a[j]!=b[j]) {
      int u=a[j], v=b[j], dup=0;
      for (int k=0;k<gd_al[u];k++) if (g_al[u][k]==v) dup=1;
      if (!dup) g_al[u][gd_al[u]++]=v;
      found=1; break;
    }
    if (!found && na>nb) { char* e=(char*)malloc(1); e[0]=0; return e; }
  }
  for (int c=0;c<128;c++) if (present_al[c]) dfs_al2(c);
  char* res=(char*)malloc(33); int p=0;
  if (cycle_al) { res[0]=0; return res; }
  for (int i=on_al-1;i>=0;i--) res[p++]=(char)out_al[i];
  res[p]=0; return res;
}


// Method 3: More optimal
// Time: O(n·L + k) | Space: O(k²)
// Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

#include <stdlib.h>
#include <string.h>
char* alienOrder(char** words, int nw) {
  int g[128][32]={0}, gd[128]={0}, indeg[128], present[128]={0};
  for (int i=0;i<128;i++) indeg[i]=-1;
  for (int w=0;w<nw;w++) for (int i=0; words[w][i]; i++) { present[(int)words[w][i]]=1; indeg[(unsigned char)words[w][i]]=0; }
  for (int i=0;i<nw-1;i++) {
    char *a=words[i], *b=words[i+1];
    int na=(int)strlen(a), nb=(int)strlen(b), n=na<nb?na:nb, found=0;
    for (int j=0;j<n;j++) if (a[j]!=b[j]) {
      int u=(unsigned char)a[j], v=(unsigned char)b[j], dup=0;
      for (int k=0;k<gd[u];k++) if (g[u][k]==v) dup=1;
      if (!dup) { g[u][gd[u]++]=v; indeg[v]++; }
      found=1; break;
    }
    if (!found && na>nb) { char* e=(char*)malloc(1); e[0]=0; return e; }
  }
  int q[32], h=0,t=0, keys=0;
  for (int c=0;c<128;c++) if (indeg[c]==0) q[t++]=c;
  for (int c=0;c<128;c++) if (present[c]) keys++;
  char* order=(char*)malloc(33); int p=0;
  while (h<t) {
    int u=q[h++]; order[p++]=(char)u;
    for (int i=0;i<gd[u];i++) { int v=g[u][i]; indeg[v]--; if (indeg[v]==0) q[t++]=v; }
  }
  order[p]=0;
  if (p!=keys) order[0]=0;
  return order;
}
