// Method 1: Brute
// Time: O(S) | Space: O(m)
// S is the total number of characters. Each word is compared to the current prefix from scratch.
// How it works: prefix starts as strs[0]. For each next word, cut prefix while it is not a prefix of that word.

// vector, unordered_map, string
string longestCommonPrefix(vector<string>& strs) {
  if (!(int)strs.size()) return "";
  string prefix = strs[0];
  for (int i = 1; i < (int)strs.size(); i++) {
    while (strs[i].indexOf(prefix) != 0) {
      prefix = prefix.substr(0, ((int)prefix.size() - 1)-(0));
      if (prefix == "") return "";
    }
  }
  return prefix;
}


// Method 2: Optimal
// Time: O(n log n + m) | Space: O(m)
// Sort the n words, then only the first and last can disagree. m is the shorter of those two.
// How it works: after sort, walk columns of first vs last until they differ. That slice is the prefix of the whole set.

// vector, unordered_map, string
string longestCommonPrefix(vector<string>& strs) {
  if (!(int)strs.size()) return "";
  string list = vector<int>(strs).sort();
  char first = list[0];
  int last = list[(int)list.size() - 1];
  int i = 0;
  while (i < (int)first.size() && i < (int)last.size() && first[i] == last[i]) i++;
  return vector<int>(first.begin()+(0), first.begin()+(i));
}


// Method 3: More optimal
// Time: O(S) | Space: O(1)
// No sort copy. Extra memory is a few indexes. Worst case still reads every character of every word until a mismatch.
// How it works: for column i of strs[0], every other word must have the same character. Return the slice before the first failure.

// vector, unordered_map, string
string longestCommonPrefix(vector<string>& strs) {
  if (!(int)strs.size()) return "";
  string first = strs[0];
  for (int i = 0; i < (int)first.size(); i++) {
    char ch = first[i];
    for (int j = 1; j < (int)strs.size(); j++) {
      if (i >= strs[j].length || strs[j][i] != ch) return first.substr(0, (i)-(0));
    }
  }
  return first;
}
