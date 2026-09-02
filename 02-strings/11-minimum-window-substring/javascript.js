// Method 1: Brute
// Time: O(n² · k) | Space: O(k)
// Every i..j window rebuilds counts against t. k is the alphabet / unique letters in t.
// How it works: covers() copies t’s need map and decrements for each character of the slice. Keep the shortest slice that covers.

function minWindow(s, t) {
  function covers(slice) {
    const need = new Map();
    for (let i = 0; i < t.length; i++) {
      need.set(t[i], (need.get(t[i]) || 0) + 1);
    }
    for (let i = 0; i < slice.length; i++) {
      const ch = slice[i];
      if (need.has(ch)) {
        need.set(ch, need.get(ch) - 1);
        if (need.get(ch) === 0) need.delete(ch);
      }
    }
    return need.size === 0;
  }
  let best = "";
  for (let i = 0; i < s.length; i++) {
    for (let j = i; j < s.length; j++) {
      const slice = s.slice(i, j + 1);
      if (covers(slice) && (best === "" || slice.length < best.length)) best = slice;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(k)
// From each left, grow right until t is covered, then record and try the next left. Still quadratic starts.
// How it works: missing starts as t.length. A need map counts t. As right adds characters, missing drops. First time missing hits 0, that window is a candidate.

function minWindow(s, t) {
  if (t.length > s.length) return "";
  let best = "";
  for (let left = 0; left < s.length; left++) {
    const need = new Map();
    for (let i = 0; i < t.length; i++) need.set(t[i], (need.get(t[i]) || 0) + 1);
    let missing = t.length;
    for (let right = left; right < s.length; right++) {
      const ch = s[right];
      if (need.has(ch) && need.get(ch) > 0) missing--;
      if (need.has(ch)) need.set(ch, need.get(ch) - 1);
      if (missing === 0) {
        const slice = s.slice(left, right + 1);
        if (best === "" || slice.length < best.length) best = slice;
        break;
      }
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// right walks n times, left walks n times. formed tracks how many unique t-characters are satisfied.
// How it works: grow right, update have. While the window is complete, record if smaller, drop s[left], move left. needCount is the number of unique keys in t.

function minWindow(s, t) {
  if (t.length > s.length) return "";
  const need = new Map();
  for (let i = 0; i < t.length; i++) need.set(t[i], (need.get(t[i]) || 0) + 1);
  const have = new Map();
  let formed = 0;
  const needCount = need.size;
  let bestL = 0;
  let bestR = -1;
  let left = 0;
  for (let right = 0; right < s.length; right++) {
    const ch = s[right];
    have.set(ch, (have.get(ch) || 0) + 1);
    if (need.has(ch) && have.get(ch) === need.get(ch)) formed++;
    while (formed === needCount) {
      if (bestR === -1 || right - left < bestR - bestL) {
        bestL = left;
        bestR = right;
      }
      const drop = s[left];
      have.set(drop, have.get(drop) - 1);
      if (need.has(drop) && have.get(drop) < need.get(drop)) formed--;
      left++;
    }
  }
  return bestR === -1 ? "" : s.slice(bestL, bestR + 1);
}
