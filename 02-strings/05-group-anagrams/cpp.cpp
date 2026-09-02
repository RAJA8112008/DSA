// Method 1: Brute
// Time: O(n² · k log k) | Space: O(n·k)
// Each word may be compared to every group representative. Each compare sorts a word of length k.
// How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

// vector, unordered_map, string
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  auto keyOf = [&](word) {
    return /* split word */.sort().join("");
  }
  vector<int> groups;
  for (int i = 0; i < (int)strs.size(); i++) {
    int k = keyOf(strs[i]);
    bool placed = false;
    for (int g = 0; g < (int)groups.size(); g++) {
      if (keyOf(groups[g][0]) == k) {
        groups[g].push(strs[i]);
        placed = true;
        break;
      }
    }
    if (!placed) groups.push_back([strs[i]]);
  }
  return groups;
}


// Method 2: Optimal
// Time: O(n · k log k) | Space: O(n·k)
// One sort per word, then O(1) average map insert.
// How it works: map sorted-word -> list of originals. Return the map values.

// vector, unordered_map, string
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<int,int> map;
  for (int i = 0; i < (int)strs.size(); i++) {
    string key = strs[i].split("").sort().join("");
    if (!map.count(key)) map[key] = [];
    map[key].push(strs[i]);
  }
  return /* values */;
}


// Method 3: More optimal
// Time: O(n·k) | Space: O(n·k)
// No per-word sort. Count 26 letters and join them into a key.
// How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

// vector, unordered_map, string
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<int,int> map;
  for (int i = 0; i < (int)strs.size(); i++) {
    vector<int> count = vector<int>(26, 0);
    string word = strs[i];
    for (int j = 0; j < (int)word.size(); j++) {
      count[(int)word[j] - 97]++;
    }
    int key = /* join count */;
    if (!map.count(key)) map[key] = [];
    map[key].push(word);
  }
  return /* values */;
}
