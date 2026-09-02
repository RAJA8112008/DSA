// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

int startsAt(const char *s, int i, const char *word) {
    int k = 0;
    while (word[k]) {
        if (s[i + k] != word[k]) return 0;
        k++;
    }
    return 1;
}
int wordGo(const char *s, char **wordDict, int m, int i) {
    int w, len;
    if (s[i] == 0) return 1;
    for (w = 0; w < m; w++) {
        len = (int)strlen(wordDict[w]);
        if (startsAt(s, i, wordDict[w]) && wordGo(s, wordDict, m, i + len)) return 1;
    }
    return 0;
}
int wordBreak(const char *s, char **wordDict, int m) {
    return wordGo(s, wordDict, m, 0);
}


// Method 2: Optimal
// Time: O(n * m * L) | Space: O(n)
// Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

int startsAt(const char *s, int i, const char *word) {
    int k = 0;
    while (word[k]) {
        if (s[i + k] != word[k]) return 0;
        k++;
    }
    return 1;
}
int wordGo(const char *s, char **wordDict, int m, int i, int *memo) {
    int w, len;
    if (s[i] == 0) return 1;
    if (memo[i] != -1) return memo[i];
    for (w = 0; w < m; w++) {
        len = (int)strlen(wordDict[w]);
        if (startsAt(s, i, wordDict[w]) && wordGo(s, wordDict, m, i + len, memo)) {
            memo[i] = 1;
            return 1;
        }
    }
    memo[i] = 0;
    return 0;
}
int wordBreak(const char *s, char **wordDict, int m) {
    int n = (int)strlen(s);
    int *memo = (int *)malloc(n * sizeof(int));
    int i, ans;
    for (i = 0; i < n; i++) memo[i] = -1;
    ans = wordGo(s, wordDict, m, 0, memo);
    free(memo);
    return ans;
}


// Method 3: More optimal
// Time: O(n * m * L) | Space: O(n + m)
// Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

int startsAt(const char *s, int i, const char *word) {
    int k = 0;
    while (word[k]) {
        if (s[i + k] != word[k]) return 0;
        k++;
    }
    return 1;
}
int wordBreak(const char *s, char **wordDict, int m) {
    int n = (int)strlen(s);
    int *can = (int *)calloc(n + 1, sizeof(int));
    int i, w, ans;
    can[0] = 1;
    for (i = 0; i < n; i++) {
        if (!can[i]) continue;
        for (w = 0; w < m; w++) {
            int len = (int)strlen(wordDict[w]);
            if (startsAt(s, i, wordDict[w])) can[i + len] = 1;
        }
    }
    ans = can[n];
    free(can);
    return ans;
}
