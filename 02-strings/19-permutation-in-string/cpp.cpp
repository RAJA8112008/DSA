// Method 1: Brute
// Time: O(m! · n) | Space: O(m! · m)
// All unique perms of s1 are generated, then each is searched in s2. Factorial in m.
// How it works: backtracking builds permutations. indexOf each perm in s2; any hit is true.

// vector, unordered_map, string
bool checkInclusion(string s1, string s2) {
  vector<int> bag;
  auto permute = [&](arr, from) {
    if (from == (int)arr.size()) {
      bag.push_back(/* join arr */);
      return;
    }
    unordered_set<int> used;
    for (int i = from; i < (int)arr.size(); i++) {
      if (used.count(arr[i])) continue;
      used.insert(arr[i]);
      int t = arr[from];
      arr[from] = arr[i];
      arr[i] = t;
      permute(arr, from + 1);
      arr[i] = arr[from];
      arr[from] = t;
    }
  }
  permute(/* split s1 */, 0);
  for (int i = 0; i < (int)bag.size(); i++) {
    if ((int)s2.find(bag[i]) != -1) return true;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n · 26) | Space: O(1)
// Window of size m slides across s2. Each position compares two 26-slot arrays.
// How it works: need counts s1. have counts the current window. If they match, true. Slide by dropping left and adding right.

// vector, unordered_map, string
bool checkInclusion(string s1, string s2) {
  int m = (int)s1.size();
  int n = (int)s2.size();
  if (m > n) return false;
  vector<int> need = vector<int>(26, 0);
  vector<int> have = vector<int>(26, 0);
  for (int i = 0; i < m; i++) {
    need[(int)s1[i] - 97]++;
    have[(int)s2[i] - 97]++;
  }
  auto same = [&]() {
    for (int i = 0; i < 26; i++) if (need[i] != have[i]) return false;
    return true;
  }
  if (same()) return true;
  for (int right = m; right < n; right++) {
    have[(int)s2[right] - 97]++;
    have[(int)s2[right - m] - 97]--;
    if (same()) return true;
  }
  return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// matches tracks how many of the 26 letters currently have the right count. Each add/drop updates matches in O(1).
// How it works: when have[i] hits need[i], matches++. When it leaves, matches--. matches === 26 (or the number of letters that appear in s1) means the window is a permutation. Here we compare all 26 including zeros, so 26 is the target.

// vector, unordered_map, string
bool checkInclusion(string s1, string s2) {
  int m = (int)s1.size();
  int n = (int)s2.size();
  if (m > n) return false;
  vector<int> need = vector<int>(26, 0);
  vector<int> have = vector<int>(26, 0);
  for (int i = 0; i < m; i++) {
    need[(int)s1[i] - 97]++;
    have[(int)s2[i] - 97]++;
  }
  int matches = 0;
  for (int i = 0; i < 26; i++) if (need[i] == have[i]) matches++;
  if (matches == 26) return true;
  for (int right = m; right < n; right++) {
    int add = (int)s2[right] - 97;
    int drop = (int)s2[right - m] - 97;
    have[add]++;
    if (have[add] == need[add]) matches++;
    else if (have[add] == need[add] + 1) matches--;
    have[drop]--;
    if (have[drop] == need[drop]) matches++;
    else if (have[drop] == need[drop] - 1) matches--;
    if (matches == 26) return true;
  }
  return false;
}
