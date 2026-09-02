// Method 1: Brute
// Time: O(n) get/put | Space: O(capacity)
// Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

#include <stdlib.h>

typedef struct { int key; int value; } Pair;

typedef struct {
    int capacity;
    Pair data[10005];
    int n;
} LRUCache;

void lruInit(LRUCache* c, int capacity) {
    c->capacity = capacity;
    c->n = 0;
}

int lruGet(LRUCache* c, int key) {
    int i = -1;
    for (int idx = 0; idx < c->n; idx++) {
        if (c->data[idx].key == key) { i = idx; break; }
    }
    if (i < 0) return -1;
    Pair item = c->data[i];
    for (int j = i; j < c->n - 1; j++) c->data[j] = c->data[j + 1];
    c->data[c->n - 1] = item;
    return item.value;
}

void lruPut(LRUCache* c, int key, int value) {
    int i = -1;
    for (int idx = 0; idx < c->n; idx++) {
        if (c->data[idx].key == key) { i = idx; break; }
    }
    if (i >= 0) {
        for (int j = i; j < c->n - 1; j++) c->data[j] = c->data[j + 1];
        c->n--;
    }
    c->data[c->n].key = key;
    c->data[c->n].value = value;
    c->n++;
    if (c->n > c->capacity) {
        for (int j = 0; j < c->n - 1; j++) c->data[j] = c->data[j + 1];
        c->n--;
    }
}


// Method 2: Optimal
// Time: O(1) get/put | Space: O(capacity)
// Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

#include <stdlib.h>

typedef struct Item {
    int key;
    int value;
    struct Item* prev;
    struct Item* next;
} Item;

#define TAB 4099

typedef struct {
    int capacity;
    int size;
    Item* head;
    Item* tail;
    Item* table[TAB];
} LRUCache;

static unsigned hkey(int k) { return ((unsigned)k * 2654435761u) % TAB; }

static Item* find(LRUCache* c, int key) {
    for (Item* p = c->table[hkey(key)]; p; p = p->next) {
        /* linear list is recency; table is not chained by key — scan recency list */
    }
    for (Item* p = c->head; p; p = p->next) if (p->key == key) return p;
    return NULL;
}

void lruInit(LRUCache* c, int capacity) {
    c->capacity = capacity;
    c->size = 0;
    c->head = c->tail = NULL;
}

int lruGet(LRUCache* c, int key) {
    Item* p = find(c, key);
    if (!p) return -1;
    if (p != c->tail) {
        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        if (p == c->head) c->head = p->next;
        p->prev = c->tail;
        p->next = NULL;
        if (c->tail) c->tail->next = p;
        c->tail = p;
        if (!c->head) c->head = p;
    }
    return p->value;
}

void lruPut(LRUCache* c, int key, int value) {
    Item* p = find(c, key);
    if (p) {
        p->value = value;
        lruGet(c, key);
        return;
    }
    Item* n = (Item*)malloc(sizeof(Item));
    n->key = key; n->value = value; n->prev = c->tail; n->next = NULL;
    if (c->tail) c->tail->next = n; else c->head = n;
    c->tail = n;
    c->size++;
    if (c->size > c->capacity) {
        Item* old = c->head;
        c->head = old->next;
        if (c->head) c->head->prev = NULL;
        else c->tail = NULL;
        free(old);
        c->size--;
    }
}


// Method 3: More optimal
// Time: O(1) get/put | Space: O(capacity)
// Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

#include <stdlib.h>

struct DNode {
    int key;
    int val;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* newDNode(int key, int val) {
    struct DNode* n = (struct DNode*)malloc(sizeof(struct DNode));
    n->key = key; n->val = val; n->prev = NULL; n->next = NULL;
    return n;
}

#define TAB 4099

typedef struct {
    int capacity;
    int size;
    struct DNode* head;
    struct DNode* tail;
    struct DNode* map[TAB];
    int mapKeys[TAB];
    int mapUsed[TAB];
} LRUCache;

static int slot(LRUCache* c, int key, int create) {
    unsigned h = (unsigned)key * 2654435761u;
    for (int i = 0; i < TAB; i++) {
        int s = (h + i) % TAB;
        if (!c->mapUsed[s]) {
            if (!create) return -1;
            c->mapUsed[s] = 1;
            c->mapKeys[s] = key;
            return s;
        }
        if (c->mapKeys[s] == key) return s;
    }
    return -1;
}

static void add(LRUCache* c, struct DNode* node) {
    node->next = c->head->next;
    node->prev = c->head;
    c->head->next->prev = node;
    c->head->next = node;
}

static void removeNode(struct DNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void lruInit(LRUCache* c, int capacity) {
    c->capacity = capacity;
    c->size = 0;
    c->head = newDNode(0, 0);
    c->tail = newDNode(0, 0);
    c->head->next = c->tail;
    c->tail->prev = c->head;
    for (int i = 0; i < TAB; i++) c->mapUsed[i] = 0;
}

int lruGet(LRUCache* c, int key) {
    int s = slot(c, key, 0);
    if (s < 0) return -1;
    struct DNode* node = c->map[s];
    removeNode(node);
    add(c, node);
    return node->val;
}

void lruPut(LRUCache* c, int key, int value) {
    int s = slot(c, key, 0);
    if (s >= 0) {
        removeNode(c->map[s]);
        c->mapUsed[s] = 0;
        c->size--;
    }
    struct DNode* node = newDNode(key, value);
    add(c, node);
    s = slot(c, key, 1);
    c->map[s] = node;
    c->size++;
    if (c->size > c->capacity) {
        struct DNode* lru = c->tail->prev;
        removeNode(lru);
        int t = slot(c, lru->key, 0);
        if (t >= 0) c->mapUsed[t] = 0;
        c->size--;
    }
}
