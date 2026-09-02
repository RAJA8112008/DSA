// Method 1: Brute
// Time: O(n² · m) | Space: O(n · m)
// Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, vector<int>> emailToIds;
    for (int i=0;i<(int)accounts.size();i++)
      for (int j=1;j<(int)accounts[i].size();j++) emailToIds[accounts[i][j]].push_back(i);
    vector<int> global(accounts.size());
    vector<vector<string>> ans;
    for (int i=0;i<(int)accounts.size();i++) {
      if (global[i]) continue;
      vector<int> seen=global;
      vector<int> st; st.push_back(i); seen[i]=1;
      set<string> emails;
      while (!st.empty()) {
        int id=st.back(); st.pop_back(); global[id]=1;
        for (int j=1;j<(int)accounts[id].size();j++) {
          string e=accounts[id][j]; emails.insert(e);
          for (int k : emailToIds[e]) { if (seen[k]) continue; seen[k]=1; st.push_back(k); }
        }
      }
      vector<string> list(emails.begin(), emails.end());
      vector<string> row; row.push_back(accounts[i][0]);
      row.insert(row.end(), list.begin(), list.end());
      ans.push_back(row);
    }
    return ans;
  }
};


// Method 2: Optimal
// Time: O(n · m log m) | Space: O(n · m)
// Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, unordered_set<string>> g;
    unordered_map<string, string> emailName;
    for (auto& acc : accounts) {
      string name=acc[0];
      for (int j=1;j<(int)acc.size();j++) {
        string e=acc[j]; emailName[e]=name;
        if (j>1) { g[e].insert(acc[1]); g[acc[1]].insert(e); }
        else g[e];
      }
    }
    unordered_set<string> seen; vector<vector<string>> ans;
    for (auto& p : emailName) {
      string start=p.first; if (seen.count(start)) continue;
      vector<string> st; st.push_back(start); seen.insert(start);
      vector<string> bag;
      while (!st.empty()) {
        string e=st.back(); st.pop_back(); bag.push_back(e);
        for (auto& nei : g[e]) { if (seen.count(nei)) continue; seen.insert(nei); st.push_back(nei); }
      }
      sort(bag.begin(), bag.end());
      vector<string> row; row.push_back(emailName[start]);
      row.insert(row.end(), bag.begin(), bag.end());
      ans.push_back(row);
    }
    return ans;
  }
};


// Method 3: More optimal
// Time: O(n · m log m) | Space: O(n · m)
// Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

class Solution {
  unordered_map<string,string> parent;
  string find(string x) {
    if (!parent.count(x)) parent[x]=x;
    while (parent[x]!=x) { parent[x]=parent[parent[x]]; x=parent[x]; }
    return x;
  }
  void unite(string a, string b) {
    string x=find(a), y=find(b);
    if (x!=y) parent[y]=x;
  }
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string,string> emailName;
    for (auto& acc : accounts) {
      string name=acc[0], first=acc[1];
      for (int j=1;j<(int)acc.size();j++) { emailName[acc[j]]=name; unite(first, acc[j]); }
    }
    unordered_map<string, vector<string>> groups;
    for (auto& p : emailName) groups[find(p.first)].push_back(p.first);
    vector<vector<string>> ans;
    for (auto& p : groups) {
      auto list=p.second; sort(list.begin(), list.end());
      vector<string> row; row.push_back(emailName[p.first]);
      row.insert(row.end(), list.begin(), list.end());
      ans.push_back(row);
    }
    return ans;
  }
};
