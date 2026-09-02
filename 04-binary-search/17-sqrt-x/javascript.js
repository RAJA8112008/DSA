// Method 1: Brute
// Time: O(sqrt(x)) | Space: O(1)
// Increase r while (r+1)*(r+1) still fits in x. Use 64-bit (or a division check) so r*r does not overflow 32-bit int.

function mySqrt(x) {
  let r = 0;
  while ((r + 1) * (r + 1) <= x) r++;
  return r;
}


// Method 2: Optimal
// Time: O(log x) | Space: O(1)
// Last-true search: mid is good when mid <= x / mid (avoids mid*mid overflow). If good, try a larger r. If not, shrink high. x in {0,1} returns x.

function mySqrt(x) {
  if (x < 2) return x;
  let lo = 1, hi = x, ans = 1;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (mid <= Math.floor(x / mid)) {
      ans = mid;
      lo = mid + 1;
    } else hi = mid - 1;
  }
  return ans;
}


// Method 3: More optimal
// Time: O(log x) | Space: O(1)
// Integer Newton: r = (r + x/r) / 2 until r <= x/r. Overflow-safe. Usually fewer loops than binary search. Still exact for the floor sqrt.

function mySqrt(x) {
  if (x < 2) return x;
  let r = x;
  while (r > Math.floor(x / r)) {
    r = Math.floor((r + Math.floor(x / r)) / 2);
  }
  return r;
}
