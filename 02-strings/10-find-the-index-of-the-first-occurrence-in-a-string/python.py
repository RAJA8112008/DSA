# Method 1: Brute
# Time: O((n-m)·m) | Space: O(1)
# Every start position compares up to m characters.
# How it works: for each i, check whether haystack[i..i+m) equals needle. First hit wins.

def str_str(haystack, needle):
    n = len(haystack)
    m = len(needle)
    if m == 0: return 0
    i = 0
    while i + m <= n:

        ok = True
        for j in range(m):

            if haystack[i + j] != needle[j]: { ok = False break }

        if ok: return i

        i += 1
    return -1


# Method 2: Optimal
# Time: O((n-m)·m) | Space: O(1)
# Same worst-case bound, fewer inner steps when the first character already mismatches (slice avoided).
# How it works: skip starts whose first character is wrong, then compare the rest. Empty needle returns 0.

def str_str(haystack, needle):
    n = len(haystack)
    m = len(needle)
    if m == 0: return 0
    i = 0
    while i + m <= n:

        if haystack[i] != needle[0]: continue
        j = 1
        while j < m and haystack[i + j] == needle[j]: j += 1
        if j == m: return i

        i += 1
    return -1


# Method 3: More optimal
# Time: O(n + m) | Space: O(m)
# KMP: build lps of the needle in O(m), then scan haystack in O(n) without restarting from scratch on mismatch.
# How it works: lps[i] is the longest proper prefix of needle[0..i] that is also a suffix. On mismatch, j = lps[j-1] instead of j = 0 always.

def str_str(haystack, needle):
    n = len(haystack)
    m = len(needle)
    if m == 0: return 0
    lps = [0] * m
    length = 0
    i = 1
    while i < m:
        if needle[i] == needle[length]:
            length += 1
            lps[i] = length
            i += 1
        elif length > 0:
            length = lps[length - 1]
        else:
            lps[i] = 0
            i += 1
    hi = 0
    ni = 0
    while hi < n:
        if haystack[hi] == needle[ni]:
            hi += 1
            ni += 1
            if ni == m: return hi - m
        elif ni > 0:
            ni = lps[ni - 1]
        else:
            hi += 1
    return -1
