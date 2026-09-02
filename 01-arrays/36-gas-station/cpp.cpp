// Method 1: Brute
// Time: O(n²) | Space: O(1)
// From each start, simulate the circle. Fail when the tank goes negative. Return the first start that finishes n steps.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = (int)gas.size();
  for (int start = 0; start < n; start++) {
    int tank = 0;
    bool ok = true;
    for (int step = 0; step < n; step++) {
      int i = (start + step) % n;
      tank += gas[i] - cost[i];
      if (tank < 0) { ok = false; break; }
    }
    if (ok) return start;
  }
  return -1;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// If the total of gas[i]-cost[i] is negative, no start works. Otherwise try starts in order but skip a failed prefix using a leftover tank. Still a linear check plus a second idea.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int n = (int)gas.size(), total = 0;
  for (int i = 0; i < n; i++) total += gas[i] - cost[i];
  if (total < 0) return -1;
  for (int start = 0; start < n; start++) {
    int tank = 0;
    bool ok = true;
    for (int step = 0; step < n; step++) {
      int i = (start + step) % n;
      tank += gas[i] - cost[i];
      if (tank < 0) { ok = false; break; }
    }
    if (ok) return start;
  }
  return -1;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass. tank is the fuel since the current start. If tank drops below 0, no start in [oldStart, i] works, so start = i+1 and tank = 0. If the total is negative, return -1. Unique start is guaranteed.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int total = 0, tank = 0, start = 0;
  for (int i = 0; i < (int)gas.size(); i++) {
    int d = gas[i] - cost[i];
    total += d;
    tank += d;
    if (tank < 0) { start = i + 1; tank = 0; }
  }
  return total < 0 ? -1 : start;
}
