// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
// How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

// vector, unordered_map, string
string encode(vector<string>& strs) {
  return JSON.stringify(strs);
}
vector<string> decode(string s) {
  return JSON.parse(s);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
// How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

// vector, unordered_map, string
string encode(vector<string>& strs) {
  int header = to_string((int)strs.size());
  for (int i = 0; i < (int)strs.size(); i++) {
    header += "," + to_string(strs[i].length);
  }
  string body = "";
  for (int i = 0; i < (int)strs.size(); i++) body += strs[i];
  return header + "#" + body;
}
vector<string> decode(string s) {
  int hash = (int)s.find("#");
  string parts = s.substr(0, (hash)-(0)).split(",");
  int n = stoi(parts[0]);
  vector<int> out;
  int pos = hash + 1;
  for (int i = 0; i < n; i++) {
    int len = stoi(parts[i + 1]);
    out.push_back(s.substr(pos, (pos + len)-(pos)));
    pos += len;
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
// How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

// vector, unordered_map, string
string encode(vector<string>& strs) {
  string out = "";
  for (int i = 0; i < (int)strs.size(); i++) {
    out += to_string(strs[i].length) + "#" + strs[i];
  }
  return out;
}
vector<string> decode(string s) {
  vector<int> out;
  int i = 0;
  while (i < (int)s.size()) {
    int j = i;
    while (s[j] != "#") j++;
    string len = stoi(s.substr(i, (j)-(i)));
    string word = s.substr(j + 1, (j + 1 + len)-(j + 1));
    out.push_back(word);
    i = j + 1 + len;
  }
  return out;
}
