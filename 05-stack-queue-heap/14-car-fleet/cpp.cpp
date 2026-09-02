// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = (int)position.size();
    vector<pair<double,double>> cars(n);
    for (int i = 0; i < n; i++) cars[i] = { (double)position[i], (target - position[i]) * 1.0 / speed[i] };
    sort(cars.begin(), cars.end(), [](auto& a, auto& b){ return a.first > b.first; });
    vector<int> used(n, 0);
    int fleets = 0;
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      fleets++;
      for (int j = i + 1; j < n; j++) if (cars[j].second <= cars[i].second) used[j] = 1;
    }
    return fleets;
  }
};


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = (int)position.size();
    vector<pair<int,int>> cars(n);
    for (int i = 0; i < n; i++) cars[i] = {position[i], speed[i]};
    sort(cars.begin(), cars.end());
    vector<double> st;
    for (int i = n - 1; i >= 0; i--) {
      double time = (target - cars[i].first) * 1.0 / cars[i].second;
      if (st.empty() || time > st.back()) st.push_back(time);
    }
    return (int)st.size();
  }
};


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = (int)position.size();
    vector<pair<double,double>> cars(n);
    for (int i = 0; i < n; i++) cars[i] = { (double)position[i], (target - position[i]) * 1.0 / speed[i] };
    sort(cars.begin(), cars.end());
    int fleets = 0;
    double cur = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (cars[i].second > cur) { fleets++; cur = cars[i].second; }
    }
    return fleets;
  }
};
