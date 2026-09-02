// Method 1: Brute
// Time: O(k! · n · L) | Space: O(k)
// Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

class Solution {
  string ans;
  bool valid(const string& order, vector<string>& words) {
    int rank[128]={}; for (int i=0;i<(int)order.size();i++) rank[(int)order[i]]=i;
    for (int i=0;i<(int)words.size()-1;i++) {
      string a=words[i], b=words[i+1];
      int n=min((int)a.size(), (int)b.size()); bool diff=false;
      for (int j=0;j<n;j++) if (a[j]!=b[j]) {
        if (rank[(int)a[j]]>rank[(int)b[j]]) return false;
        diff=true; break;
      }
      if (!diff && a.size()>b.size()) return false;
    }
    return true;
  }
  void dfs(string& letters, vector<int>& used, string& path, vector<string>& words) {
    if (!ans.empty()) return;
    if (path.size()==letters.size()) { if (valid(path, words)) ans=path; return; }
    for (int i=0;i<(int)letters.size();i++) {
      if (used[i]) continue;
      used[i]=1; path.push_back(letters[i]); dfs(letters, used, path, words);
      path.pop_back(); used[i]=0;
    }
  }
public:
  string alienOrder(vector<string>& words) {
    string letters; int seen[128]={};
    for (auto& w : words) for (char ch : w) if (!seen[(int)ch]) { seen[(int)ch]=1; letters.push_back(ch); }
    ans=""; vector<int> used(letters.size()); string path;
    dfs(letters, used, path, words);
    return ans;
  }
};


// Method 2: Optimal
// Time: O(n·L + k) | Space: O(k²)
// Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

class Solution {
  bool cycle;
  void dfs(char u, unordered_map<char, unordered_set<char>>& g, unordered_map<char,int>& state, string& out) {
    if (state[u]==1) { cycle=true; return; }
    if (state[u]==2) return;
    state[u]=1;
    for (char v : g[u]) dfs(v, g, state, out);
    state[u]=2; out.push_back(u);
  }
public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char,int> state;
    for (auto& w : words) for (char ch : w) { if (!g.count(ch)) { g[ch]={}; state[ch]=0; } }
    for (int i=0;i<(int)words.size()-1;i++) {
      string a=words[i], b=words[i+1];
      int n=min((int)a.size(),(int)b.size()); bool found=false;
      for (int j=0;j<n;j++) if (a[j]!=b[j]) { g[a[j]].insert(b[j]); found=true; break; }
      if (!found && a.size()>b.size()) return "";
    }
    string out; cycle=false;
    for (auto& p : g) dfs(p.first, g, state, out);
    if (cycle) return "";
    reverse(out.begin(), out.end());
    return out;
  }
};


// Method 3: More optimal
// Time: O(n·L + k) | Space: O(k²)
// Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

class Solution {
public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char,int> indeg;
    for (auto& w : words) for (char ch : w) if (!g.count(ch)) { g[ch]={}; indeg[ch]=0; }
    for (int i=0;i<(int)words.size()-1;i++) {
      string a=words[i], b=words[i+1];
      int n=min((int)a.size(),(int)b.size()); bool found=false;
      for (int j=0;j<n;j++) if (a[j]!=b[j]) {
        if (!g[a[j]].count(b[j])) { g[a[j]].insert(b[j]); indeg[b[j]]++; }
        found=true; break;
      }
      if (!found && a.size()>b.size()) return "";
    }
    queue<char> q;
    for (auto& p : indeg) if (p.second==0) q.push(p.first);
    string order;
    while (!q.empty()) {
      char u=q.front(); q.pop(); order+=u;
      for (char v : g[u]) { indeg[v]--; if (indeg[v]==0) q.push(v); }
    }
    return (int)order.size()==(int)indeg.size() ? order : "";
  }
};
