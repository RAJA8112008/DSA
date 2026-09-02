// Method 1: Brute
// Time: O(3^{m+n}) | Space: O(m + n)
// Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

int distGo(const string& word1, const string& word2, int i, int j) {
    if (i == (int)word1.size()) return (int)word2.size() - j;
    if (j == (int)word2.size()) return (int)word1.size() - i;
    if (word1[i] == word2[j]) return distGo(word1, word2, i + 1, j + 1);
    int insert = 1 + distGo(word1, word2, i, j + 1);
    int del = 1 + distGo(word1, word2, i + 1, j);
    int replace = 1 + distGo(word1, word2, i + 1, j + 1);
    return min(insert, min(del, replace));
}
int minDistance(string word1, string word2) {
    return distGo(word1, word2, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[m][n];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> prev(n + 1);
    for (int j = 0; j <= n; j++) prev[j] = j;
    for (int i = 1; i <= m; i++) {
        vector<int> cur(n + 1);
        cur[0] = i;
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) cur[j] = prev[j - 1];
            else cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
        }
        prev.swap(cur);
    }
    return prev[n];
}
