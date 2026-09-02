// Method 1: Brute
// Time: O(26^L · n) | Space: O(n·L)
// DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

#include <stdlib.h>
#include <string.h>
#include <limits.h>
int best_ll;
int has_word(char** left, int n, int* used, const char* w) {
  for (int i=0;i<n;i++) if (!used[i] && !strcmp(left[i], w)) return i;
  return -1;
}
void dfs_ll(char* word, int dist, char** left, int n, int* used, const char* endWord) {
  if (dist >= best_ll) return;
  if (!strcmp(word, endWord)) { best_ll = dist; return; }
  int L = (int)strlen(word);
  char* next = (char*)malloc(L+1); strcpy(next, word);
  for (int i=0;i<L;i++) {
    char old = next[i];
    for (char c='a'; c<='z'; c++) {
      next[i]=c;
      int idx = has_word(left, n, used, next);
      if (idx < 0) continue;
      int* copy=(int*)malloc(sizeof(int)*n); memcpy(copy, used, sizeof(int)*n); copy[idx]=1;
      dfs_ll(next, dist+1, left, n, copy, endWord);
      free(copy);
    }
    next[i]=old;
  }
  free(next);
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int n) {
  int found=0; for (int i=0;i<n;i++) if (!strcmp(wordList[i], endWord)) found=1;
  if (!found) return 0;
  best_ll = INT_MAX;
  int* used=(int*)calloc(n,sizeof(int));
  dfs_ll(beginWord, 1, wordList, n, used, endWord);
  return best_ll==INT_MAX ? 0 : best_ll;
}


// Method 2: Optimal
// Time: O(n·L·26) | Space: O(n·L)
// BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

#include <stdlib.h>
#include <string.h>
int in_set(char** w, int n, int* used, const char* s) {
  for (int i=0;i<n;i++) if (!used[i] && !strcmp(w[i], s)) return i;
  return -1;
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int n) {
  int found=0; for (int i=0;i<n;i++) if (!strcmp(wordList[i], endWord)) found=1;
  if (!found) return 0;
  int* used=(int*)calloc(n,sizeof(int));
  int bi=in_set(wordList,n,used,beginWord); if (bi>=0) used[bi]=1;
  int cap=n+2; char** q=(char**)malloc(sizeof(char*)*cap); int* dist=(int*)malloc(sizeof(int)*cap);
  int h=0,t=0; q[t]=beginWord; dist[t]=1; t++;
  int L=(int)strlen(beginWord);
  while (h<t) {
    char* word=q[h]; int d=dist[h]; h++;
    if (!strcmp(word, endWord)) return d;
    char* next=(char*)malloc(L+1); strcpy(next, word);
    for (int i=0;i<L;i++) {
      char old=next[i];
      for (char c='a';c<='z';c++) {
        next[i]=c;
        int idx=in_set(wordList,n,used,next);
        if (idx<0) continue;
        used[idx]=1;
        q[t]=wordList[idx]; dist[t]=d+1; t++;
      }
      next[i]=old;
    }
    free(next);
  }
  return 0;
}


// Method 3: More optimal
// Time: O(n·L·26) | Space: O(n·L)
// Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

#include <stdlib.h>
#include <string.h>
/* bidirectional BFS: two frontier arrays of word indices; words[n] plus begin as extra */
int ladderLength(char* beginWord, char* endWord, char** wordList, int n) {
  int endIdx=-1;
  for (int i=0;i<n;i++) if (!strcmp(wordList[i], endWord)) endIdx=i;
  if (endIdx<0) return 0;
  int* seen=(int*)calloc(n+1,sizeof(int));
  int* b1=(int*)malloc(sizeof(int)*(n+1));
  int* b2=(int*)malloc(sizeof(int)*(n+1));
  int n1=1, n2=1; b1[0]=-1; /* -1 means beginWord */ b2[0]=endIdx;
  seen[endIdx]=1;
  int steps=1;
  while (n1 && n2) {
    if (n1>n2) { int* t=b1; b1=b2; b2=t; int tn=n1; n1=n2; n2=tn; }
    int nn=0; int* next=(int*)malloc(sizeof(int)*(n+1));
    for (int b=0;b<n1;b++) {
      char* word = b1[b]<0 ? beginWord : wordList[b1[b]];
      int L=(int)strlen(word);
      char* cand=(char*)malloc(L+1); strcpy(cand, word);
      for (int i=0;i<L;i++) {
        char old=cand[i];
        for (char c='a';c<='z';c++) {
          cand[i]=c;
          int inEnd=0;
          for (int k=0;k<n2;k++) {
            char* ew = b2[k]<0 ? beginWord : wordList[b2[k]];
            if (!strcmp(cand, ew)) { free(cand); return steps+1; }
          }
          int idx=-1;
          for (int j=0;j<n;j++) if (!seen[j] && !strcmp(wordList[j], cand)) { idx=j; break; }
          if (idx<0) continue;
          seen[idx]=1; next[nn++]=idx;
        }
        cand[i]=old;
      }
      free(cand);
    }
    free(b1); b1=next; n1=nn; steps++;
  }
  return 0;
}
