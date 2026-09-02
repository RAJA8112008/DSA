// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each position may branch into a 1-digit take and a 2-digit take. Overlapping suffixes are recomputed. Zeros prune some branches but the worst case is still exponential.

class Solution {
    public int numDecodings(String s) {
        return go(s, 0);
    }
    private int go(String s, int i) {
        if (i == s.length()) return 1;
        if (s.charAt(i) == '0') return 0;
        int ways = go(s, i + 1);
        if (i + 1 < s.length()) {
            int two = (s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0');
            if (two >= 10 && two <= 26) ways += go(s, i + 2);
        }
        return ways;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each start index is solved once. Work per index is O(1) digit checks. Memo of n cells plus the call stack. Linear in the length of s.

class Solution {
    public int numDecodings(String s) {
        Integer[] memo = new Integer[s.length()];
        return go(s, 0, memo);
    }
    private int go(String s, int i, Integer[] memo) {
        if (i == s.length()) return 1;
        if (s.charAt(i) == '0') return 0;
        if (memo[i] != null) return memo[i];
        int ways = go(s, i + 1, memo);
        if (i + 1 < s.length()) {
            int two = (s.charAt(i) - '0') * 10 + (s.charAt(i + 1) - '0');
            if (two >= 10 && two <= 26) ways += go(s, i + 2, memo);
        }
        memo[i] = ways;
        return ways;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// prev1 is ways for the prefix ending here, prev2 is ways for the prefix one shorter. A one-digit code adds prev1. A two-digit code adds prev2. Empty string and a leading zero are the bases. No array.

class Solution {
    public int numDecodings(String s) {
        if (s.length() == 0 || s.charAt(0) == '0') return 0;
        int prev2 = 1, prev1 = 1;
        for (int i = 1; i < s.length(); i++) {
            int cur = 0;
            if (s.charAt(i) != '0') cur += prev1;
            int two = (s.charAt(i - 1) - '0') * 10 + (s.charAt(i) - '0');
            if (two >= 10 && two <= 26) cur += prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
}
