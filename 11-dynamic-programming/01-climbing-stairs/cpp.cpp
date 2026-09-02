// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each stair branches into two calls. The same k is solved again and again, so the tree is exponential. Space is the recursion depth n.

int climbStairs(int n) {
    if (n <= 2) return n;
    return climbStairs(n - 1) + climbStairs(n - 2);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Memo stores each k once. After the first fill, go(k) is a lookup. You still use O(n) stack plus O(n) memo cells. Same recurrence, no repeated subtrees.

int climbStairs(int n) {
    vector<int> memo(n + 1, -1);
    function<int(int)> go = [&](int k) -> int {
        if (k <= 2) return k;
        if (memo[k] != -1) return memo[k];
        memo[k] = go(k - 1) + go(k - 2);
        return memo[k];
    };
    return go(n);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only the previous two answers are live. a is ways(i-2), b is ways(i-1). Slide them forward n-2 times. Time stays linear; extra memory is two numbers.

int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}
