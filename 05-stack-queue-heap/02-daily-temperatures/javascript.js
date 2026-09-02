// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each day i, scan j > i until temperatures[j] > temperatures[i]. Worst case a falling array, so n² compares.

function dailyTemperatures(temperatures) {
  const n = temperatures.length;
  const ans = Array(n).fill(0);
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (temperatures[j] > temperatures[i]) {
        ans[i] = j - i;
        break;
      }
    }
  }
  return ans;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Stack of indices with decreasing temps. When a warmer day arrives, pop until the stack is cooler again. Each index is pushed and popped at most once.

function dailyTemperatures(temperatures) {
  const n = temperatures.length;
  const ans = Array(n).fill(0);
  const st = [];
  for (let i = 0; i < n; i++) {
    while (st.length && temperatures[st[st.length - 1]] < temperatures[i]) {
      const j = st.pop();
      ans[j] = i - j;
    }
    st.push(i);
  }
  return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Right-to-left jump: if day j is not warmer, skip ahead by ans[j] days (those days are also not warmer than j, hence not warmer than i if temps[j] <= temps[i]). Extra space is only the output. Still linear.

function dailyTemperatures(temperatures) {
  const n = temperatures.length;
  const ans = Array(n).fill(0);
  for (let i = n - 2; i >= 0; i--) {
    let j = i + 1;
    while (j < n && temperatures[j] <= temperatures[i]) {
      if (ans[j] === 0) { j = n; break; }
      j += ans[j];
    }
    if (j < n) ans[i] = j - i;
  }
  return ans;
}
