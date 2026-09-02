// Method 1: Brute
// Time: O(n³) with naive fact | Space: O(n²)
// Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

import java.util.*;
class Solution {
  long nCr(int n, int r) {
    long a = 1, b = 1;
    for (int i = 0; i < r; i++) { a *= (n - i); b *= (i + 1); }
    return a / b;
  }
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    for (int i = 0; i < numRows; i++) {
      List<Integer> row = new ArrayList<Integer>();
      for (int j = 0; j <= i; j++) row.add((int) nCr(i, j));
      out.add(row);
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

import java.util.*;
class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    out.add(Arrays.asList(1));
    for (int r = 1; r < numRows; r++) {
      List<Integer> prev = out.get(r - 1);
      List<Integer> row = new ArrayList<Integer>();
      row.add(1);
      for (int j = 1; j < r; j++) row.add(prev.get(j - 1) + prev.get(j));
      row.add(1);
      out.add(row);
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

import java.util.*;
class Solution {
  public List<List<Integer>> generate(int numRows) {
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    for (int r = 0; r < numRows; r++) {
      List<Integer> row = new ArrayList<Integer>();
      long v = 1;
      row.add(1);
      for (int k = 1; k <= r; k++) {
        v = v * (r - k + 1) / k;
        row.add((int) v);
      }
      out.add(row);
    }
    return out;
  }
}
