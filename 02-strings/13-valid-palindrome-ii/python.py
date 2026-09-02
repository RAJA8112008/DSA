# Method 1: Brute
# Time: O(n²) | Space: O(n)
# n candidate strings after deleting one index, each palindrome check is O(n).
# How it works: if s is already a palindrome, true. Else for each i, check s without index i.

def valid_palindrome(s):
    def is_palin(text):
        left = 0
        right = len(text) - 1
        while left < right:
            if text[left] != text[right]: return False
            left += 1
            right -= 1
        return True
    if is_palin(s): return True
    for i in range(len(s)):

        if is_palin(s[0:i] + s[i + 1:]): return True

    return False


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One mismatch, then two extra strings of length n-1.
# How it works: walk inward. On mismatch, test skip-left and skip-right by slicing. If the whole walk succeeds, no deletion was needed.

def valid_palindrome(s):
    def is_palin(text):
        left = 0
        right = len(text) - 1
        while left < right:
            if text[left] != text[right]: return False
            left += 1
            right -= 1
        return True
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            skipL = s[left + 1:right + 1]
            skipR = s[left:right]
            return is_palin(skipL) or is_palin(skipR)
        left += 1
        right -= 1
    return True


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Range checks use indexes only. No sliced copies.
# How it works: palin(l,r) checks a range. On the first mismatch, return palin(left+1, right) or palin(left, right-1).

def valid_palindrome(s):
    def palin(left, right):
        while left < right:
            if s[left] != s[right]: return False
            left += 1
            right -= 1
        return True
    left = 0
    right = len(s) - 1
    while left < right:
        if s[left] != s[right]:
            return palin(left + 1, right) or palin(left, right - 1)
        left += 1
        right -= 1
    return True
