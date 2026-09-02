// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Count with nested scans: for each character type, walk the whole string. Slow counting, same final formula.
// How it works: collect unique letters. For each letter, count occurrences with a full scan. Add even parts; remember if any odd exists; add 1 for a center.

// vector, unordered_map, string
int longestPalindrome(string s) {
  vector<int> letters;
  for (int i = 0; i < (int)s.size(); i++) {
    if ((int)letters.find(s[i]) == -1) letters.push_back(s[i]);
  }
  int len = 0;
  bool odd = false;
  for (int L = 0; L < (int)letters.size(); L++) {
    int c = 0;
    for (int i = 0; i < (int)s.size(); i++) if (s[i] == letters[L]) c++;
    len += c - (c % 2);
    if (c % 2 == 1) odd = true;
  }
  return odd ? len + 1 : len;
}


// Method 2: Optimal
// Time: O(n) | Space: O(k)
// One pass to count, one pass over unique keys. k is the alphabet size.
// How it works: object/map frequencies. Even contribution is count - count%2. One leftover odd becomes the center.

// vector, unordered_map, string
int longestPalindrome(string s) {
  unordered_map<int,int> count;
  for (int i = 0; i < (int)s.size(); i++) {
    char ch = s[i];
    count[ch] = (count[ch] || 0) + 1;
  }
  int len = 0;
  bool odd = false;
  for (auto ch : count) {
    len += count[ch] - (count[ch] % 2);
    if (count[ch] % 2 == 1) odd = true;
  }
  return odd ? len + 1 : len;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// 128 slots cover ASCII letters used in the usual prompt. Extra memory is constant.
// How it works: count[charCode]++. Same even/odd rule on the 128 numbers. Equivalent: len += count[i] & ~1, then if len < s.length add 1.

// vector, unordered_map, string
int longestPalindrome(string s) {
  vector<int> count = vector<int>(128, 0);
  for (int i = 0; i < (int)s.size(); i++) count[(int)s[i]]++;
  int len = 0;
  for (int i = 0; i < 128; i++) len += count[i] - (count[i] % 2);
  if (len < (int)s.size()) len += 1;
  return len;
}
