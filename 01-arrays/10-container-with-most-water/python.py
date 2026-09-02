# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Every pair of bars is an area. Quadratic checks.
# How it works: i is the left wall, j the right wall. Area is min height times width. Keep the max.

def max_area(height):
    best = 0
    n = len(height)
    for i in range(n):

        for j in range(i + 1, n):

            h = min(height[i], height[j])
            area = h * (j - i)
            if area > best: best = area

    return best


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# Each step moves one pointer, so at most n-1 steps.
# How it works: start at both ends. Record the area. Move the shorter wall inward. A taller inner wall might win; a shorter width with the same short wall cannot.

def max_area(height):
    left = 0
    right = len(height) - 1
    best = 0
    while left < right:
        h = min(height[left], height[right])
        area = h * (right - left)
        if area > best: best = area
        if height[left] < height[right]: left += 1
        else: right -= 1
    return best


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Still O(n) worst case, but bars no taller than the current min height are skipped, so fewer area multiplies on flat stretches.
# How it works: after recording the area for height h, advance left while height[left] <= h and right while height[right] <= h.

def max_area(height):
    left = 0
    right = len(height) - 1
    best = 0
    while left < right:
        h = min(height[left], height[right])
        area = h * (right - left)
        if area > best: best = area
        while left < right and height[left] <= h: left += 1
        while left < right and height[right] <= h: right -= 1
    return best
