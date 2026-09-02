# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Count with nested scans: for each character type, walk the whole string. Slow counting, same final formula.
# How it works: collect unique letters. For each letter, count occurrences with a full scan. Add even parts; remember if any odd exists; add 1 for a center.

def longest_palindrome(s):
    letters = []
    for i in range(len(s)):

        if letters.find(s[i]) if isinstance(letters, str) else (letters.index(s[i]) if s[i] in letters else -1) == -1: letters.append(s[i])

    length = 0
    odd = False
    for L in range(len(letters)):

        c = 0
        for i in range(len(s)):
            if s[i] == letters[L]: c += 1
        length += c - (c % 2)
        if c % 2 == 1: odd = True

    length + 1 if return odd else length


# Method 2: Optimal
# Time: O(n) | Space: O(k)
# One pass to count, one pass over unique keys. k is the alphabet size.
# How it works: object/map frequencies. Even contribution is count - count%2. One leftover odd becomes the center.

def longest_palindrome(s):
    count = {}
    for i in range(len(s)):

        ch = s[i]
        count[ch] = (count[ch] or 0) + 1

    length = 0
    odd = False
    for ch in count:
        length += count[ch] - (count[ch] % 2)
        if count[ch] % 2 == 1: odd = True
    length + 1 if return odd else length


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# 128 slots cover ASCII letters used in the usual prompt. Extra memory is constant.
# How it works: count[charCode]++. Same even/odd rule on the 128 numbers. Equivalent: len += count[i] & ~1, then if len < s.length add 1.

def longest_palindrome(s):
    count = [0] * 128
    for i in range(len(s)):
        count[ord(s[i])]++
    length = 0
    for i in range(128):
        length += count[i] - (count[i] % 2)
    if length < len(s): length += 1
    return length
