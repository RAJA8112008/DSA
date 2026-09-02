# Method 1: Brute
# Time: O(n² · 26) | Space: O(1)
# Every window rebuilds 26 counts and checks whether length - maxCount <= k.
# How it works: if the letters that are not the most common letter fit in k replacements, the window is valid. Keep the max valid length.

def character_replacement(s, k):
    best = 0
    n = len(s)
    for i in range(n):

        count = [0] * 26
        maxCount = 0
        for j in range(i, n):

            idx = ord(s[j]) - 65
            count[idx]++
            if count[idx] > maxCount: maxCount = count[idx]
            length = j - i + 1
            if length - maxCount <= k and length > best: best = length

    return best


# Method 2: Optimal
# Time: O(n · 26) | Space: O(1)
# One window. When invalid, left moves and you recompute maxCount by scanning 26 slots.
# How it works: grow right. While length - maxCount > k, decrement s[left] and recount maxCount. Then update best.

def character_replacement(s, k):
    count = [0] * 26
    left = 0
    best = 0
    for right in range(len(s)):

        count[ord(s[right]) - 65]++
        def max_in_count():
            m = 0
            for i in range(26):
                if count[i] > m: m = count[i]
            return m
        while right - left + 1 - max_in_count() > k:
            count[ord(s[left]) - 65]--
            left += 1
        length = right - left + 1
        if length > best: best = length

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# maxCount only increases when a better majority appears. For the longest window, you never need a smaller maxCount.
# How it works: grow right, update maxCount. If window is too dirty, move left once (not a while with a rescan). Window size still only grows when valid history allows it.

def character_replacement(s, k):
    count = [0] * 26
    left = 0
    maxCount = 0
    best = 0
    for right in range(len(s)):

        idx = ord(s[right]) - 65
        count[idx]++
        if count[idx] > maxCount: maxCount = count[idx]
        if right - left + 1 - maxCount > k:
            count[ord(s[left]) - 65]--
            left += 1
        length = right - left + 1
        if length > best: best = length

    return best
