// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every start and end pair is summed. Fine to explain, too slow for large n.
// How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

// vector, unordered_map, string
int subarraySum(vector<int>& nums, int k) {
  int count = 0;
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum == k) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build all prefixes, then query a map. Two linear passes, O(n) extra.
// How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

// vector, unordered_map, string
int subarraySum(vector<int>& nums, int k) {
  int n = (int)nums.size();
  vector<int> prefix = vector<int>(n + 1);
  prefix[0] = 0;
  for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
  unordered_map<int,int> freq;
  int count = 0;
  for (int i = 0; i <= n; i++) {
    int need = prefix[i] - k;
    if (freq.count(need)) count += freq[need];
    freq[prefix[i]] = (freq.count(prefix[i] ? freq[prefix[i]] : 0) + 1);
  }
  return count;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same map idea without a prefix array. One running sum.
// How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

// vector, unordered_map, string
int subarraySum(vector<int>& nums, int k) {
  unordered_map<int,int> freq;
  freq[0] = 1;
  int sum = 0;
  int count = 0;
  for (int i = 0; i < (int)nums.size(); i++) {
    sum += nums[i];
    int need = sum - k;
    if (freq.count(need)) count += freq[need];
    freq[sum] = (freq.count(sum ? freq[sum] : 0) + 1);
  }
  return count;
}
