// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) ranges, each palindrome test O(n).
// How it works: for every i..j, two-pointer check. Increment count when it is a palindrome.

// vector, unordered_map, string
int countSubstrings(string s) {
  auto isPalin = [&](left, right) {
    while (left < right) {
      if (s[left] != s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  int count = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (isPalin(i, j)) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// A boolean table of n by n. Each cell is O(1) after shorter lengths are known.
// How it works: pal[i][j] is true if s[i]===s[j] and the inside is a palindrome (or the length is 1 or 2). Count every true cell.

// vector, unordered_map, string
int countSubstrings(string s) {
  int n = (int)s.size();
  vector<int> pal;
  for (int i = 0; i < n; i++) pal.push_back(vector<int>(n, 0));
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
        pal[i][j] = true;
        count++;
      }
    }
  }
  return count;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Same time, constant extra memory. Each palindrome is grown from a center.
// How it works: expand(left,right) counts while the letters match. Call expand(i,i) and expand(i,i+1) for every i.

// vector, unordered_map, string
int countSubstrings(string s) {
  int count = 0;
  auto expand = [&](left, right) {
    while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
      count++;
      left--;
      right++;
    }
  }
  for (int i = 0; i < (int)s.size(); i++) {
    expand(i, i);
    expand(i, i + 1);
  }
  return count;
}
