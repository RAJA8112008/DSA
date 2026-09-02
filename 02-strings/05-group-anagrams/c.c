// Method 1: Brute
// Time: O(n² · k log k) | Space: O(n·k)
// Each word may be compared to every group representative. Each compare sorts a word of length k.
// How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

/* pass n for array length; simple loops */
int groupAnagrams(char strs[][64], int n) {
  void keyOf(/* word */) {
    return /* split word */.sort().join("");
  }
  int groups[1024]; int groups_n = 0;
  for (int i = 0; i < n; i++) {
    int k = keyOf(strs[i]);
    int placed = 0;
    for (int g = 0; g < groups_len; g++) {
      if (keyOf(groups[g][0]) == k) {
        groups[g].push(strs[i]);
        placed = 1;
        break;
      }
    }
    if (!placed) /* push */([strs[i]]);
  }
  return groups;
}


// Method 2: Optimal
// Time: O(n · k log k) | Space: O(n·k)
// One sort per word, then O(1) average map insert.
// How it works: map sorted-word -> list of originals. Return the map values.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int groupAnagrams(char strs[][64], int n) {
  int map_keys[1024]; int map_vals[1024]; int map_n = 0;
  for (int i = 0; i < n; i++) {
    char key[1024]; /* strs[i].split("").sort().join("") */
    if (!map_find(map_keys, map_n, key) >= 0) /* set map */;
    map.get(key).push(strs[i]);
  }
  return /* values */;
}


// Method 3: More optimal
// Time: O(n·k) | Space: O(n·k)
// No per-word sort. Count 26 letters and join them into a key.
// How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int groupAnagrams(char strs[][64], int n) {
  int map_keys[1024]; int map_vals[1024]; int map_n = 0;
  for (int i = 0; i < n; i++) {
    int count = /* zeros 26 */;
    char word[1024]; /* strs[i] */
    for (int j = 0; j < strlen(word); j++) {
      count[(int)word[j] - 97]++;
    }
    int key = /* join count */;
    if (!map_find(map_keys, map_n, key) >= 0) /* set map */;
    map.get(key).push(word);
  }
  return /* values */;
}
