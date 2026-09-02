// Method 1: Brute
// Time: O(n²) | Space: O(n)
// From each unique start you may scan the set repeatedly. In the worst case this is quadratic.
// How it works: put numbers in a Set. For each start, count start, start+1, start+2 while those values exist. Keep the longest streak.

function longestConsecutive(nums) {
  const set = new Set(nums);
  let best = 0;
  for (const x of set) {
    let len = 1;
    let cur = x;
    while (set.has(cur + 1)) {
      cur++;
      len++;
    }
    if (len > best) best = len;
  }
  return best;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Unique copy plus sort, then a linear neighbor walk. Sorting is the bottleneck.
// How it works: skip duplicates while scanning the sorted unique list. A gap of 1 grows the streak; a larger gap resets it.

function longestConsecutive(nums) {
  if (nums.length === 0) return 0;
  const list = Array.from(new Set(nums));
  list.sort(function (a, b) { return a - b; });
  let best = 1;
  let streak = 1;
  for (let i = 1; i < list.length; i++) {
    if (list[i] === list[i - 1] + 1) {
      streak++;
      if (streak > best) best = streak;
    } else {
      streak = 1;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each number is inserted once and then used in at most one forward walk.
// How it works: only start a streak when x-1 is missing. Then count x, x+1, ... while present. That visits each run from its true beginning.

function longestConsecutive(nums) {
  const set = new Set(nums);
  let best = 0;
  for (const x of set) {
    if (set.has(x - 1)) continue;
    let len = 1;
    let cur = x;
    while (set.has(cur + 1)) {
      cur++;
      len++;
    }
    if (len > best) best = len;
  }
  return best;
}
