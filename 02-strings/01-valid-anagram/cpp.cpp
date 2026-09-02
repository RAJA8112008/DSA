// Method 1: Brute
// Time: O(n²) | Space: O(n)
// For each letter in s you search t and splice it out. Each splice is O(n), so quadratic.
// How it works: copy t into an array. For every character of s, indexOf that character in the copy; if missing, false; else splice it out. Empty copy at the end means success.

// vector, unordered_map, string
bool isAnagram(string s, string t) {
  if ((int)s.size() != (int)t.size()) return false;
  int letters = /* split t */;
  for (int i = 0; i < (int)s.size(); i++) {
    int idx = (int)letters.find(s[i]);
    if (idx == -1) return false;
    letters.erase(letters.begin()+(idx));
  }
  return (int)letters.size() == 0;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting both strings dominates. Extra arrays hold the split characters.
// How it works: sort the character lists and compare them index by index.

// vector, unordered_map, string
bool isAnagram(string s, string t) {
  if ((int)s.size() != (int)t.size()) return false;
  int a = /* split s */.sort();
  int b = /* split t */.sort();
  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass over both strings and 26 integers. For lowercase a-z the extra space is constant.
// How it works: count[s[i]]++, count[t[i]]--. If every slot is 0, the bags of letters matched.

// vector, unordered_map, string
bool isAnagram(string s, string t) {
  if ((int)s.size() != (int)t.size()) return false;
  vector<int> count = vector<int>(26, 0);
  for (int i = 0; i < (int)s.size(); i++) {
    count[(int)s[i] - 97]++;
    count[(int)t[i] - 97]--;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) return false;
  }
  return true;
}
