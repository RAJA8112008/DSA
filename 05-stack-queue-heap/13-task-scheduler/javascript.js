// Method 1: Brute
// Time: O(k^t) | Space: O(k)
// At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

function leastInterval(tasks, n) {
  const count = {};
  for (let i = 0; i < tasks.length; i++) count[tasks[i]] = (count[tasks[i]] || 0) + 1;
  const types = Object.keys(count);
  let best = Infinity;
  function left() {
    let s = 0;
    for (let i = 0; i < types.length; i++) s += count[types[i]];
    return s;
  }
  function dfs(time, cool) {
    if (time >= best) return;
    if (!left()) { best = time; return; }
    let placed = false;
    for (let i = 0; i < types.length; i++) {
      const t = types[i];
      if (count[t] === 0) continue;
      if ((cool[t] || 0) > time) continue;
      placed = true;
      count[t]--;
      const old = cool[t] || 0;
      cool[t] = time + n + 1;
      dfs(time + 1, cool);
      cool[t] = old;
      count[t]++;
    }
    if (!placed) dfs(time + 1, cool);
  }
  dfs(0, {});
  return best;
}


// Method 2: Optimal
// Time: O(t log k) | Space: O(k)
// Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

function leastInterval(tasks, n) {
  const freq = Array(26).fill(0);
  for (let i = 0; i < tasks.length; i++) freq[tasks[i].charCodeAt(0) - 65]++;
  const h = [];
  function up(i) {
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (h[i] <= h[p]) break;
      const t = h[i]; h[i] = h[p]; h[p] = t;
      i = p;
    }
  }
  function down(i) {
    while (true) {
      let s = i;
      const l = i * 2 + 1, r = l + 1;
      if (l < h.length && h[l] > h[s]) s = l;
      if (r < h.length && h[r] > h[s]) s = r;
      if (s === i) break;
      const t = h[i]; h[i] = h[s]; h[s] = t;
      i = s;
    }
  }
  function push(x) { h.push(x); up(h.length - 1); }
  function pop() {
    const top = h[0];
    const last = h.pop();
    if (h.length) { h[0] = last; down(0); }
    return top;
  }
  for (let i = 0; i < 26; i++) if (freq[i]) push(freq[i]);
  const cool = [];
  let time = 0;
  while (h.length || cool.length) {
    time++;
    if (h.length) {
      const left = pop() - 1;
      if (left) cool.push([left, time + n]);
    }
    if (cool.length && cool[0][1] === time) push(cool.shift()[0]);
  }
  return time;
}


// Method 3: More optimal
// Time: O(t) | Space: O(1)
// The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

function leastInterval(tasks, n) {
  const freq = Array(26).fill(0);
  for (let i = 0; i < tasks.length; i++) freq[tasks[i].charCodeAt(0) - 65]++;
  let maxF = 0, maxCount = 0;
  for (let i = 0; i < 26; i++) {
    if (freq[i] > maxF) { maxF = freq[i]; maxCount = 1; }
    else if (freq[i] === maxF) maxCount++;
  }
  const frame = (maxF - 1) * (n + 1) + maxCount;
  return Math.max(frame, tasks.length);
}
