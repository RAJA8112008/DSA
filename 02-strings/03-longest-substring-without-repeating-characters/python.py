# Method 1: Brute
# Time: O(n³) | Space: O(n)
# O(n²) substrings, and each uniqueness check can scan the slice again.
# How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

def length_of_longest_substring(s):
    n = len(s)
    best = 0
    for i in range(n):

        for j in range(i, n):

            seen = set()
            unique = True
            for k in range(i, = j):

                if s[k] in seen: { unique = False break }
                seen.add(s[k])

            if unique and j - i + 1 > best: best = j - i + 1

    return best


# Method 2: Optimal
# Time: O(n²) | Space: O(n)
# From each start, grow right until a repeat. Inner work is O(n), times n starts.
# How it works: seen is a Set for the current window. On a repeat, break and try the next start.

def length_of_longest_substring(s):
    best = 0
    n = len(s)
    for i in range(n):

        seen = set()
        for j in range(i, n):

            if s[j] in seen: break
            seen.add(s[j])
            if j - i + 1 > best: best = j - i + 1

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Each index is a right endpoint once. left only moves forward. Map stores last indexes.
# How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

def length_of_longest_substring(s):
    last = {}
    left = 0
    best = 0
    for right in range(len(s)):

        ch = s[right]
        if ch in last and last[ch] >= left) left = last.get(ch: + 1
        last[ch] = right
        length = right - left + 1
        if length > best: best = length

    return best
