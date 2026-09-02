// Method 1: Brute
// Time: O(n²) | Space: O(n)
// n candidate strings after deleting one index, each palindrome check is O(n).
// How it works: if s is already a palindrome, true. Else for each i, check s without index i.

// vector, unordered_map, string
bool validPalindrome(string s) {
  auto isPalin = [&](text) {
    int left = 0;
    int right = (int)text.size() - 1;
    while (left < right) {
      if (text[left] != text[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  if (isPalin(s)) return true;
  for (int i = 0; i < (int)s.size(); i++) {
    if (isPalin(s.substr(0, (i)-(0)) + s.substr(i + 1))) return true;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One mismatch, then two extra strings of length n-1.
// How it works: walk inward. On mismatch, test skip-left and skip-right by slicing. If the whole walk succeeds, no deletion was needed.

// vector, unordered_map, string
bool validPalindrome(string s) {
  auto isPalin = [&](text) {
    int left = 0;
    int right = (int)text.size() - 1;
    while (left < right) {
      if (text[left] != text[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  int left = 0;
  int right = (int)s.size() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      string skipL = s.substr(left + 1, (right + 1)-(left + 1));
      string skipR = s.substr(left, (right)-(left));
      return isPalin(skipL) || isPalin(skipR);
    }
    left++;
    right--;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Range checks use indexes only. No sliced copies.
// How it works: palin(l,r) checks a range. On the first mismatch, return palin(left+1, right) or palin(left, right-1).

// vector, unordered_map, string
bool validPalindrome(string s) {
  auto palin = [&](left, right) {
    while (left < right) {
      if (s[left] != s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  int left = 0;
  int right = (int)s.size() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return palin(left + 1, right) || palin(left, right - 1);
    }
    left++;
    right--;
  }
  return true;
}
