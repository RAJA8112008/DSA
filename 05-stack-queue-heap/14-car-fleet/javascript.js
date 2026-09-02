// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

function carFleet(target, position, speed) {
  const n = position.length;
  const cars = [];
  for (let i = 0; i < n; i++) {
    cars.push({ p: position[i], t: (target - position[i]) / speed[i] });
  }
  cars.sort(function (a, b) { return b.p - a.p; });
  const used = Array(n).fill(false);
  let fleets = 0;
  for (let i = 0; i < n; i++) {
    if (used[i]) continue;
    fleets++;
    for (let j = i + 1; j < n; j++) {
      if (cars[j].t <= cars[i].t) used[j] = true;
    }
  }
  return fleets;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

function carFleet(target, position, speed) {
  const n = position.length;
  const cars = [];
  for (let i = 0; i < n; i++) cars.push([position[i], speed[i]]);
  cars.sort(function (a, b) { return a[0] - b[0]; });
  const st = [];
  for (let i = n - 1; i >= 0; i--) {
    const time = (target - cars[i][0]) / cars[i][1];
    if (!st.length || time > st[st.length - 1]) st.push(time);
  }
  return st.length;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

function carFleet(target, position, speed) {
  const n = position.length;
  const cars = [];
  for (let i = 0; i < n; i++) {
    cars.push({ p: position[i], t: (target - position[i]) / speed[i] });
  }
  cars.sort(function (a, b) { return a.p - b.p; });
  let fleets = 0;
  let cur = 0;
  for (let i = n - 1; i >= 0; i--) {
    if (cars[i].t > cur) {
      fleets++;
      cur = cars[i].t;
    }
  }
  return fleets;
}
