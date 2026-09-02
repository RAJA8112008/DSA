// Method 1: Brute
// Time: O(n + u · k) | Space: O(u)
// Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> count;
    for (int x : nums) count[x]++;
    vector<int> ans;
    for (int t = 0; t < k; t++) {
      int bestKey = 0, best = -1;
      for (auto& p : count) if (p.second > best) { best = p.second; bestKey = p.first; }
      ans.push_back(bestKey);
      count.erase(bestKey);
    }
    return ans;
  }
};


// Method 2: Optimal
// Time: O(n + u log u) | Space: O(u)
// Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> count;
    for (int x : nums) count[x]++;
    vector<int> keys;
    for (auto& p : count) keys.push_back(p.first);
    sort(keys.begin(), keys.end(), [&](int a, int b){ return count[a] > count[b]; });
    keys.resize(k);
    return keys;
  }
};


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> count;
    for (int x : nums) count[x]++;
    vector<vector<int>> buckets(nums.size() + 1);
    for (auto& p : count) buckets[p.second].push_back(p.first);
    vector<int> ans;
    for (int f = (int)buckets.size() - 1; f >= 0 && (int)ans.size() < k; f--) {
      for (int x : buckets[f]) {
        if ((int)ans.size() >= k) break;
        ans.push_back(x);
      }
    }
    return ans;
  }
};
