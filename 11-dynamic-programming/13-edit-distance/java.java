// Method 1: Brute
// Time: O(3^{m+n}) | Space: O(m + n)
// Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

class Solution {
    public int minDistance(String word1, String word2) {
        return go(word1, word2, 0, 0);
    }
    private int go(String word1, String word2, int i, int j) {
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;
        if (word1.charAt(i) == word2.charAt(j)) return go(word1, word2, i + 1, j + 1);
        int insert = 1 + go(word1, word2, i, j + 1);
        int del = 1 + go(word1, word2, i + 1, j);
        int replace = 1 + go(word1, word2, i + 1, j + 1);
        return Math.min(insert, Math.min(del, replace));
    }
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[m][n];
    }
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[] prev = new int[n + 1];
        for (int j = 0; j <= n; j++) prev[j] = j;
        for (int i = 1; i <= m; i++) {
            int[] cur = new int[n + 1];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) cur[j] = prev[j - 1];
                else cur[j] = 1 + Math.min(prev[j], Math.min(cur[j - 1], prev[j - 1]));
            }
            prev = cur;
        }
        return prev[n];
    }
}
