// Method 1: Brute
// Time: O(n^4) | Space: O(n)
// Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

bool ok(const string& part) {
  if (part.empty() || part.size() > 3) return false;
  if (part.size() > 1 && part[0] == '0') return false;
  int v = stoi(part);
  return v >= 0 && v <= 255;
}
vector<string> restoreIpAddresses(string s) {
  vector<string> ans;
  int n = (int)s.size();
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        string a = s.substr(0, i), b = s.substr(i, j - i), c = s.substr(j, k - j), d = s.substr(k);
        if (ok(a) && ok(b) && ok(c) && ok(d)) ans.push_back(a + "." + b + "." + c + "." + d);
      }
  return ans;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

bool ok(const string& part) {
  if (part.empty() || part.size() > 3) return false;
  if (part.size() > 1 && part[0] == '0') return false;
  return stoi(part) <= 255;
}
void go(string& s, int i, vector<string>& parts, vector<string>& ans) {
  if ((int)parts.size() == 4) {
    if (i == (int)s.size()) ans.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
    return;
  }
  for (int len = 1; len <= 3 && i + len <= (int)s.size(); len++) {
    string piece = s.substr(i, len);
    if (!ok(piece)) continue;
    parts.push_back(piece);
    go(s, i + len, parts, ans);
    parts.pop_back();
  }
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

void go(string& s, int i, vector<string>& parts, vector<string>& ans) {
  int leftParts = 4 - (int)parts.size();
  int leftChars = (int)s.size() - i;
  if (leftChars < leftParts || leftChars > 3 * leftParts) return;
  if ((int)parts.size() == 4) {
    ans.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
    return;
  }
  for (int len = 1; len <= 3 && i + len <= (int)s.size(); len++) {
    if (len > 1 && s[i] == '0') break;
    string piece = s.substr(i, len);
    if (stoi(piece) > 255) continue;
    parts.push_back(piece);
    go(s, i + len, parts, ans);
    parts.pop_back();
  }
}
