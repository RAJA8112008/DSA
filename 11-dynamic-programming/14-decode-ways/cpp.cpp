// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each position may branch into a 1-digit take and a 2-digit take. Overlapping suffixes are recomputed. Zeros prune some branches but the worst case is still exponential.

int decGo(const string& s, int i) {
    if (i == (int)s.size()) return 1;
    if (s[i] == '0') return 0;
    int ways = decGo(s, i + 1);
    if (i + 1 < (int)s.size()) {
        int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (two >= 10 && two <= 26) ways += decGo(s, i + 2);
    }
    return ways;
}
int numDecodings(string s) {
    return decGo(s, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each start index is solved once. Work per index is O(1) digit checks. Memo of n cells plus the call stack. Linear in the length of s.

int decGo(const string& s, int i, vector<int>& memo) {
    if (i == (int)s.size()) return 1;
    if (s[i] == '0') return 0;
    if (memo[i] != -1) return memo[i];
    int ways = decGo(s, i + 1, memo);
    if (i + 1 < (int)s.size()) {
        int two = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (two >= 10 && two <= 26) ways += decGo(s, i + 2, memo);
    }
    memo[i] = ways;
    return ways;
}
int numDecodings(string s) {
    vector<int> memo(s.size(), -1);
    return decGo(s, 0, memo);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// prev1 is ways for the prefix ending here, prev2 is ways for the prefix one shorter. A one-digit code adds prev1. A two-digit code adds prev2. Empty string and a leading zero are the bases. No array.

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;
    int prev2 = 1, prev1 = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        int cur = 0;
        if (s[i] != '0') cur += prev1;
        int two = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (two >= 10 && two <= 26) cur += prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
