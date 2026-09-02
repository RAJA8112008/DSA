# Method 1: Brute
# Time: O(n²) | Space: O(n)
# For each letter in s you search t and splice it out. Each splice is O(n), so quadratic.
# How it works: copy t into an array. For every character of s, indexOf that character in the copy; if missing, false; else splice it out. Empty copy at the end means success.

def is_anagram(s, t):
    if len(s) != len(t): return False
    letters = list(t)
    for i in range(len(s)):

        idx = letters.find(s[i]) if isinstance(letters, str) else (letters.index(s[i]) if s[i] in letters else -1)
        if idx == -1: return False
        del letters[idx]

    return len(letters) == 0


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Sorting both strings dominates. Extra arrays hold the split characters.
# How it works: sort the character lists and compare them index by index.

def is_anagram(s, t):
    if len(s) != len(t): return False
    a = list(s).sort()
    b = list(t).sort()
    for i in range(len(a)):

        if a[i] != b[i]: return False

    return True


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One pass over both strings and 26 integers. For lowercase a-z the extra space is constant.
# How it works: count[s[i]]++, count[t[i]]--. If every slot is 0, the bags of letters matched.

def is_anagram(s, t):
    if len(s) != len(t): return False
    count = [0] * 26
    for i in range(len(s)):

        count[ord(s[i]) - 97]++
        count[ord(t[i]) - 97]--

    for i in range(26):

        if count[i] != 0: return False

    return True
