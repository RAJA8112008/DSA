// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each stair branches into two calls. The same k is solved again and again, so the tree is exponential. Space is the recursion depth n.

class Solution {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Memo stores each k once. After the first fill, go(k) is a lookup. You still use O(n) stack plus O(n) memo cells. Same recurrence, no repeated subtrees.

class Solution {
    public int climbStairs(int n) {
        Integer[] memo = new Integer[n + 1];
        return go(n, memo);
    }
    private int go(int k, Integer[] memo) {
        if (k <= 2) return k;
        if (memo[k] != null) return memo[k];
        memo[k] = go(k - 1, memo) + go(k - 2, memo);
        return memo[k];
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only the previous two answers are live. a is ways(i-2), b is ways(i-1). Slide them forward n-2 times. Time stays linear; extra memory is two numbers.

class Solution {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }
        return b;
    }
}
