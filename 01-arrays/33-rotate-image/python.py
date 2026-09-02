# Method 1: Brute
# Time: O(n²) | Space: O(n²)
# new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

def rotate(matrix):
  n = len(matrix)
  neu = [[0] * n for _ in range(n)]
  for r in range(n):
    for c in range(n):
      neu[c][n - 1 - r] = matrix[r][c]
  for r in range(n):
    for c in range(n):
      matrix[r][c] = neu[r][c]
  return matrix


# Method 2: Optimal
# Time: O(n²) | Space: O(1)
# Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

def rotate(matrix):
  n = len(matrix)
  for i in range(n):
    for j in range(i + 1, n):
      matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
  for i in range(n):
    L, R = 0, n - 1
    while L < R:
      matrix[i][L], matrix[i][R] = matrix[i][R], matrix[i][L]
      L += 1
      R -= 1
  return matrix


# Method 3: More optimal
# Time: O(n²) | Space: O(1)
# Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

def rotate(matrix):
  n = len(matrix)
  for layer in range(n // 2):
    last = n - 1 - layer
    for i in range(last - layer):
      top = matrix[layer][layer + i]
      matrix[layer][layer + i] = matrix[last - i][layer]
      matrix[last - i][layer] = matrix[last][last - i]
      matrix[last][last - i] = matrix[layer + i][last]
      matrix[layer + i][last] = top
  return matrix
