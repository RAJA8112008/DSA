// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

function permute(nums) {
  const ans = [];
  function go(left, path) {
    if (left.length === 0) {
      ans.push(path);
      return;
    }
    for (let i = 0; i < left.length; i++) {
      const nextLeft = left.slice(0, i).concat(left.slice(i + 1));
      const nextPath = path.slice();
      nextPath.push(left[i]);
      go(nextLeft, nextPath);
    }
  }
  go(nums.slice(), []);
  return ans;
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

function permute(nums) {
  const ans = [];
  const used = Array(nums.length).fill(false);
  function go(path) {
    if (path.length === nums.length) {
      ans.push(path.slice());
      return;
    }
    for (let j = 0; j < nums.length; j++) {
      if (used[j]) continue;
      used[j] = true;
      path.push(nums[j]);
      go(path);
      path.pop();
      used[j] = false;
    }
  }
  go([]);
  return ans;
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

function permute(nums) {
  const ans = [];
  function go(start) {
    if (start === nums.length) {
      ans.push(nums.slice());
      return;
    }
    for (let i = start; i < nums.length; i++) {
      const tmp = nums[start]; nums[start] = nums[i]; nums[i] = tmp;
      go(start + 1);
      const tmp2 = nums[start]; nums[start] = nums[i]; nums[i] = tmp2;
    }
  }
  go(0);
  return ans;
}
