// Method 1: Brute
// Time: set O(1), get O(n) | Space: O(n)
// Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

function TimeMap() {
  this.map = {};
}
TimeMap.prototype.set = function (key, value, timestamp) {
  if (!this.map[key]) this.map[key] = [];
  this.map[key].push([timestamp, value]);
};
TimeMap.prototype.get = function (key, timestamp) {
  const arr = this.map[key];
  if (!arr) return "";
  let ans = "";
  for (let i = 0; i < arr.length; i++) {
    if (arr[i][0] <= timestamp) ans = arr[i][1];
  }
  return ans;
};


// Method 2: Optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

function TimeMap() {
  this.map = {};
}
TimeMap.prototype.set = function (key, value, timestamp) {
  if (!this.map[key]) this.map[key] = [];
  this.map[key].push([timestamp, value]);
};
TimeMap.prototype.get = function (key, timestamp) {
  const arr = this.map[key];
  if (!arr) return "";
  let lo = 0, hi = arr.length - 1, ans = "";
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (arr[mid][0] <= timestamp) {
      ans = arr[mid][1];
      lo = mid + 1;
    } else hi = mid - 1;
  }
  return ans;
};


// Method 3: More optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

function TimeMap() {
  this.map = {};
}
TimeMap.prototype.set = function (key, value, timestamp) {
  if (!this.map[key]) this.map[key] = [];
  this.map[key].push([timestamp, value]);
};
TimeMap.prototype.get = function (key, timestamp) {
  const arr = this.map[key];
  if (!arr) return "";
  let lo = 0, hi = arr.length;
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (arr[mid][0] <= timestamp) lo = mid + 1;
    else hi = mid;
  }
  return lo === 0 ? "" : arr[lo - 1][1];
};
