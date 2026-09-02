# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For every index you walk the whole left side and the whole right side.
# How it works: water at i is max(0, min(leftMax, rightMax) - height[i]). Sum those amounts.

def trap(height):
    n = len(height)
    total = 0
    for i in range(n):

        leftMax = 0
        rightMax = 0
        for L in range(= i):
            leftMax = max(leftMax, height[L])
        for R in range(i, n):
            rightMax = max(rightMax, height[R])
        total += min(leftMax, rightMax) - height[i]

    return total


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Three linear passes. Two extra arrays of length n.
# How it works: leftMax[i] is the tallest bar at or left of i. rightMax[i] is the tallest at or right of i. Water at i uses those two stored values.

def trap(height):
    n = len(height)
    if n == 0: return 0
    leftMax = [None] * (n)
    rightMax = [None] * (n)
    leftMax[0] = height[0]
    for i in range(1, n):
        leftMax[i] = max(leftMax[i - 1], height[i])
    rightMax[n - 1] = height[n - 1]
    for i in range(n - 2, (0) - 1, -1):
        rightMax[i] = max(rightMax[i + 1], height[i])
    total = 0
    for i in range(n):

        total += min(leftMax[i], rightMax[i]) - height[i]

    return total


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One pass from both ends. Only a handful of integers besides the input.
# How it works: the side with the smaller max is the bottleneck. Add water there, then move that pointer and update that max. The other side is at least as tall, so it can hold this water.

def trap(height):
    left = 0
    right = len(height) - 1
    leftMax = 0
    rightMax = 0
    total = 0
    while left < right:
        if height[left] < height[right]:
            if height[left] >= leftMax: leftMax = height[left]
            else: total += leftMax - height[left]
            left += 1
        else:
            if height[right] >= rightMax: rightMax = height[right]
            else: total += rightMax - height[right]
            right -= 1
    return total
