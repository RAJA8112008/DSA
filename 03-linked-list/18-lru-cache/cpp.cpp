// Method 1: Brute
// Time: O(n) get/put | Space: O(capacity)
// Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    vector<pair<int,int>> data;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        int i = -1;
        for (int idx = 0; idx < (int)data.size(); idx++) {
            if (data[idx].first == key) { i = idx; break; }
        }
        if (i < 0) return -1;
        pair<int,int> item = data[i];
        data.erase(data.begin() + i);
        data.push_back(item);
        return item.second;
    }
    void put(int key, int value) {
        int i = -1;
        for (int idx = 0; idx < (int)data.size(); idx++) {
            if (data[idx].first == key) { i = idx; break; }
        }
        if (i >= 0) data.erase(data.begin() + i);
        data.push_back({key, value});
        if ((int)data.size() > capacity) data.erase(data.begin());
    }
};


// Method 2: Optimal
// Time: O(1) get/put | Space: O(capacity)
// Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    list<pair<int,int>> order;
    unordered_map<int, list<pair<int,int>>::iterator> map;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    int get(int key) {
        if (!map.count(key)) return -1;
        auto it = map[key];
        int value = it->second;
        order.erase(it);
        order.push_front({key, value});
        map[key] = order.begin();
        return value;
    }
    void put(int key, int value) {
        if (map.count(key)) {
            order.erase(map[key]);
            map.erase(key);
        }
        order.push_front({key, value});
        map[key] = order.begin();
        if ((int)map.size() > capacity) {
            auto oldest = order.back();
            map.erase(oldest.first);
            order.pop_back();
        }
    }
};


// Method 3: More optimal
// Time: O(1) get/put | Space: O(capacity)
// Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

#include <bits/stdc++.h>
using namespace std;

struct DNode {
    int key, val;
    DNode* prev;
    DNode* next;
    DNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, DNode*> map;
    DNode* head;
    DNode* tail;
    void add(DNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void remove(DNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new DNode(0, 0);
        tail = new DNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    int get(int key) {
        if (!map.count(key)) return -1;
        DNode* node = map[key];
        remove(node);
        add(node);
        return node->val;
    }
    void put(int key, int value) {
        if (map.count(key)) {
            remove(map[key]);
            map.erase(key);
        }
        DNode* node = new DNode(key, value);
        add(node);
        map[key] = node;
        if ((int)map.size() > capacity) {
            DNode* lru = tail->prev;
            remove(lru);
            map.erase(lru->key);
        }
    }
};
