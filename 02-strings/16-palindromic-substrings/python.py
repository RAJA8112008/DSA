# Method 1: Brute
# Time: O(n³) | Space: O(1)
# O(n²) ranges, each palindrome test O(n).
# How it works: for every i..j, two-pointer check. Increment count when it is a palindrome.

def count_substrings(s):
    def is_palin(left, right):
        while left < right:
            if s[left] != s[right]: return False
            left += 1
            right -= 1
        return True
    count = 0
    n = len(s)
    for i in range(n):

        for j in range(i, n):

            if is_palin(i, j): count += 1

    return count


# Method 2: Optimal
# Time: O(n²) | Space: O(n²)
# A boolean table of n by n. Each cell is O(1) after shorter lengths are known.
# How it works: pal[i][j] is true if s[i]===s[j] and the inside is a palindrome (or the length is 1 or 2). Count every true cell.

def count_substrings(s):
    n = len(s)
    pal = []
    for i in range(n):
        pal.append([False] * n)
    count = 0
    for i in range(n - 1, (0) - 1, -1):

        for j in range(i, n):

            if s[i] == s[j] and (j - i < 2 or pal[i + 1][j - 1]):
                pal[i][j] = True
                count += 1

    return count


# Method 3: More optimal
# Time: O(n²) | Space: O(1)
# Same time, constant extra memory. Each palindrome is grown from a center.
# How it works: expand(left,right) counts while the letters match. Call expand(i,i) and expand(i,i+1) for every i.

def count_substrings(s):
    count = 0
    def expand(left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            count += 1
            left -= 1
            right += 1
    for i in range(len(s)):

        expand(i, i)
        expand(i, i + 1)

    return count
