# Method 1: Brute
# Time: O(n³) with naive fact | Space: O(n²)
# Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

def generate(numRows):
  def nCr(n, r):
    a = b = 1
    for i in range(r):
      a *= n - i
      b *= i + 1
    return a // b
  out = []
  for i in range(numRows):
    out.append([nCr(i, j) for j in range(i + 1)])
  return out


# Method 2: Optimal
# Time: O(n²) | Space: O(n²)
# Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

def generate(numRows):
  out = [[1]]
  for r in range(1, numRows):
    prev = out[-1]
    row = [1]
    for j in range(1, r):
      row.append(prev[j - 1] + prev[j])
    row.append(1)
    out.append(row)
  return out


# Method 3: More optimal
# Time: O(n²) | Space: O(n²)
# Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

def generate(numRows):
  out = []
  for r in range(numRows):
    row = [1]
    v = 1
    for k in range(1, r + 1):
      v = v * (r - k + 1) // k
      row.append(v)
    out.append(row)
  return out
