// Method 1: Brute
// Time: O(n · m) | Space: O(1)
// For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for (int x : nums1) {
      bool found = false;
      int next = -1;
      for (int y : nums2) {
        if (!found) { if (y == x) found = true; continue; }
        if (y > x) { next = y; break; }
      }
      ans.push_back(next);
    }
    return ans;
  }
};


// Method 2: Optimal
// Time: O(n · m) | Space: O(m)
// Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> idx;
    for (int i = 0; i < (int)nums2.size(); i++) idx[nums2[i]] = i;
    vector<int> ans;
    for (int x : nums1) {
      int next = -1;
      for (int j = idx[x] + 1; j < (int)nums2.size(); j++) {
        if (nums2[j] > x) { next = nums2[j]; break; }
      }
      ans.push_back(next);
    }
    return ans;
  }
};


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> nxt;
    vector<int> st;
    for (int x : nums2) {
      while (!st.empty() && st.back() < x) { nxt[st.back()] = x; st.pop_back(); }
      st.push_back(x);
    }
    vector<int> ans;
    for (int x : nums1) ans.push_back(nxt.count(x) ? nxt[x] : -1);
    return ans;
  }
};
