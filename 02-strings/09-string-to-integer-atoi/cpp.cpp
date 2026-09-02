// Method 1: Brute
// Time: O(n) | Space: O(n)
// You still walk the string once, but you build a digit string and use Number, then clamp.
// How it works: skip spaces, note sign, gather digits into text. Number(text) * sign, then clamp to 32-bit bounds.

// vector, unordered_map, string
int myAtoi(string s) {
  int i = 0;
  int n = (int)s.size();
  while (i < n && s[i] == " ") i++;
  int sign = 1;
  if (i < n && (s[i] == "+" || s[i] == "-")) {
    if (s[i] == "-") sign = -1;
    i++;
  }
  string digits = "";
  while (i < n && s[i] >= "0" && s[i] <= "9") {
    digits += s[i];
    i++;
  }
  if ((int)digits.size() == 0) return 0;
  int num = sign * stoi(digits);
  int lo = -2147483648;
  int hi = 2147483647;
  if (num < lo) return lo;
  if (num > hi) return hi;
  return num;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// No digit string. A running number. Clamp after the loop (JS Number can hold these intermediates).
// How it works: same skip/sign walk. num = num * 10 + digit. Then clamp.

// vector, unordered_map, string
int myAtoi(string s) {
  int i = 0;
  int n = (int)s.size();
  while (i < n && s[i] == " ") i++;
  int sign = 1;
  if (i < n && (s[i] == "+" || s[i] == "-")) {
    if (s[i] == "-") sign = -1;
    i++;
  }
  int num = 0;
  while (i < n && s[i] >= "0" && s[i] <= "9") {
    num = num * 10 + ((int)s[i] - 48);
    i++;
  }
  num *= sign;
  int lo = -2147483648;
  int hi = 2147483647;
  if (num < lo) return lo;
  if (num > hi) return hi;
  return num;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Overflow is stopped as soon as the next digit would leave 32-bit range, matching a language without big numbers.
// How it works: before num = num*10 + d, if num > 214748364 or (num === 214748364 and d > 7), return the clamped bound for this sign.

// vector, unordered_map, string
int myAtoi(string s) {
  int i = 0;
  int n = (int)s.size();
  int lo = -2147483648;
  int hi = 2147483647;
  while (i < n && s[i] == " ") i++;
  int sign = 1;
  if (i < n && (s[i] == "+" || s[i] == "-")) {
    if (s[i] == "-") sign = -1;
    i++;
  }
  int num = 0;
  while (i < n && s[i] >= "0" && s[i] <= "9") {
    int d = (int)s[i] - 48;
    if (num > 214748364 || (num == 214748364 && d > 7)) {
      return sign == 1 ? hi : lo;
    }
    num = num * 10 + d;
    i++;
  }
  return num * sign;
}
