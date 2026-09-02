// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) ranges, each palindrome test O(n).
// How it works: for every i..j, two-pointer check. Increment count when it is a palindrome.

function countSubstrings(s) {
  function isPalin(left, right) {
    while (left < right) {
      if (s[left] !== s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  let count = 0;
  const n = s.length;
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      if (isPalin(i, j)) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// A boolean table of n by n. Each cell is O(1) after shorter lengths are known.
// How it works: pal[i][j] is true if s[i]===s[j] and the inside is a palindrome (or the length is 1 or 2). Count every true cell.

function countSubstrings(s) {
  const n = s.length;
  const pal = [];
  for (let i = 0; i < n; i++) pal.push(new Array(n).fill(false));
  let count = 0;
  for (let i = n - 1; i >= 0; i--) {
    for (let j = i; j < n; j++) {
      if (s[i] === s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
        pal[i][j] = true;
        count++;
      }
    }
  }
  return count;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Same time, constant extra memory. Each palindrome is grown from a center.
// How it works: expand(left,right) counts while the letters match. Call expand(i,i) and expand(i,i+1) for every i.

function countSubstrings(s) {
  let count = 0;
  function expand(left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      count++;
      left--;
      right++;
    }
  }
  for (let i = 0; i < s.length; i++) {
    expand(i, i);
    expand(i, i + 1);
  }
  return count;
}
