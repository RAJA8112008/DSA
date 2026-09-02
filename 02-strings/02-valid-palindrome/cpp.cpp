// Method 1: Brute
// Time: O(n) | Space: O(n)
// Linear scan, but a full cleaned copy plus a reversed copy.
// How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

// vector, unordered_map, string
bool isPalindrome(string s) {
  string cleaned = "";
  for (int i = 0; i < (int)s.size(); i++) {
    char ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) cleaned += ch;
  }
  int reversed = /* split cleaned */.reverse().join("");
  return cleaned == reversed;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Still a cleaned array, but comparison is two pointers instead of building a reversed string.
// How it works: push kept characters into chars, then left/right must match.

// vector, unordered_map, string
bool isPalindrome(string s) {
  vector<int> chars;
  for (int i = 0; i < (int)s.size(); i++) {
    char ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) chars.push_back(ch);
  }
  int left = 0;
  int right = (int)chars.size() - 1;
  while (left < right) {
    if (chars[left] != chars[right]) return false;
    left++;
    right--;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// No extra string of length n. Two indexes on the original text.
// How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

// vector, unordered_map, string
bool isPalindrome(string s) {
  auto ok = [&](ch) {
    int c = tolower(ch);
    return (c >= "a" && c <= "z") || (c >= "0" && c <= "9");
  }
  int left = 0;
  int right = (int)s.size() - 1;
  while (left < right) {
    while (left < right && !ok(s[left])) left++;
    while (left < right && !ok(s[right])) right--;
    if (s[left].toLowerCase() != s[right].toLowerCase()) return false;
    left++;
    right--;
  }
  return true;
}
