// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

char* serialize(struct Node* root) {
    return stringify(root);
}

struct Node* deserialize(char* data) {
    if (data == "NULL") {
        return NULL;
    }
    return parse(data);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* serialize_go(struct Node* node) {
    if (!node) {
        out[outn++] = "N";
        return;
    }
    out[outn++] = /*str*/(node->val);
    serialize_go(node->left);
    serialize_go(node->right);
}

char* serialize(struct Node* root) {
    struct Node* out[10005]; int outn = 0;
    serialize_go(root);
    return join(",", out);
}

struct Node* deserialize_go() {
    int t = toks[i++];
    if (t == "N") {
        return NULL;
    }
    struct Node* node = newNode(atoi(t));
    node->left = deserialize_go();
    node->right = deserialize_go();
    return node;
}

struct Node* deserialize(char* data) {
    char* toks = split(data, ",");
    int i = 0;
    return deserialize_go();
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

char* serialize(struct Node* root) {
    if (!root) {
        return "N";
    }
    struct Node* out[10005]; int outn = 0;
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root;
    while (queuen) {
        struct Node* node = queue[queueh++];
        if (!node) {
            out[outn++] = "N";
            continue;
        }
        out[outn++] = /*str*/(node->val);
        queue[queuet++] = node->left;
        queue[queuet++] = node->right;
    }
    return join(",", out);
}

struct Node* deserialize(char* data) {
    char* toks = split(data, ",");
    if (toks[0] == "N") {
        return NULL;
    }
    struct Node* root = newNode(atoi(toks[0]));
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root;
    int i = 1;
    while (queuen && i < toksn) {
        struct Node* node = queue[queueh++];
        if (toks[i] != "N") {
            node->left = newNode(atoi(toks[i]));
            queue[queuet++] = node->left;
        }
        i++;
        if (i < toksn && toks[i] != "N") {
            node->right = newNode(atoi(toks[i]));
            queue[queuet++] = node->right;
        }
        i++;
    }
    return root;
}
