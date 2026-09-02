# Method 1: Brute
# Time: O(n² · k log k) | Space: O(n·k)
# Each word may be compared to every group representative. Each compare sorts a word of length k.
# How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

def group_anagrams(strs):
    def key_of(word):
        return "".join(sorted(word))
    groups = []
    for i in range(len(strs)):

        k = key_of(strs[i])
        placed = False
        for g in range(len(groups)):

            if key_of(groups[g][0]) == k:
                groups[g].push(strs[i])
                placed = True
                break

        if not placed: groups.append([strs[i]])

    return groups


# Method 2: Optimal
# Time: O(n · k log k) | Space: O(n·k)
# One sort per word, then O(1) average map insert.
# How it works: map sorted-word -> list of originals. Return the map values.

def group_anagrams(strs):
    map = {}
    for i in range(len(strs)):

        key = strs[i].split("").sort().join("")
        if key not in map: map[key] = []
        map[key].push(strs[i])

    return list(map.values())


# Method 3: More optimal
# Time: O(n·k) | Space: O(n·k)
# No per-word sort. Count 26 letters and join them into a key.
# How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

def group_anagrams(strs):
    map = {}
    for i in range(len(strs)):

        count = [0] * 26
        word = strs[i]
        for j in range(len(word)):

            count[ord(word[j]) - 97]++

        key = ",".join(count)
        if key not in map: map[key] = []
        map[key].push(word)

    return list(map.values())
