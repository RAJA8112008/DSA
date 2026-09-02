# Method 1: Brute
# Time: O(n) | Space: O(n)
# You still walk the string once, but you build a digit string and use Number, then clamp.
# How it works: skip spaces, note sign, gather digits into text. Number(text) * sign, then clamp to 32-bit bounds.

def my_atoi(s):
    i = 0
    n = len(s)
    while i < n and s[i] == " ": i += 1
    sign = 1
    if i < n and (s[i] == "+" or s[i] == "-"):
        if s[i] == "-": sign = -1
        i += 1
    digits = ""
    while i < n and s[i] >= "0" and s[i] <= "9":
        digits += s[i]
        i += 1
    if len(digits) == 0: return 0
    num = sign * int(digits)
    lo = -2147483648
    hi = 2147483647
    if num < lo: return lo
    if num > hi: return hi
    return num


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# No digit string. A running number. Clamp after the loop (JS Number can hold these intermediates).
# How it works: same skip/sign walk. num = num * 10 + digit. Then clamp.

def my_atoi(s):
    i = 0
    n = len(s)
    while i < n and s[i] == " ": i += 1
    sign = 1
    if i < n and (s[i] == "+" or s[i] == "-"):
        if s[i] == "-": sign = -1
        i += 1
    num = 0
    while i < n and s[i] >= "0" and s[i] <= "9":
        num = num * 10 + (ord(s[i]) - 48)
        i += 1
    num *= sign
    lo = -2147483648
    hi = 2147483647
    if num < lo: return lo
    if num > hi: return hi
    return num


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Overflow is stopped as soon as the next digit would leave 32-bit range, matching a language without big numbers.
# How it works: before num = num*10 + d, if num > 214748364 or (num === 214748364 and d > 7), return the clamped bound for this sign.

def my_atoi(s):
    i = 0
    n = len(s)
    lo = -2147483648
    hi = 2147483647
    while i < n and s[i] == " ": i += 1
    sign = 1
    if i < n and (s[i] == "+" or s[i] == "-"):
        if s[i] == "-": sign = -1
        i += 1
    num = 0
    while i < n and s[i] >= "0" and s[i] <= "9":
        d = ord(s[i]) - 48
        if num > 214748364 or (num == 214748364 and d > 7):
            hi if return sign == 1 else lo
        num = num * 10 + d
        i += 1
    return num * sign
