// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        return go(text1, text2, 0, 0);
    }
    private int go(String text1, String text2, int i, int j) {
        if (i == text1.length() || j == text2.length()) return 0;
        if (text1.charAt(i) == text2.charAt(j)) return 1 + go(text1, text2, i + 1, j + 1);
        return Math.max(go(text1, text2, i + 1, j), go(text1, text2, i, j + 1));
    }
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(min(m, n))
// A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        if (text1.length() < text2.length()) {
            String tmp = text1;
            text1 = text2;
            text2 = tmp;
        }
        int n = text2.length();
        int[] prev = new int[n + 1];
        for (int i = 1; i <= text1.length(); i++) {
            int[] cur = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) cur[j] = prev[j - 1] + 1;
                else cur[j] = Math.max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[n];
    }
}
