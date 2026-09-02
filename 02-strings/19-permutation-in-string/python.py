# Method 1: Brute
# Time: O(m! · n) | Space: O(m! · m)
# All unique perms of s1 are generated, then each is searched in s2. Factorial in m.
# How it works: backtracking builds permutations. indexOf each perm in s2; any hit is true.

def check_inclusion(s1, s2):
    bag = []
    def permute(arr, start):
        if start == len(arr):
            bag.append("".join(arr))
            return
        used = set()
        for i in range(start, len(arr)):

            if arr[i] in used: continue
            used.add(arr[i])
            t = arr[start]
            arr[start] = arr[i]
            arr[i] = t
            permute(arr, start + 1)
            arr[i] = arr[start]
            arr[start] = t

    permute(list(s1), 0)
    for i in range(len(bag)):

        if s2.find(bag[i]) if isinstance(s2, str) else (s2.index(bag[i]) if bag[i] in s2 else -1) != -1: return True

    return False


# Method 2: Optimal
# Time: O(n · 26) | Space: O(1)
# Window of size m slides across s2. Each position compares two 26-slot arrays.
# How it works: need counts s1. have counts the current window. If they match, true. Slide by dropping left and adding right.

def check_inclusion(s1, s2):
    m = len(s1)
    n = len(s2)
    if m > n: return False
    need = [0] * 26
    have = [0] * 26
    for i in range(m):

        need[ord(s1[i]) - 97]++
        have[ord(s2[i]) - 97]++

    def same():
        for i in range(26):
            if need[i] != have[i]: return False
        return True
    if same(): return True
    for right in range(m, n):

        have[ord(s2[right]) - 97]++
        have[ord(s2[right - m]) - 97]--
        if same(): return True

    return False


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# matches tracks how many of the 26 letters currently have the right count. Each add/drop updates matches in O(1).
# How it works: when have[i] hits need[i], matches++. When it leaves, matches--. matches === 26 (or the number of letters that appear in s1) means the window is a permutation. Here we compare all 26 including zeros, so 26 is the target.

def check_inclusion(s1, s2):
    m = len(s1)
    n = len(s2)
    if m > n: return False
    need = [0] * 26
    have = [0] * 26
    for i in range(m):

        need[ord(s1[i]) - 97]++
        have[ord(s2[i]) - 97]++

    matches = 0
    for i in range(26):
        if need[i] == have[i]: matches += 1
    if matches == 26: return True
    for right in range(m, n):

        add = ord(s2[right]) - 97
        drop = ord(s2[right - m]) - 97
        have[add]++
        if have[add] == need[add]: matches += 1
        elif have[add] == need[add] + 1: matches -= 1
        have[drop]--
        if have[drop] == need[drop]: matches += 1
        elif have[drop] == need[drop] - 1: matches -= 1
        if matches == 26: return True

    return False
