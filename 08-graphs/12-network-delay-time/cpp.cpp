// Method 1: Brute
// Time: O(n^e) | Space: O(n + e)
// DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

class Solution {
  void dfs(vector<vector<pair<int,int>>>& g, int u, int d, vector<int>& dist, vector<int> visiting) {
    if (d >= dist[u]) return;
    dist[u]=d; visiting[u]=1;
    for (auto e : g[u]) if (!visiting[e.first]) dfs(g, e.first, d+e.second, dist, visiting);
  }
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> g(n+1);
    for (auto& t : times) g[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n+1, INT_MAX/4);
    dfs(g, k, 0, dist, vector<int>(n+1));
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans, dist[i]);
    return ans>=INT_MAX/4 ? -1 : ans;
  }
};


// Method 2: Optimal
// Time: O(n² + e) | Space: O(n + e)
// Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> g(n+1);
    for (auto& t : times) g[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n+1, INT_MAX/4), used(n+1);
    dist[k]=0;
    for (int round=0; round<n; round++) {
      int u=-1;
      for (int i=1;i<=n;i++) {
        if (used[i]) continue;
        if (u==-1 || dist[i]<dist[u]) u=i;
      }
      if (u==-1 || dist[u]==INT_MAX/4) break;
      used[u]=1;
      for (auto e : g[u]) if (dist[u]+e.second < dist[e.first]) dist[e.first]=dist[u]+e.second;
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans, dist[i]);
    return ans>=INT_MAX/4 ? -1 : ans;
  }
};


// Method 3: More optimal
// Time: O((n + e) log n) | Space: O(n + e)
// Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

class Solution {
  vector<pair<int,int>> heap;
  void push(int d, int u) {
    heap.push_back({d,u}); int i=(int)heap.size()-1;
    while (i>0) { int p=(i-1)>>1; if (heap[i].first>=heap[p].first) break; swap(heap[i], heap[p]); i=p; }
  }
  pair<int,int> pop() {
    auto top=heap[0]; auto last=heap.back(); heap.pop_back();
    if (!heap.empty()) { heap[0]=last; int i=0;
      while (true) { int s=i,l=i*2+1,r=l+1,n=(int)heap.size();
        if (l<n && heap[l].first<heap[s].first) s=l;
        if (r<n && heap[r].first<heap[s].first) s=r;
        if (s==i) break; swap(heap[i], heap[s]); i=s; } }
    return top;
  }
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> g(n+1);
    for (auto& t : times) g[t[0]].push_back({t[1], t[2]});
    vector<int> dist(n+1, INT_MAX/4); dist[k]=0;
    push(0,k);
    while (!heap.empty()) {
      auto cur=pop(); int d=cur.first, u=cur.second;
      if (d>dist[u]) continue;
      for (auto e : g[u]) if (d+e.second < dist[e.first]) { dist[e.first]=d+e.second; push(dist[e.first], e.first); }
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans, dist[i]);
    return ans>=INT_MAX/4 ? -1 : ans;
  }
};
