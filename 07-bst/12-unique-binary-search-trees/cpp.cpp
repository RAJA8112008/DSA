// Method 1: Brute
// Time: O(4^n / n^{3/2}) | Space: O(n)
// Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int countLen(int len) {
    if (len <= 1) return 1;
    int total = 0;
    for (int left = 0; left < len; left++) total += countLen(left) * countLen(len - 1 - left);
    return total;
}
int numTrees(int n) { return countLen(n); }


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// dp[k] = number of BSTs on k keys. dp[0]=1. Each k sums dp[left]*dp[k-1-left]. Standard Catalan DP.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int numTrees(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int k = 1; k <= n; k++)
        for (int left = 0; left < k; left++) dp[k] += dp[left] * dp[k - 1 - left];
    return (int)dp[n];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int numTrees(int n) {
    long long c = 1;
    for (int i = 2; i <= n; i++) c = c * 2 * (2LL * i - 1) / (i + 1);
    return (int)c;
}
