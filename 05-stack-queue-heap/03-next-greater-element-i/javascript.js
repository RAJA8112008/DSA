// Method 1: Brute
// Time: O(n · m) | Space: O(1)
// For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

function nextGreaterElement(nums1, nums2) {
  const ans = [];
  for (let i = 0; i < nums1.length; i++) {
    let found = false;
    let next = -1;
    for (let j = 0; j < nums2.length; j++) {
      if (!found) {
        if (nums2[j] === nums1[i]) found = true;
        continue;
      }
      if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
    }
    ans.push(next);
  }
  return ans;
}


// Method 2: Optimal
// Time: O(n · m) | Space: O(m)
// Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

function nextGreaterElement(nums1, nums2) {
  const idx = {};
  for (let i = 0; i < nums2.length; i++) idx[nums2[i]] = i;
  const ans = [];
  for (let i = 0; i < nums1.length; i++) {
    let next = -1;
    for (let j = idx[nums1[i]] + 1; j < nums2.length; j++) {
      if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
    }
    ans.push(next);
  }
  return ans;
}


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

function nextGreaterElement(nums1, nums2) {
  const next = {};
  const st = [];
  for (let i = 0; i < nums2.length; i++) {
    while (st.length && st[st.length - 1] < nums2[i]) next[st.pop()] = nums2[i];
    st.push(nums2[i]);
  }
  const ans = [];
  for (let i = 0; i < nums1.length; i++) {
    ans.push(next[nums1[i]] === undefined ? -1 : next[nums1[i]]);
  }
  return ans;
}
