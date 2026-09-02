// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each pass scans the whole string and removes one pair. Up to n/2 passes.
// How it works: while any "()", "[]", or "{}" remains, split-join it away. Success is an empty string.

// vector, unordered_map, string
bool isValid(string s) {
  int cur = s;
  bool changed = true;
  while (changed) {
    int next = /* split cur */.join("").split("[]").join("").split("{}").join("");
    changed = next != cur;
    cur = next;
  }
  return (int)cur.size() == 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One pass. Stack holds at most n openers.
// How it works: push openers. On a closer, pop and check it is the matching opener. Leftover openers fail.

// vector, unordered_map, string
bool isValid(string s) {
  vector<int> stack;
  for (int i = 0; i < (int)s.size(); i++) {
    char ch = s[i];
    if (ch == "(" || ch == "[" || ch == "{") {
      stack.push_back(ch);
    } else {
      int top = ({ auto _t=stack.back(); stack.pop_back(); _t; });
      if (ch == ")" && top != "(") return false;
      if (ch == "]" && top != "[") return false;
      if (ch == "}" && top != "{") return false;
    }
  }
  return (int)stack.size() == 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same O(n) bound. A pair map avoids three mismatch branches, and odd length fails immediately.
// How it works: if the character is a key in pairs, it is a closer: pop must equal pairs[ch]. Else it is an opener: push.

// vector, unordered_map, string
bool isValid(string s) {
  if ((int)s.size() % 2 == 1) return false;
  int pairs = { ")": "(", "]": "[", "}": "{" };
  vector<int> stack;
  for (int i = 0; i < (int)s.size(); i++) {
    char ch = s[i];
    if (pairs[ch]) {
      if (({ auto _t=stack.back(); stack.pop_back(); _t; }) != pairs[ch]) return false;
    } else {
      stack.push_back(ch);
    }
  }
  return (int)stack.size() == 0;
}
