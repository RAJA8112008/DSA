// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every start and end pair is summed. Fine to explain, too slow for large n.
// How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

function subarraySum(nums, k) {
  let count = 0;
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    let sum = 0;
    for (let j = i; j < n; j++) {
      sum += nums[j];
      if (sum === k) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build all prefixes, then query a map. Two linear passes, O(n) extra.
// How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

function subarraySum(nums, k) {
  const n = nums.length;
  const prefix = new Array(n + 1);
  prefix[0] = 0;
  for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
  const freq = new Map();
  let count = 0;
  for (let i = 0; i <= n; i++) {
    const need = prefix[i] - k;
    if (freq.has(need)) count += freq.get(need);
    freq.set(prefix[i], (freq.get(prefix[i]) || 0) + 1);
  }
  return count;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same map idea without a prefix array. One running sum.
// How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

function subarraySum(nums, k) {
  const freq = new Map();
  freq.set(0, 1);
  let sum = 0;
  let count = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    const need = sum - k;
    if (freq.has(need)) count += freq.get(need);
    freq.set(sum, (freq.get(sum) || 0) + 1);
  }
  return count;
}
