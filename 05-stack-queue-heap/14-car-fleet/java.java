// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

import java.util.*;
class Solution {
  public int carFleet(int target, int[] position, int[] speed) {
    int n = position.length;
    double[][] cars = new double[n][2];
    for (int i = 0; i < n; i++) {
      cars[i][0] = position[i];
      cars[i][1] = (target - position[i]) * 1.0 / speed[i];
    }
    Arrays.sort(cars, (a, b) -> Double.compare(b[0], a[0]));
    boolean[] used = new boolean[n];
    int fleets = 0;
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      fleets++;
      for (int j = i + 1; j < n; j++) if (cars[j][1] <= cars[i][1]) used[j] = true;
    }
    return fleets;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

import java.util.*;
class Solution {
  public int carFleet(int target, int[] position, int[] speed) {
    int n = position.length;
    int[][] cars = new int[n][2];
    for (int i = 0; i < n; i++) { cars[i][0] = position[i]; cars[i][1] = speed[i]; }
    Arrays.sort(cars, (a, b) -> a[0] - b[0]);
    ArrayDeque<Double> st = new ArrayDeque<Double>();
    for (int i = n - 1; i >= 0; i--) {
      double time = (target - cars[i][0]) * 1.0 / cars[i][1];
      if (st.isEmpty() || time > st.peek()) st.push(time);
    }
    return st.size();
  }
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

import java.util.*;
class Solution {
  public int carFleet(int target, int[] position, int[] speed) {
    int n = position.length;
    double[][] cars = new double[n][2];
    for (int i = 0; i < n; i++) {
      cars[i][0] = position[i];
      cars[i][1] = (target - position[i]) * 1.0 / speed[i];
    }
    Arrays.sort(cars, (a, b) -> Double.compare(a[0], b[0]));
    int fleets = 0;
    double cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (cars[i][1] > cur) { fleets++; cur = cars[i][1]; }
    }
    return fleets;
  }
}
