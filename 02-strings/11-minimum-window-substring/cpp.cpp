// Method 1: Brute
// Time: O(n² · k) | Space: O(k)
// Every i..j window rebuilds counts against t. k is the alphabet / unique letters in t.
// How it works: covers() copies t’s need map and decrements for each character of the slice. Keep the shortest slice that covers.

// vector, unordered_map, string
string minWindow(string s, string t) {
  auto covers = [&](slice) {
    unordered_map<int,int> need;
    for (int i = 0; i < (int)t.size(); i++) {
      need[t[i]] = (need.count(t[i] ? need[t[i]] : 0) + 1);
    }
    for (int i = 0; i < (int)slice.size(); i++) {
      char ch = slice[i];
      if (need.count(ch)) {
        need[ch] = need[ch] - 1;
        if (need[ch] == 0) need.erase(ch);
      }
    }
    return need.size() == 0;
  }
  string best = "";
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = i; j < (int)s.size(); j++) {
      string slice = s.substr(i, (j + 1)-(i));
      if (covers(slice) && (best == "" || (int)slice.size() < (int)best.size())) best = slice;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(k)
// From each left, grow right until t is covered, then record and try the next left. Still quadratic starts.
// How it works: missing starts as t.length. A need map counts t. As right adds characters, missing drops. First time missing hits 0, that window is a candidate.

// vector, unordered_map, string
string minWindow(string s, string t) {
  if ((int)t.size() > (int)s.size()) return "";
  string best = "";
  for (int left = 0; left < (int)s.size(); left++) {
    unordered_map<int,int> need;
    for (int i = 0; i < (int)t.size(); i++) need[t[i]] = (need.count(t[i] ? need[t[i]] : 0) + 1);
    int missing = (int)t.size();
    for (int right = left; right < (int)s.size(); right++) {
      char ch = s[right];
      if (need.count(ch) && need[ch] > 0) missing--;
      if (need.count(ch)) need[ch] = need[ch] - 1;
      if (missing == 0) {
        string slice = s.substr(left, (right + 1)-(left));
        if (best == "" || (int)slice.size() < (int)best.size()) best = slice;
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

// vector, unordered_map, string
string minWindow(string s, string t) {
  if ((int)t.size() > (int)s.size()) return "";
  unordered_map<int,int> need;
  for (int i = 0; i < (int)t.size(); i++) need[t[i]] = (need.count(t[i] ? need[t[i]] : 0) + 1);
  unordered_map<int,int> have;
  int formed = 0;
  int needCount = need.size();
  int bestL = 0;
  int bestR = -1;
  int left = 0;
  for (int right = 0; right < (int)s.size(); right++) {
    char ch = s[right];
    have[ch] = (have.count(ch ? have[ch] : 0) + 1);
    if (need.count(ch) && have[ch] == need[ch]) formed++;
    while (formed == needCount) {
      if (bestR == -1 || right - left < bestR - bestL) {
        bestL = left;
        bestR = right;
      }
      char drop = s[left];
      have[drop] = have[drop] - 1;
      if (need.count(drop) && have[drop] < need[drop]) formed--;
      left++;
    }
  }
  return bestR == -1 ? "" : s.substr(bestL, (bestR + 1)-(bestL));
}
