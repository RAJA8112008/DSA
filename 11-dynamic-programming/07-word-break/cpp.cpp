// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

bool wordGo(const string& s, vector<string>& wordDict, int i) {
    if (i == (int)s.size()) return true;
    for (int w = 0; w < (int)wordDict.size(); w++) {
        const string& word = wordDict[w];
        if (s.compare(i, word.size(), word) == 0 && wordGo(s, wordDict, i + (int)word.size())) {
            return true;
        }
    }
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    return wordGo(s, wordDict, 0);
}


// Method 2: Optimal
// Time: O(n * m * L) | Space: O(n)
// Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

bool wordGo(const string& s, vector<string>& wordDict, int i, vector<int>& memo) {
    if (i == (int)s.size()) return true;
    if (memo[i] != -1) return memo[i];
    for (int w = 0; w < (int)wordDict.size(); w++) {
        const string& word = wordDict[w];
        if (s.compare(i, word.size(), word) == 0 && wordGo(s, wordDict, i + (int)word.size(), memo)) {
            memo[i] = 1;
            return true;
        }
    }
    memo[i] = 0;
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    vector<int> memo(s.size(), -1);
    return wordGo(s, wordDict, 0, memo);
}


// Method 3: More optimal
// Time: O(n * m * L) | Space: O(n + m)
// Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<char> can(n + 1, 0);
    can[0] = 1;
    for (int i = 0; i < n; i++) {
        if (!can[i]) continue;
        for (const string& word : words) {
            if (s.compare(i, word.size(), word) == 0) can[i + (int)word.size()] = 1;
        }
    }
    return can[n];
}
