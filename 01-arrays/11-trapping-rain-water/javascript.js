// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For every index you walk the whole left side and the whole right side.
// How it works: water at i is max(0, min(leftMax, rightMax) - height[i]). Sum those amounts.

function trap(height) {
  const n = height.length;
  let total = 0;
  for (let i = 0; i < n; i++) {
    let leftMax = 0;
    let rightMax = 0;
    for (let L = 0; L <= i; L++) leftMax = Math.max(leftMax, height[L]);
    for (let R = i; R < n; R++) rightMax = Math.max(rightMax, height[R]);
    total += Math.min(leftMax, rightMax) - height[i];
  }
  return total;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three linear passes. Two extra arrays of length n.
// How it works: leftMax[i] is the tallest bar at or left of i. rightMax[i] is the tallest at or right of i. Water at i uses those two stored values.

function trap(height) {
  const n = height.length;
  if (n === 0) return 0;
  const leftMax = new Array(n);
  const rightMax = new Array(n);
  leftMax[0] = height[0];
  for (let i = 1; i < n; i++) leftMax[i] = Math.max(leftMax[i - 1], height[i]);
  rightMax[n - 1] = height[n - 1];
  for (let i = n - 2; i >= 0; i--) rightMax[i] = Math.max(rightMax[i + 1], height[i]);
  let total = 0;
  for (let i = 0; i < n; i++) {
    total += Math.min(leftMax[i], rightMax[i]) - height[i];
  }
  return total;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass from both ends. Only a handful of integers besides the input.
// How it works: the side with the smaller max is the bottleneck. Add water there, then move that pointer and update that max. The other side is at least as tall, so it can hold this water.

function trap(height) {
  let left = 0;
  let right = height.length - 1;
  let leftMax = 0;
  let rightMax = 0;
  let total = 0;
  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) leftMax = height[left];
      else total += leftMax - height[left];
      left++;
    } else {
      if (height[right] >= rightMax) rightMax = height[right];
      else total += rightMax - height[right];
      right--;
    }
  }
  return total;
}
