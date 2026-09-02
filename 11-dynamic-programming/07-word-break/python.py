# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

def wordBreak(s, wordDict):
    def go(i):
        if i == len(s):
            return True
        for word in wordDict:
            if s.startswith(word, i) and go(i + len(word)):
                return True
        return False
    return go(0)


# Method 2: Optimal
# Time: O(n * m * L) | Space: O(n)
# Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

def wordBreak(s, wordDict):
    memo = {}
    def go(i):
        if i == len(s):
            return True
        if i in memo:
            return memo[i]
        for word in wordDict:
            if s.startswith(word, i) and go(i + len(word)):
                memo[i] = True
                return True
        memo[i] = False
        return False
    return go(0)


# Method 3: More optimal
# Time: O(n * m * L) | Space: O(n + m)
# Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

def wordBreak(s, wordDict):
    words = set(wordDict)
    n = len(s)
    can = [False] * (n + 1)
    can[0] = True
    for i in range(n):
        if not can[i]:
            continue
        for word in words:
            if s.startswith(word, i):
                can[i + len(word)] = True
    return can[n]
