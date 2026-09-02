# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Add the new interval, then reuse the quadratic merge-until-stable idea.
# How it works: push a copy of newInterval onto a copied list, then glue overlaps with nested scans until the list is stable.

def insert(intervals, newInterval):
    out = []
    for i in range(len(intervals)):

        out.append([intervals[i][0], intervals[i][1]])

    out.append([newInterval[0], newInterval[1]])
    changed = True
    while changed:
        changed = False
        for i in range(len(out)):

            for j in range(i + 1, len(out)):

                if out[i][0] <= out[j][1] and out[j][0] <= out[i][1]:
                    out[i][0] = min(out[i][0], out[j][0])
                    out[i][1] = max(out[i][1], out[j][1])
                    del out[j]
                    changed = True
                    break

            if changed: break

    out.sort(key=lambda z: z[0])
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Three buckets, one scan. No sort needed because the input is already sorted.
# How it works: before holds intervals fully to the left. after holds fully to the right. The middle ones stretch start/end of the new interval. Concatenate before + merged + after.

def insert(intervals, newInterval):
    before = []
    after = []
    start = newInterval[0]
    end = newInterval[1]
    for i in range(len(intervals)):

        cur = intervals[i]
        if cur[1] < start: before.append([cur[0], cur[1]])
        elif cur[0] > end: after.append([cur[0], cur[1]])
        else:
            start = min(start, cur[0])
            end = max(end, cur[1])

    return (before + [[start, end]], after)


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# One pass, one result list, no extra before/after arrays (the result plays that role).
# How it works: copy intervals that end before the new start. Merge while the next interval starts at or before the new end. Then copy the tail.

def insert(intervals, newInterval):
    out = []
    n = len(intervals)
    i = 0
    start = newInterval[0]
    end = newInterval[1]
    while i < n and intervals[i][1] < start:
        out.append([intervals[i][0], intervals[i][1]])
        i += 1
    while i < n and intervals[i][0] <= end:
        start = min(start, intervals[i][0])
        end = max(end, intervals[i][1])
        i += 1
    out.append([start, end])
    while i < n:
        out.append([intervals[i][0], intervals[i][1]])
        i += 1
    return out
