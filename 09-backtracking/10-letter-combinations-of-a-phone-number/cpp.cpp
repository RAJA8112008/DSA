// Method 1: Brute
// Time: O(4^n * n) | Space: O(4^n * n)
// Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

void go(string& digits, int i, string path, vector<string>& ans, string* mp) {
  if (i == (int)digits.size()) { ans.push_back(path); return; }
  string letters = mp[digits[i] - '0'];
  for (char ch : letters) go(digits, i + 1, path + ch, ans, mp);
}


// Method 2: Optimal
// Time: O(4^n * n) | Space: O(n)
// One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

void go(string& digits, int i, string& path, vector<string>& ans, string* mp) {
  if (i == (int)digits.size()) { ans.push_back(path); return; }
  for (char ch : mp[digits[i] - '0']) {
    path.push_back(ch);
    go(digits, i + 1, path, ans, mp);
    path.pop_back();
  }
}


// Method 3: More optimal
// Time: O(4^n * n) | Space: O(4^n * n)
// Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

vector<string> letterCombinations(string digits) {
  if (digits.empty()) return {};
  string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> cur = {""};
  for (char d : digits) {
    vector<string> next;
    for (auto& prefix : cur) for (char ch : mp[d - '0']) next.push_back(prefix + ch);
    cur.swap(next);
  }
  return cur;
}
