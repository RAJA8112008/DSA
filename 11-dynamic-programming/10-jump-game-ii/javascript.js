// Method 1: Brute
// Time: O(n^n) | Space: O(n)
// From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

function jump(nums) {
  function go(i) {
    if (i >= nums.length - 1) return 0;
    let best = Infinity;
    for (let step = 1; step <= nums[i]; step++) {
      best = Math.min(best, 1 + go(i + step));
    }
    return best;
  }
  return go(0);
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

function jump(nums) {
  const n = nums.length;
  const best = Array(n).fill(Infinity);
  best[0] = 0;
  for (let i = 0; i < n; i++) {
    for (let step = 1; step <= nums[i] && i + step < n; step++) {
      best[i + step] = Math.min(best[i + step], best[i] + 1);
    }
  }
  return best[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

function jump(nums) {
  let jumps = 0;
  let end = 0;
  let farthest = 0;
  for (let i = 0; i < nums.length - 1; i++) {
    farthest = Math.max(farthest, i + nums[i]);
    if (i === end) {
      jumps += 1;
      end = farthest;
    }
  }
  return jumps;
}
