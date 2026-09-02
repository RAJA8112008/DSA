# Method 1: Brute
# Time: O(n²) | Space: O(1)
# From each start, simulate the circle. Fail when the tank goes negative. Return the first start that finishes n steps.

def canCompleteCircuit(gas, cost):
  n = len(gas)
  for start in range(n):
    tank = 0
    ok = True
    for step in range(n):
      i = (start + step) % n
      tank += gas[i] - cost[i]
      if tank < 0:
        ok = False
        break
    if ok:
      return start
  return -1


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# If the total of gas[i]-cost[i] is negative, no start works. Otherwise try starts in order but skip a failed prefix using a leftover tank. Still a linear check plus a second idea.

def canCompleteCircuit(gas, cost):
  n = len(gas)
  if sum(gas[i] - cost[i] for i in range(n)) < 0:
    return -1
  for start in range(n):
    tank = 0
    ok = True
    for step in range(n):
      i = (start + step) % n
      tank += gas[i] - cost[i]
      if tank < 0:
        ok = False
        break
    if ok:
      return start
  return -1


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One pass. tank is the fuel since the current start. If tank drops below 0, no start in [oldStart, i] works, so start = i+1 and tank = 0. If the total is negative, return -1. Unique start is guaranteed.

def canCompleteCircuit(gas, cost):
  total = tank = start = 0
  for i in range(len(gas)):
    d = gas[i] - cost[i]
    total += d
    tank += d
    if tank < 0:
      start = i + 1
      tank = 0
  return -1 if total < 0 else start
