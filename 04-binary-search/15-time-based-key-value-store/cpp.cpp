// Method 1: Brute
// Time: set O(1), get O(n) | Space: O(n)
// Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

class TimeMap {
  unordered_map<string, vector<pair<int,string>>> mp;
public:
  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }
  string get(string key, int timestamp) {
    auto it = mp.find(key);
    if (it == mp.end()) return "";
    string ans;
    for (auto& p : it->second) if (p.first <= timestamp) ans = p.second;
    return ans;
  }
};


// Method 2: Optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

class TimeMap {
  unordered_map<string, vector<pair<int,string>>> mp;
public:
  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }
  string get(string key, int timestamp) {
    auto it = mp.find(key);
    if (it == mp.end()) return "";
    auto& arr = it->second;
    int lo = 0, hi = (int)arr.size() - 1;
    string ans;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (arr[mid].first <= timestamp) { ans = arr[mid].second; lo = mid + 1; }
      else hi = mid - 1;
    }
    return ans;
  }
};


// Method 3: More optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

class TimeMap {
  unordered_map<string, vector<pair<int,string>>> mp;
public:
  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }
  string get(string key, int timestamp) {
    auto it = mp.find(key);
    if (it == mp.end()) return "";
    auto& arr = it->second;
    int lo = 0, hi = (int)arr.size();
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (arr[mid].first <= timestamp) lo = mid + 1;
      else hi = mid;
    }
    return lo == 0 ? "" : arr[lo - 1].second;
  }
};
