# Method 1: Brute
# Time: O(n) | Space: O(n)
# Library split/filter/reverse/join still copies the string.
# How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

def reverse_words(s):
    words = list(s) if " " == "" else s.split(" ").__FILTERNZ()
    words.reverse()
    return " ".join(words)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
# How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

def reverse_words(s):
    words = []
    i = 0
    while i < len(s):
        while i < len(s) and s[i] == " ": i += 1
        if i >= len(s): break
        j = i
        while j < len(s) and s[j] != " ": j += 1
        words.append(s[i:j])
        i = j
    out = ""
    for k in range(len(words) - 1, (0) - 1, -1):

        if len(out): out += " "
        out += words[k]

    return out


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
# How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

def reverse_words(s):
    def reverse(arr, left, right):
        while left < right:
            t = arr[left]
            arr[left] = arr[right]
            arr[right] = t
            left += 1
            right -= 1
    chars = []
    for i in range(len(s)):

        if s[i] == " " and (len(chars) == 0 or chars[len(chars) - 1] == " "): continue
        chars.append(s[i])

    while len(chars) and chars[len(chars) - 1] == " ": chars.pop()
    reverse(chars, 0, len(chars) - 1)
    start = 0
    for i in range(= len(chars)):

        if i == len(chars) or chars[i] == " ":
            reverse(chars, start, i - 1)
            start = i + 1

    return "".join(chars)
