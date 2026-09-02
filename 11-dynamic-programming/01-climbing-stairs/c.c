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

int goClimb(int k, int *memo) {
    if (k <= 2) return k;
    if (memo[k] != -1) return memo[k];
    memo[k] = goClimb(k - 1, memo) + goClimb(k - 2, memo);
    return memo[k];
}
int climbStairs(int n) {
    int *memo = (int *)malloc((n + 1) * sizeof(int));
    int i, ans;
    for (i = 0; i <= n; i++) memo[i] = -1;
    ans = goClimb(n, memo);
    free(memo);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only the previous two answers are live. a is ways(i-2), b is ways(i-1). Slide them forward n-2 times. Time stays linear; extra memory is two numbers.

int climbStairs(int n) {
    int a, b, i, next;
    if (n <= 2) return n;
    a = 1;
    b = 2;
    for (i = 3; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}
