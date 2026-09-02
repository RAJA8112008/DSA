# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

def carFleet(target, position, speed):
  n = len(position)
  cars = [{"p": position[i], "t": (target - position[i]) / speed[i]} for i in range(n)]
  cars.sort(key=lambda c: -c["p"])
  used = [False] * n
  fleets = 0
  for i in range(n):
    if used[i]: continue
    fleets += 1
    for j in range(i + 1, n):
      if cars[j]["t"] <= cars[i]["t"]:
        used[j] = True
  return fleets


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

def carFleet(target, position, speed):
  n = len(position)
  cars = [[position[i], speed[i]] for i in range(n)]
  cars.sort(key=lambda c: c[0])
  st = []
  for i in range(n - 1, -1, -1):
    time = (target - cars[i][0]) / cars[i][1]
    if not st or time > st[-1]:
      st.append(time)
  return len(st)


# Method 3: More optimal
# Time: O(n log n) | Space: O(n)
# Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

def carFleet(target, position, speed):
  n = len(position)
  cars = [{"p": position[i], "t": (target - position[i]) / speed[i]} for i in range(n)]
  cars.sort(key=lambda c: c["p"])
  fleets = 0
  cur = 0
  for i in range(n - 1, -1, -1):
    if cars[i]["t"] > cur:
      fleets += 1
      cur = cars[i]["t"]
  return fleets
