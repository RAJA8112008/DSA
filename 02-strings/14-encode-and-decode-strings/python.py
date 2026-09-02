# Method 1: Brute
# Time: O(n) | Space: O(n)
# JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
# How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

# import json
def encode(strs):
    return json.dumps(strs)
def decode(s):
    return json.loads(s)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
# How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

def encode(strs):
    header = str(len(strs))
    for i in range(len(strs)):

        header += "," + str(strs[i].length)

    body = ""
    for i in range(len(strs)):
        body += strs[i]
    return header + "#" + body
def decode(s):
    hash = s.find("#") if isinstance(s, str) else (s.index("#") if "#" in s else -1)
    parts = s[0:hash].split(",")
    n = int(parts[0])
    out = []
    pos = hash + 1
    for i in range(n):

        length = int(parts[i + 1])
        out.append(s[pos:pos + length])
        pos += length

    return out


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
# How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

def encode(strs):
    out = ""
    for i in range(len(strs)):

        out += str(strs[i].length) + "#" + strs[i]

    return out
def decode(s):
    out = []
    i = 0
    while i < len(s):
        j = i
        while s[j] != "#": j += 1
        length = int(s[i:j])
        word = s[j + 1:j + 1 + length]
        out.append(word)
        i = j + 1 + length
    return out
