// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each position may branch into a 1-digit take and a 2-digit take. Overlapping suffixes are recomputed. Zeros prune some branches but the worst case is still exponential.

int decGo(const char *s, int i) {
    int ways, two;
    if (s[i] == 0) return 1;
    if (s[i] == '0') return 0;
    ways = decGo(s, i + 1);
    if (s[i + 1] != 0) {
        two = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (two >= 10 && two <= 26) ways += decGo(s, i + 2);
    }
    return ways;
}
int numDecodings(const char *s) {
    return decGo(s, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each start index is solved once. Work per index is O(1) digit checks. Memo of n cells plus the call stack. Linear in the length of s.

int decGo(const char *s, int i, int *memo) {
    int ways, two;
    if (s[i] == 0) return 1;
    if (s[i] == '0') return 0;
    if (memo[i] != -1) return memo[i];
    ways = decGo(s, i + 1, memo);
    if (s[i + 1] != 0) {
        two = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (two >= 10 && two <= 26) ways += decGo(s, i + 2, memo);
    }
    memo[i] = ways;
    return ways;
}
int numDecodings(const char *s) {
    int n = (int)strlen(s);
    int *memo = (int *)malloc(n * sizeof(int));
    int i, ans;
    for (i = 0; i < n; i++) memo[i] = -1;
    ans = decGo(s, 0, memo);
    free(memo);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// prev1 is ways for the prefix ending here, prev2 is ways for the prefix one shorter. A one-digit code adds prev1. A two-digit code adds prev2. Empty string and a leading zero are the bases. No array.

int numDecodings(const char *s) {
    int n = (int)strlen(s);
    int prev2, prev1, i, cur, two;
    if (n == 0 || s[0] == '0') return 0;
    prev2 = 1;
    prev1 = 1;
    for (i = 1; i < n; i++) {
        cur = 0;
        if (s[i] != '0') cur += prev1;
        two = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two >= 10 && two <= 26) cur += prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
