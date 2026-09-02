# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Each pass scans the whole string and removes one pair. Up to n/2 passes.
# How it works: while any "()", "[]", or "{}" remains, split-join it away. Success is an empty string.

def is_valid(s):
    cur = s
    changed = True
    while changed:
        next = list(cur) if "()" == "" else cur.split("()").join("").split("[]").join("").split("{}").join("")
        changed = next != cur
        cur = next
    return len(cur) == 0


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One pass. Stack holds at most n openers.
# How it works: push openers. On a closer, pop and check it is the matching opener. Leftover openers fail.

def is_valid(s):
    stack = []
    for i in range(len(s)):

        ch = s[i]
        if ch == "(" or ch == "[" or ch == "{":
            stack.append(ch)
        else:
            top = stack.pop()
            if ch == ")" and top != "(": return False
            if ch == "]" and top != "[": return False
            if ch == "}" and top != "{": return False

    return len(stack) == 0


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Same O(n) bound. A pair map avoids three mismatch branches, and odd length fails immediately.
# How it works: if the character is a key in pairs, it is a closer: pop must equal pairs[ch]. Else it is an opener: push.

def is_valid(s):
    if len(s) % 2 == 1: return False
    pairs = { ")": "(", "]": "[", "}": "{" }
    stack = []
    for i in range(len(s)):

        ch = s[i]
        if pairs[ch]:
            if stack.pop() != pairs[ch]: return False
        else:
            stack.append(ch)

    return len(stack) == 0
