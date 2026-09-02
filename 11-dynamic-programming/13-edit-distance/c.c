// Method 1: Brute
// Time: O(3^{m+n}) | Space: O(m + n)
// Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

int distGo(const char *word1, const char *word2, int i, int j) {
    int insert, del, replace, m;
    if (word1[i] == 0) return (int)strlen(word2 + j);
    if (word2[j] == 0) return (int)strlen(word1 + i);
    if (word1[i] == word2[j]) return distGo(word1, word2, i + 1, j + 1);
    insert = 1 + distGo(word1, word2, i, j + 1);
    del = 1 + distGo(word1, word2, i + 1, j);
    replace = 1 + distGo(word1, word2, i + 1, j + 1);
    m = insert < del ? insert : del;
    return m < replace ? m : replace;
}
int minDistance(const char *word1, const char *word2) {
    return distGo(word1, word2, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

int minDistance(const char *word1, const char *word2) {
    int m = (int)strlen(word1), n = (int)strlen(word2);
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    int i, j, ans, t;
    for (i = 0; i <= m; i++) dp[i] = (int *)calloc(n + 1, sizeof(int));
    for (i = 0; i <= m; i++) dp[i][0] = i;
    for (j = 0; j <= n; j++) dp[0][j] = j;
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                t = dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                if (dp[i - 1][j - 1] < t) t = dp[i - 1][j - 1];
                dp[i][j] = 1 + t;
            }
        }
    }
    ans = dp[m][n];
    for (i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return ans;
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

int minDistance(const char *word1, const char *word2) {
    int m = (int)strlen(word1), n = (int)strlen(word2);
    int *prev = (int *)malloc((n + 1) * sizeof(int));
    int i, j, t, ans;
    for (j = 0; j <= n; j++) prev[j] = j;
    for (i = 1; i <= m; i++) {
        int *cur = (int *)malloc((n + 1) * sizeof(int));
        cur[0] = i;
        for (j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) cur[j] = prev[j - 1];
            else {
                t = prev[j] < cur[j - 1] ? prev[j] : cur[j - 1];
                if (prev[j - 1] < t) t = prev[j - 1];
                cur[j] = 1 + t;
            }
        }
        free(prev);
        prev = cur;
    }
    ans = prev[n];
    free(prev);
    return ans;
}
