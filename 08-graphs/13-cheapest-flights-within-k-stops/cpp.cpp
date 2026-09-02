// Method 1: Brute
// Time: O(n^K) | Space: O(n + e)
// DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

class Solution {
  int best;
  void dfs(vector<vector<pair<int,int>>>& g, int u, int cost, int stops, vector<int> visiting, int dst) {
    if (cost >= best) return;
    if (u==dst) { best=cost; return; }
    if (stops<0) return;
    visiting[u]=1;
    for (auto e : g[u]) if (!visiting[e.first]) dfs(g, e.first, cost+e.second, stops-1, visiting, dst);
  }
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> g(n);
    for (auto& f : flights) g[f[0]].push_back({f[1], f[2]});
    best=INT_MAX/4;
    dfs(g, src, 0, k, vector<int>(n), dst);
    return best>=INT_MAX/4 ? -1 : best;
  }
};


// Method 2: Optimal
// Time: O(K · e) | Space: O(n)
// Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX/4); dist[src]=0;
    for (int round=0; round<=k; round++) {
      vector<int> next=dist;
      for (auto& f : flights) {
        int u=f[0], v=f[1], w=f[2];
        if (dist[u]==INT_MAX/4) continue;
        if (dist[u]+w < next[v]) next[v]=dist[u]+w;
      }
      dist.swap(next);
    }
    return dist[dst]==INT_MAX/4 ? -1 : dist[dst];
  }
};


// Method 3: More optimal
// Time: O(K · e log (K n)) | Space: O(n · K + e)
// Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

class Solution {
  vector<array<int,3>> heap;
  void push(array<int,3> x) {
    heap.push_back(x); int i=(int)heap.size()-1;
    while (i>0) { int p=(i-1)>>1; if (heap[i][0]>=heap[p][0]) break; swap(heap[i], heap[p]); i=p; }
  }
  array<int,3> pop() {
    auto top=heap[0]; auto last=heap.back(); heap.pop_back();
    if (!heap.empty()) { heap[0]=last; int i=0;
      while (true) { int s=i,l=i*2+1,r=l+1,n=(int)heap.size();
        if (l<n && heap[l][0]<heap[s][0]) s=l;
        if (r<n && heap[r][0]<heap[s][0]) s=r;
        if (s==i) break; swap(heap[i], heap[s]); i=s; } }
    return top;
  }
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> g(n);
    for (auto& f : flights) g[f[0]].push_back({f[1], f[2]});
    vector<vector<int>> best(n, vector<int>(k+2, INT_MAX/4));
    best[src][0]=0; push({0,src,0});
    while (!heap.empty()) {
      auto cur=pop(); int cost=cur[0], u=cur[1], used=cur[2];
      if (u==dst) return cost;
      if (used>k) continue;
      for (auto e : g[u]) {
        int nc=cost+e.second;
        if (nc>=best[e.first][used+1]) continue;
        best[e.first][used+1]=nc; push({nc, e.first, used+1});
      }
    }
    return -1;
  }
};
