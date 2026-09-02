# Method 1: Brute
# Time: O(S) | Space: O(m)
# S is the total number of characters. Each word is compared to the current prefix from scratch.
# How it works: prefix starts as strs[0]. For each next word, cut prefix while it is not a prefix of that word.

def longest_common_prefix(strs):
    if not len(strs): return ""
    prefix = strs[0]
    for i in range(1, len(strs)):

        while strs[i].indexOf(prefix) != 0:
            prefix = prefix[0:len(prefix) - 1]
            if prefix == "": return ""

    return prefix


# Method 2: Optimal
# Time: O(n log n + m) | Space: O(m)
# Sort the n words, then only the first and last can disagree. m is the shorter of those two.
# How it works: after sort, walk columns of first vs last until they differ. That slice is the prefix of the whole set.

def longest_common_prefix(strs):
    if not len(strs): return ""
    list = strs[:].sort()
    first = list[0]
    last = list[len(list) - 1]
    i = 0
    while i < len(first) and i < len(last) and first[i] == last[i]: i += 1
    return first[0:i]


# Method 3: More optimal
# Time: O(S) | Space: O(1)
# No sort copy. Extra memory is a few indexes. Worst case still reads every character of every word until a mismatch.
# How it works: for column i of strs[0], every other word must have the same character. Return the slice before the first failure.

def longest_common_prefix(strs):
    if not len(strs): return ""
    first = strs[0]
    for i in range(len(first)):

        ch = first[i]
        for j in range(1, len(strs)):

            if i >= strs[j].length or strs[j][i] != ch: return first[0:i]

    return first
