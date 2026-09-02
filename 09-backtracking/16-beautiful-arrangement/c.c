// Method 1: Brute
// Time: O(n * n!) | Space: O(n)
// Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

int ok(int* perm, int n) {
  int i;
  for (i = 1; i <= n; i++) if (perm[i - 1] % i && i % perm[i - 1]) return 0;
  return 1;
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n)
// At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

void go(int n, int pos, int* used, int* count) {
  int num;
  if (pos > n) { (*count)++; return; }
  for (num = 1; num <= n; num++) {
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

int goMask(int n, int mask, int* memo) {
  int pos = 1, m = mask, num, ways;
  while (m) { m &= m - 1; pos++; }
  if (pos > n) return 1;
  if (memo[mask] != -1) return memo[mask];
  ways = 0;
  for (num = 1; num <= n; num++) {
    if (mask & (1 << (num - 1))) continue;
    if (num % pos && pos % num) continue;
    ways += goMask(n, mask | (1 << (num - 1)), memo);
  }
  memo[mask] = ways;
  return ways;
}
