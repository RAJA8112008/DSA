// Method 1: Brute
// Time: O(n * n!) | Space: O(n)
// Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

bool ok(vector<int>& perm) {
  int n = (int)perm.size();
  for (int i = 1; i <= n; i++) if (perm[i - 1] % i && i % perm[i - 1]) return false;
  return true;
}
void go(vector<int> left, vector<int> perm, int& count) {
  if (left.empty()) { if (ok(perm)) count++; return; }
  for (int i = 0; i < (int)left.size(); i++) {
    vector<int> nextLeft = left, nextPerm = perm;
    nextPerm.push_back(nextLeft[i]);
    nextLeft.erase(nextLeft.begin() + i);
    go(nextLeft, nextPerm, count);
  }
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n)
// At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

void go(int n, int pos, vector<int>& used, int& count) {
  if (pos > n) { count++; return; }
  for (int num = 1; num <= n; num++) {
    if (used[num]) continue;
    if (num % pos && pos % num) continue;
    used[num] = 1;
    go(n, pos + 1, used, count);
    used[num] = 0;
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n * 2^n)
// n <= 15. mask bit (num-1) means num is used. pos = popcount(mask)+1. Memo[mask] caches how many ways finish from this used-set. Bitmask + prune + no leftover copies.

int go(int n, int mask, vector<int>& memo) {
  int pos = __builtin_popcount(mask) + 1;
  if (pos > n) return 1;
  if (memo[mask] != -1) return memo[mask];
  int ways = 0;
  for (int num = 1; num <= n; num++) {
    if (mask & (1 << (num - 1))) continue;
    if (num % pos && pos % num) continue;
    ways += go(n, mask | (1 << (num - 1)), memo);
  }
  return memo[mask] = ways;
}
int countArrangement(int n) {
  vector<int> memo(1 << n, -1);
  return go(n, 0, memo);
}
