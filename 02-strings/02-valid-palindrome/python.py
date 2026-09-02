# Method 1: Brute
# Time: O(n) | Space: O(n)
# Linear scan, but a full cleaned copy plus a reversed copy.
# How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

def is_palindrome(s):
    cleaned = ""
    for i in range(len(s)):

        ch = s[i].lower()
        if (ch >= "a" and ch <= "z") or (ch >= "0" and ch <= "9"): cleaned += ch

    reversed = list(cleaned).reverse().join("")
    return cleaned == reversed


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Still a cleaned array, but comparison is two pointers instead of building a reversed string.
# How it works: push kept characters into chars, then left/right must match.

def is_palindrome(s):
    chars = []
    for i in range(len(s)):

        ch = s[i].lower()
        if (ch >= "a" and ch <= "z") or (ch >= "0" and ch <= "9"): chars.append(ch)

    left = 0
    right = len(chars) - 1
    while left < right:
        if chars[left] != chars[right]: return False
        left += 1
        right -= 1
    return True


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# No extra string of length n. Two indexes on the original text.
# How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

def is_palindrome(s):
    def ok(ch):
        c = ch.lower()
        return (c >= "a" and c <= "z") or (c >= "0" and c <= "9")
    left = 0
    right = len(s) - 1
    while left < right:
        while left < right and not ok(s[left]): left += 1
        while left < right and not ok(s[right]): right -= 1
        if s[left].lower() != s[right].lower(): return False
        left += 1
        right -= 1
    return True
