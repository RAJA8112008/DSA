// Method 1: Brute
// Time: O(n + u · k) | Space: O(u)
// Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

function topKFrequent(nums, k) {
  const count = {};
  for (let i = 0; i < nums.length; i++) count[nums[i]] = (count[nums[i]] || 0) + 1;
  const ans = [];
  for (let t = 0; t < k; t++) {
    let bestKey = null, best = -1;
    const keys = Object.keys(count);
    for (let i = 0; i < keys.length; i++) {
      const key = keys[i];
      if (count[key] > best) { best = count[key]; bestKey = key; }
    }
    ans.push(Number(bestKey));
    delete count[bestKey];
  }
  return ans;
}


// Method 2: Optimal
// Time: O(n + u log u) | Space: O(u)
// Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

function topKFrequent(nums, k) {
  const count = {};
  for (let i = 0; i < nums.length; i++) count[nums[i]] = (count[nums[i]] || 0) + 1;
  const keys = Object.keys(count).map(Number);
  keys.sort(function (a, b) { return count[b] - count[a]; });
  return keys.slice(0, k);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

function topKFrequent(nums, k) {
  const count = {};
  for (let i = 0; i < nums.length; i++) count[nums[i]] = (count[nums[i]] || 0) + 1;
  const buckets = Array.from({ length: nums.length + 1 }, function () { return []; });
  const keys = Object.keys(count);
  for (let i = 0; i < keys.length; i++) {
    const num = Number(keys[i]);
    buckets[count[num]].push(num);
  }
  const ans = [];
  for (let f = buckets.length - 1; f >= 0 && ans.length < k; f--) {
    for (let i = 0; i < buckets[f].length && ans.length < k; i++) ans.push(buckets[f][i]);
  }
  return ans;
}
