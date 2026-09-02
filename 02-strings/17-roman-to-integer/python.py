# Method 1: Brute
# Time: O(n) | Space: O(n)
# You copy the string and rewrite pairs, then sum. Extra string memory.
# How it works: replace CM, CD, XC, XL, IX, IV with single tokens, then add a map of remaining symbols including those tokens.

def roman_to_int(s):
    t = s
    t = list(t) if "CM" == "" else t.split("CM").join("a")
    t = list(t) if "CD" == "" else t.split("CD").join("b")
    t = list(t) if "XC" == "" else t.split("XC").join("c")
    t = list(t) if "XL" == "" else t.split("XL").join("d")
    t = list(t) if "IX" == "" else t.split("IX").join("e")
    t = list(t) if "IV" == "" else t.split("IV").join("f")
    val = { M: 1000, D: 500, C: 100, L: 50, X: 10, V: 5, I: 1, a: 900, b: 400, c: 90, d: 40, e: 9, f: 4 }
    sum = 0
    for i in range(len(t)):
        sum += val[t[i]]
    return sum


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# One pass, a fixed map. When a subtractive pair is seen, add the pair value and skip two characters.
# How it works: if val[s[i]] < val[s[i+1]], add the difference and i += 2. Else add val[s[i]] and i += 1.

def roman_to_int(s):
    val = { I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000 }
    sum = 0
    i = 0
    while i < len(s):
        cur = val[s[i]]
        val[s[i + 1]] if next = i + 1 < len(s) else 0
        if cur < next:
            sum += next - cur
            i += 2
        else:
            sum += cur
            i += 1
    return sum


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Same linear scan, no skip logic: always add the current value, but subtract it instead when it is smaller than the next.
# How it works: for each i, if val[s[i]] < val[s[i+1]] then sum -= val[s[i]], else sum += val[s[i]].

def roman_to_int(s):
    val = { I: 1, V: 5, X: 10, L: 50, C: 100, D: 500, M: 1000 }
    sum = 0
    for i in range(len(s)):

        cur = val[s[i]]
        val[s[i + 1]] if next = i + 1 < len(s) else 0
        if cur < next: sum -= cur
        else: sum += cur

    return sum
