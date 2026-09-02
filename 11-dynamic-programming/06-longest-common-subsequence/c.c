// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

int lcsGo(const char *text1, const char *text2, int i, int j) {
    if (text1[i] == 0 || text2[j] == 0) return 0;
    if (text1[i] == text2[j]) return 1 + lcsGo(text1, text2, i + 1, j + 1);
    int a = lcsGo(text1, text2, i + 1, j);
    int b = lcsGo(text1, text2, i, j + 1);
    return a > b ? a : b;
}
int longestCommonSubsequence(const char *text1, const char *text2) {
    return lcsGo(text1, text2, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

int longestCommonSubsequence(const char *text1, const char *text2) {
    int m = (int)strlen(text1), n = (int)strlen(text2);
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    int i, j, ans;
    for (i = 0; i <= m; i++) dp[i] = (int *)calloc(n + 1, sizeof(int));
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    ans = dp[m][n];
    for (i = 0; i <= m; i++) free(dp[i]);
    free(dp);
    return ans;
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(min(m, n))
// A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

int longestCommonSubsequence(const char *text1, const char *text2) {
    int m = (int)strlen(text1), n = (int)strlen(text2);
    const char *a = text1, *b = text2;
    int *prev, *cur, i, j, t, ans;
    if (m < n) { a = text2; b = text1; t = m; m = n; n = t; }
    prev = (int *)calloc(n + 1, sizeof(int));
    for (i = 1; i <= m; i++) {
        cur = (int *)calloc(n + 1, sizeof(int));
        for (j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) cur[j] = prev[j - 1] + 1;
            else cur[j] = prev[j] > cur[j - 1] ? prev[j] : cur[j - 1];
        }
        free(prev);
        prev = cur;
    }
    ans = prev[n];
    free(prev);
    return ans;
}
