# Method 1: Brute
# Time: O(3^{m+n}) | Space: O(m + n)
# Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

def minDistance(word1, word2):
    def go(i, j):
        if i == len(word1):
            return len(word2) - j
        if j == len(word2):
            return len(word1) - i
        if word1[i] == word2[j]:
            return go(i + 1, j + 1)
        insert = 1 + go(i, j + 1)
        delete = 1 + go(i + 1, j)
        replace = 1 + go(i + 1, j + 1)
        return min(insert, delete, replace)
    return go(0, 0)


# Method 2: Optimal
# Time: O(m * n) | Space: O(m * n)
# dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    return dp[m][n]


# Method 3: More optimal
# Time: O(m * n) | Space: O(n)
# A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    prev = list(range(n + 1))
    for i in range(1, m + 1):
        cur = [0] * (n + 1)
        cur[0] = i
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                cur[j] = prev[j - 1]
            else:
                cur[j] = 1 + min(prev[j], cur[j - 1], prev[j - 1])
        prev = cur
    return prev[n]
