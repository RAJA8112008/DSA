// Method 1: Brute
// Time: O(n²) | Space: O(n)
// For each i you multiply n - 1 others. That is n² multiplications.
// How it works: skip index i in the inner loop. Store the product in out[i].

function productExceptSelf(nums) {
  const n = nums.length;
  const out = new Array(n);
  for (let i = 0; i < n; i++) {
    let prod = 1;
    for (let j = 0; j < n; j++) {
      if (j !== i) prod *= nums[j];
    }
    out[i] = prod;
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three linear passes and two extra arrays of length n.
// How it works: left[i] is the product of items before i. right[i] is the product after i. out[i] = left[i] * right[i].

function productExceptSelf(nums) {
  const n = nums.length;
  const left = new Array(n);
  const right = new Array(n);
  const out = new Array(n);
  left[0] = 1;
  for (let i = 1; i < n; i++) left[i] = left[i - 1] * nums[i - 1];
  right[n - 1] = 1;
  for (let i = n - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i + 1];
  for (let i = 0; i < n; i++) out[i] = left[i] * right[i];
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory for the answer list, but no extra left/right arrays.
// How it works: fill out with prefix products. Then walk right to left with a running suffix product and multiply it in.

function productExceptSelf(nums) {
  const n = nums.length;
  const out = new Array(n);
  out[0] = 1;
  for (let i = 1; i < n; i++) out[i] = out[i - 1] * nums[i - 1];
  let right = 1;
  for (let i = n - 1; i >= 0; i--) {
    out[i] *= right;
    right *= nums[i];
  }
  return out;
}
