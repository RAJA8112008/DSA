// Method 1: Brute
// Time: O(n² · k log k) | Space: O(n·k)
// Each word may be compared to every group representative. Each compare sorts a word of length k.
// How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

function groupAnagrams(strs) {
  function keyOf(word) {
    return word.split("").sort().join("");
  }
  const groups = [];
  for (let i = 0; i < strs.length; i++) {
    const k = keyOf(strs[i]);
    let placed = false;
    for (let g = 0; g < groups.length; g++) {
      if (keyOf(groups[g][0]) === k) {
        groups[g].push(strs[i]);
        placed = true;
        break;
      }
    }
    if (!placed) groups.push([strs[i]]);
  }
  return groups;
}


// Method 2: Optimal
// Time: O(n · k log k) | Space: O(n·k)
// One sort per word, then O(1) average map insert.
// How it works: map sorted-word -> list of originals. Return the map values.

function groupAnagrams(strs) {
  const map = new Map();
  for (let i = 0; i < strs.length; i++) {
    const key = strs[i].split("").sort().join("");
    if (!map.has(key)) map.set(key, []);
    map.get(key).push(strs[i]);
  }
  return Array.from(map.values());
}


// Method 3: More optimal
// Time: O(n·k) | Space: O(n·k)
// No per-word sort. Count 26 letters and join them into a key.
// How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

function groupAnagrams(strs) {
  const map = new Map();
  for (let i = 0; i < strs.length; i++) {
    const count = new Array(26).fill(0);
    const word = strs[i];
    for (let j = 0; j < word.length; j++) {
      count[word.charCodeAt(j) - 97]++;
    }
    const key = count.join(",");
    if (!map.has(key)) map.set(key, []);
    map.get(key).push(word);
  }
  return Array.from(map.values());
}
