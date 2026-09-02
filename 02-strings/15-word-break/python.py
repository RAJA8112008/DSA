# Method 1: Brute
# Time: O(2ⁿ) | Space: O(n)
# Each position may start many words. Overlapping failures are recomputed. Stack depth is O(n).
# How it works: dfs(i) is true if i is the end, or some wordDict entry matches s starting at i and dfs continues after it.

def word_break(s, wordDict):
    def dfs(i):
        if i == len(s): return True
        for w in range(len(wordDict)):

            word = wordDict[w]
            if s[i:i + len(word)] == word and dfs(i + len(word)): return True

        return False
    return dfs(0)


# Method 2: Optimal
# Time: O(n² · k) | Space: O(n)
# ok[i] loops previous starts and slices. k is cost of string compare / slice.
# How it works: ok[0] = true. ok[j] is true if some i < j has ok[i] and s.slice(i,j) is in the dictionary Set.

def word_break(s, wordDict):
    words = set(wordDict)
    n = len(s)
    ok = [None] * (n + 1).fill(False)
    ok[0] = True
    for j in range(1, = n):

        for i in range(j):

            if ok[i] and s[i:j] in words:
                ok[j] = True
                break

    return ok[n]


# Method 3: More optimal
# Time: O(n · L) | Space: O(n)
# From each true index i, only try lengths 1..longest word, not every j. L is that max length times slice cost, still typically much less than n for each i.
# How it works: same ok array. If ok[i], try each length up to longest. If the slice is a word, mark ok[i+len].

def word_break(s, wordDict):
    words = set(wordDict)
    longest = 0
    for w in range(len(wordDict)):

        if wordDict[w].length > longest: longest = wordDict[w].length

    n = len(s)
    ok = [None] * (n + 1).fill(False)
    ok[0] = True
    for i in range(n):

        if not ok[i]: continue
        for length in range(1, = longest and i + length <= n):

            if s[i:i + length] in words: ok[i + length] = True

    return ok[n]
