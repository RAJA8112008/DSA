// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Each pass scans the whole string and removes one pair. Up to n/2 passes.
// How it works: while any "()", "[]", or "{}" remains, split-join it away. Success is an empty string.

/* pass n for array length; simple loops */
int isValid(char* s) {
  int cur = s;
  int changed = 1;
  while (changed) {
    int next = /* split cur */.join("").split("[]").join("").split("{}").join("");
    changed = next != cur;
    cur = next;
  }
  return cur_len == 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One pass. Stack holds at most n openers.
// How it works: push openers. On a closer, pop and check it is the matching opener. Leftover openers fail.

/* pass n for array length; simple loops */
int isValid(char* s) {
  int stack[1024]; int stack_n = 0;
  for (int i = 0; i < strlen(s); i++) {
    int ch = s[i];
    if (ch == "(" || ch == "[" || ch == "{") {
      /* push */(ch);
    } else {
      int top = /* pop */;
      if (ch == ")" && top != "(") return 0;
      if (ch == "]" && top != "[") return 0;
      if (ch == "}" && top != "{") return 0;
    }
  }
  return stack_len == 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same O(n) bound. A pair map avoids three mismatch branches, and odd length fails immediately.
// How it works: if the character is a key in pairs, it is a closer: pop must equal pairs[ch]. Else it is an opener: push.

/* pass n for array length; simple loops */
int isValid(char* s) {
  if (strlen(s) % 2 == 1) return 0;
  int pairs = { ")": "(", "]": "[", "}": "{" };
  int stack[1024]; int stack_n = 0;
  for (int i = 0; i < strlen(s); i++) {
    int ch = s[i];
    if (pairs[ch]) {
      if (/* pop */ != pairs[ch]) return 0;
    } else {
      /* push */(ch);
    }
  }
  return stack_len == 0;
}
