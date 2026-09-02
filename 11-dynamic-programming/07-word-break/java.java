// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

class Solution {
    public boolean wordBreak(String s, String[] wordDict) {
        return go(s, wordDict, 0);
    }
    private boolean go(String s, String[] wordDict, int i) {
        if (i == s.length()) return true;
        for (int w = 0; w < wordDict.length; w++) {
            String word = wordDict[w];
            if (s.startsWith(word, i) && go(s, wordDict, i + word.length())) return true;
        }
        return false;
    }
}


// Method 2: Optimal
// Time: O(n * m * L) | Space: O(n)
// Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

class Solution {
    public boolean wordBreak(String s, String[] wordDict) {
        Boolean[] memo = new Boolean[s.length()];
        return go(s, wordDict, 0, memo);
    }
    private boolean go(String s, String[] wordDict, int i, Boolean[] memo) {
        if (i == s.length()) return true;
        if (memo[i] != null) return memo[i];
        for (int w = 0; w < wordDict.length; w++) {
            String word = wordDict[w];
            if (s.startsWith(word, i) && go(s, wordDict, i + word.length(), memo)) {
                memo[i] = true;
                return true;
            }
        }
        memo[i] = false;
        return false;
    }
}


// Method 3: More optimal
// Time: O(n * m * L) | Space: O(n + m)
// Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

class Solution {
    public boolean wordBreak(String s, String[] wordDict) {
        java.util.HashSet<String> words = new java.util.HashSet<String>();
        for (int w = 0; w < wordDict.length; w++) words.add(wordDict[w]);
        int n = s.length();
        boolean[] can = new boolean[n + 1];
        can[0] = true;
        for (int i = 0; i < n; i++) {
            if (!can[i]) continue;
            for (String word : words) {
                if (s.startsWith(word, i)) can[i + word.length()] = true;
            }
        }
        return can[n];
    }
}
