// Method 1: Brute
// Time: O(4^n / n^{3/2}) | Space: O(n)
// Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int numTrees(int n) {
    long long dp[25];
    int i, left, k;
    for (i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for (k = 1; k <= n; k++)
        for (left = 0; left < k; left++) dp[k] += dp[left] * dp[k - 1 - left];
    return (int)dp[n];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int numTrees(int n) {
    long long c = 1;
    for (int i = 2; i <= n; i++) c = c * 2 * (2LL * i - 1) / (i + 1);
    return (int)c;
}
