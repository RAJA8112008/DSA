// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

int lcsGo(const string& text1, const string& text2, int i, int j) {
    if (i == (int)text1.size() || j == (int)text2.size()) return 0;
    if (text1[i] == text2[j]) return 1 + lcsGo(text1, text2, i + 1, j + 1);
    return max(lcsGo(text1, text2, i + 1, j), lcsGo(text1, text2, i, j + 1));
}
int longestCommonSubsequence(string text1, string text2) {
    return lcsGo(text1, text2, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(min(m, n))
// A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

int longestCommonSubsequence(string text1, string text2) {
    if (text1.size() < text2.size()) swap(text1, text2);
    int n = text2.size();
    vector<int> prev(n + 1, 0);
    for (int i = 1; i <= (int)text1.size(); i++) {
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) cur[j] = prev[j - 1] + 1;
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev.swap(cur);
    }
    return prev[n];
}
