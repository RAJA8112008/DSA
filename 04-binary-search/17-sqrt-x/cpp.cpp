// Method 1: Brute
// Time: O(sqrt(x)) | Space: O(1)
// Increase r while (r+1)*(r+1) still fits in x. Use 64-bit (or a division check) so r*r does not overflow 32-bit int.

class Solution {
public:
  int mySqrt(int x) {
    long long r = 0;
    while ((r + 1) * (r + 1) <= x) r++;
    return (int)r;
  }
};


// Method 2: Optimal
// Time: O(log x) | Space: O(1)
// Last-true search: mid is good when mid <= x / mid (avoids mid*mid overflow). If good, try a larger r. If not, shrink high. x in {0,1} returns x.

class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) return x;
    int lo = 1, hi = x, ans = 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (mid <= x / mid) { ans = mid; lo = mid + 1; }
      else hi = mid - 1;
    }
    return ans;
  }
};


// Method 3: More optimal
// Time: O(log x) | Space: O(1)
// Integer Newton: r = (r + x/r) / 2 until r <= x/r. Overflow-safe. Usually fewer loops than binary search. Still exact for the floor sqrt.

class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) return x;
    long long r = x;
    while (r > x / r) r = (r + x / r) / 2;
    return (int)r;
  }
};
