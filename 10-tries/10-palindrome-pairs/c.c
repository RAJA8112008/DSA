// Method 1: Brute
// Time: O(n^2 L) | Space: O(1)
// For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

int isPal(const char* s) {
  int i = 0, j = (int)strlen(s) - 1;
  while (i < j) { if (s[i] != s[j]) return 0; i++; j--; }
  return 1;
}


// Method 2: Optimal
// Time: O(n L^2) | Space: O(n L)
// Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

/* map each word to index; try every split; reverse with a temp buffer */


// Method 3: More optimal
// Time: O(n L^2) | Space: O(n L)
// Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

/* reverse-insert each word into a 26-way trie; palBelow lists indexes
   whose remaining prefix (in original order) is a palindrome */
