# Method 1: Brute
# Time: O(n³) | Space: O(1)
# O(n²) slices, each palindrome test is O(n).
# How it works: try longer slices first so the first hit is a longest palindrome. isPalin uses two pointers on s[left..right].

def longest_palindrome(s):
    def is_palin(left, right):
        while left < right:
            if s[left] != s[right]: return False
            left += 1
            right -= 1
        return True
    n = len(s)
    for length in range(n, (1) - 1, -1):

        i = 0
        while i + length - 1 < n:

            if is_palin(i, i + length - 1): return s[i:i + length]

            i += 1

    return ""


# Method 2: Optimal
# Time: O(n²) | Space: O(1)
# 2n-1 expansions, each O(n) in the worst case. Extra memory is a few indexes.
# How it works: expand(i,i) covers odd length, expand(i,i+1) covers even. Keep the longest slice.

def longest_palindrome(s):
    bestL = 0
    bestR = 0
    def expand(left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if right - left > bestR - bestL:
                bestL = left
                bestR = right
            left -= 1
            right += 1
    for i in range(len(s)):

        expand(i, i)
        expand(i, i + 1)

    return s[bestL:bestR + 1]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Manacher: a transformed string with separators, plus a radius array of length 2n+3. Each side is expanded only past the known right bound.
# How it works: t = ^#s#s#$ so even and odd palindromes look the same. p[i] is the radius. Mirror across center when i is inside right. Original start is (center - radius) / 2 on the # string.

def longest_palindrome(s):
    if len(s) < 2: return s
    t = ["^"]
    for i in range(len(s)):

        t.append("#")
        t.append(s[i])

    t.append("#")
    t.append("$")
    n = len(t)
    p = [0] * n
    center = 0
    right = 0
    bestC = 0
    bestLen = 0
    for i in range(1, n - 1):

        mirror = 2 * center - i
        if i < right: p[i] = min(right - i, p[mirror])
        while t[i + 1 + p[i]] == t[i - 1 - p[i]]: p[i]++
        if i + p[i] > right:
            center = i
            right = i + p[i]
        if p[i] > bestLen:
            bestLen = p[i]
            bestC = i

    start = ((bestC - bestLen) ) # 2
    return s[start:start + bestLen]
