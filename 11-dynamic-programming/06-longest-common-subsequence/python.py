# Method 1: Brute
# Time: O(2^{m+n}) | Space: O(m + n)
# Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

def longestCommonSubsequence(text1, text2):
    def go(i, j):
        if i == len(text1) or j == len(text2):
            return 0
        if text1[i] == text2[j]:
            return 1 + go(i + 1, j + 1)
        return max(go(i + 1, j), go(i, j + 1))
    return go(0, 0)


# Method 2: Optimal
# Time: O(m * n) | Space: O(m * n)
# One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

def longestCommonSubsequence(text1, text2):
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[m][n]


# Method 3: More optimal
# Time: O(m * n) | Space: O(min(m, n))
# A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

def longestCommonSubsequence(text1, text2):
    if len(text1) < len(text2):
        text1, text2 = text2, text1
    n = len(text2)
    prev = [0] * (n + 1)
    for i in range(1, len(text1) + 1):
        cur = [0] * (n + 1)
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                cur[j] = prev[j - 1] + 1
            else:
                cur[j] = max(prev[j], cur[j - 1])
        prev = cur
    return prev[n]
