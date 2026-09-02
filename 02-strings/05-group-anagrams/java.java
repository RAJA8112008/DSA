// Method 1: Brute
// Time: O(n² · k log k) | Space: O(n·k)
// Each word may be compared to every group representative. Each compare sorts a word of length k.
// How it works: for each word, look for a group whose first word sorts equal to this word. If none, start a new group.

class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    public void keyOf(word) {
      return word.split("").sort().join("");
    }
    List<Integer> groups = new ArrayList<>();
    for (int i = 0; i < strs.length; i++) {
      int k = keyOf(strs[i]);
      boolean placed = false;
      for (int g = 0; g < groups.size(); g++) {
        if (keyOf(groups[g][0]) == k) {
          groups[g].push(strs[i]);
          placed = true;
          break;
        }
      }
      if (!placed) groups.add([strs[i]]);
    }
    return groups;
  }
}


// Method 2: Optimal
// Time: O(n · k log k) | Space: O(n·k)
// One sort per word, then O(1) average map insert.
// How it works: map sorted-word -> list of originals. Return the map values.

class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    Map<String, List<String>> map = new HashMap<>();
    for (int i = 0; i < strs.length; i++) {
      String key = strs[i].split("").sort().join("");
      if (!map.containsKey(key)) map.put(key, []);
      map.get(key).push(strs[i]);
    }
    return new ArrayList<>(map.values());
  }
}


// Method 3: More optimal
// Time: O(n·k) | Space: O(n·k)
// No per-word sort. Count 26 letters and join them into a key.
// How it works: count[c]++ for each character. key is the 26 numbers joined by commas so 1,11 does not collide with 11,1.

class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    Map<String, List<String>> map = new HashMap<>();
    for (int i = 0; i < strs.length; i++) {
      int[] count = new int[26];
      String word = strs[i];
      for (int j = 0; j < word.length(); j++) {
        count[(int)word.charAt(j) - 97]++;
      }
      int key = String.join(",", count);
      if (!map.containsKey(key)) map.put(key, []);
      map.get(key).push(word);
    }
    return new ArrayList<>(map.values());
  }
}
