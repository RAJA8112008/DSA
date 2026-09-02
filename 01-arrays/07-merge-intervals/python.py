# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Each merge pass can scan all remaining pairs. Several passes still stay quadratic for typical n.
# How it works: copy intervals. While any two overlap, replace them with their union and restart the pair scan.

def merge(intervals):
    out = []
    for i in range(len(intervals)):

        out.append([intervals[i][0], intervals[i][1]])

    changed = True
    while changed:
        changed = False
        for i in range(len(out)):

            for j in range(i + 1, len(out)):

                a = out[i]
                b = out[j]
                if a[0] <= b[1] and b[0] <= a[1]:
                    a[0] = min(a[0], b[0])
                    a[1] = max(a[1], b[1])
                    del out[j]
                    changed = True
                    break

            if changed: break

    return out


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Sort by start, then one linear merge. Sorting is the bottleneck.
# How it works: after sort, only the last merged interval can overlap the next one. Stretch its end or push a new block.

def merge(intervals):
    if len(intervals) == 0: return []
    list = [[p[0], p[1]] for p in intervals]
    list.sort(key=lambda z: z[0])
    merged = [list[0]]
    for i in range(1, len(list)):

        last = merged[len(merged) - 1]
        if list[i][0] <= last[1]:
            last[1] = max(last[1], list[i][1])
        else:
            merged.append(list[i])

    return merged


# Method 3: More optimal
# Time: O(n log n) | Space: O(n)
# Same O(n log n) bound: you must sort unless the input is already ordered. This version sorts a copy once and writes merged ranges without extra pass flags.
# How it works: identical merge walk, with an early return for an empty list and copies so caller intervals stay untouched.

def merge(intervals):
    n = len(intervals)
    if n == 0: return []
    list = [None] * (n)
    for i in range(n):
        list[i] = [intervals[i][0], intervals[i][1]]
    list.sort(key=lambda z: z[0])
    merged = []
    start = list[0][0]
    end = list[0][1]
    for i in range(1, n):

        if list[i][0] <= end:
            if list[i][1] > end: end = list[i][1]
        else:
            merged.append([start, end])
            start = list[i][0]
            end = list[i][1]

    merged.append([start, end])
    return merged
