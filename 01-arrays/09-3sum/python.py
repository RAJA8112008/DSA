# Method 1: Brute
# Time: O(n³) | Space: O(k)
# Every triple of indexes is summed. Uniqueness is handled by a sorted-key set. k is the number of triplets stored.
# How it works: i < j < l. If the three numbers sum to 0, sort them and keep the key in a Set so duplicates are dropped.

def three_sum(nums):
    n = len(nums)
    seen = set()
    out = []
    for i in range(n):

        for j in range(i + 1, n):

            for l in range(j + 1, n):

                if nums[i] + nums[j] + nums[l] == 0:
                    trip = [nums[i], nums[j], nums[l]].sort()
                    key = trip[0] + "," + trip[1] + "," + trip[2]
                    if key not in seen:
                        seen.add(key)
                        out.append(trip)

    return out


# Method 2: Optimal
# Time: O(n² log n) | Space: O(n)
# Sort once. For each pair, binary-search the third value. Each search is log n, and there are n² pairs.
# How it works: after sort, for i and j look for -(nums[i]+nums[j]) in the suffix. Skip used indexes. A set of keys still blocks duplicate triplets.

def three_sum(nums):
    n = len(nums)
    list = sorted(nums)
    seen = set()
    out = []

    def find(start, target):
        lo = start
        hi = n - 1
        while lo <= hi:
            mid = ((lo + hi) ) # 2
            if list[mid] == target: return mid
            if list[mid] < target: lo = mid + 1
            else: hi = mid - 1
        return -1

    for i in range(n):

        for j in range(i + 1, n):

            need = -(list[i] + list[j])
            k = find(j + 1, need)
            if k != -1:
                trip = [list[i], list[j], list[k]]
                key = trip[0] + "," + trip[1] + "," + trip[2]
                if key not in seen:
                    seen.add(key)
                    out.append(trip)

    return out


# Method 3: More optimal
# Time: O(n²) | Space: O(k)
# Sort plus two pointers is the standard bound. Extra memory is only the output (and the sort copy).
# How it works: skip duplicate first numbers. For each i, left = i+1, right = end. Move left/right by comparing the sum to 0, and skip duplicate left/right values after a hit.

def three_sum(nums):
    list = sorted(nums)
    n = len(list)
    out = []
    for i in range(n):

        if i > 0 and list[i] == list[i - 1]: continue
        left = i + 1
        right = n - 1
        while left < right:
            sum = list[i] + list[left] + list[right]
            if sum == 0:
                out.append([list[i], list[left], list[right]])
                left += 1
                right -= 1
                while left < right and list[left] == list[left - 1]: left += 1
                while left < right and list[right] == list[right + 1]: right -= 1
            elif sum < 0:
                left += 1
            else:
                right -= 1

    return out
