// Method 1: Brute
// Time: O(n) | Space: O(n)
// Library split/filter/reverse/join still copies the string.
// How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

// vector, unordered_map, string
string reverseWords(string s) {
  int words = /* split s */.__FILTERNZ();
  words.reverse();
  return /* join words */;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
// How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

// vector, unordered_map, string
string reverseWords(string s) {
  vector<int> words;
  int i = 0;
  while (i < (int)s.size()) {
    while (i < (int)s.size() && s[i] == " ") i++;
    if (i >= (int)s.size()) break;
    int j = i;
    while (j < (int)s.size() && s[j] != " ") j++;
    words.push_back(s.substr(i, (j)-(i)));
    i = j;
  }
  string out = "";
  for (int k = (int)words.size() - 1; k >= 0; k--) {
    if ((int)out.size()) out += " ";
    out += words[k];
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
// How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

// vector, unordered_map, string
string reverseWords(string s) {
  auto reverse = [&](arr, left, right) {
    while (left < right) {
      int t = arr[left];
      arr[left] = arr[right];
      arr[right] = t;
      left++;
      right--;
    }
  }
  vector<int> chars;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == " " && ((int)chars.size() == 0 || chars[(int)chars.size() - 1] == " ")) continue;
    chars.push_back(s[i]);
  }
  while ((int)chars.size() && chars[(int)chars.size() - 1] == " ") ({ auto _t=chars.back(); chars.pop_back(); _t; });
  reverse(chars, 0, (int)chars.size() - 1);
  int start = 0;
  for (int i = 0; i <= (int)chars.size(); i++) {
    if (i == (int)chars.size() || chars[i] == " ") {
      reverse(chars, start, i - 1);
      start = i + 1;
    }
  }
  return /* join chars */;
}
