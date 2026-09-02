// Method 1: Brute
// Time: O(n) get/put | Space: O(capacity)
// Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

import java.util.*;

class LRUCache {
    private int capacity;
    private List<int[]> data;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.data = new ArrayList<>();
    }
    public int get(int key) {
        int i = -1;
        for (int idx = 0; idx < data.size(); idx++) {
            if (data.get(idx)[0] == key) { i = idx; break; }
        }
        if (i < 0) return -1;
        int[] item = data.remove(i);
        data.add(item);
        return item[1];
    }
    public void put(int key, int value) {
        int i = -1;
        for (int idx = 0; idx < data.size(); idx++) {
            if (data.get(idx)[0] == key) { i = idx; break; }
        }
        if (i >= 0) data.remove(i);
        data.add(new int[]{key, value});
        if (data.size() > capacity) data.remove(0);
    }
}


// Method 2: Optimal
// Time: O(1) get/put | Space: O(capacity)
// Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

import java.util.*;

class LRUCache {
    private int capacity;
    private LinkedHashMap<Integer, Integer> map;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new LinkedHashMap<>(capacity, 0.75f, true);
    }
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        int value = map.get(key);
        map.remove(key);
        map.put(key, value);
        return value;
    }
    public void put(int key, int value) {
        if (map.containsKey(key)) map.remove(key);
        map.put(key, value);
        if (map.size() > capacity) {
            Integer oldest = map.keySet().iterator().next();
            map.remove(oldest);
        }
    }
}


// Method 3: More optimal
// Time: O(1) get/put | Space: O(capacity)
// Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

import java.util.*;

class DNode {
    int key;
    int val;
    DNode prev;
    DNode next;
    DNode(int key, int val) { this.key = key; this.val = val; }
}

class LRUCache {
    private int capacity;
    private Map<Integer, DNode> map;
    private DNode head, tail;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        head = new DNode(0, 0);
        tail = new DNode(0, 0);
        head.next = tail;
        tail.prev = head;
    }
    private void add(DNode node) {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
    private void remove(DNode node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        DNode node = map.get(key);
        remove(node);
        add(node);
        return node.val;
    }
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            remove(map.get(key));
            map.remove(key);
        }
        DNode node = new DNode(key, value);
        add(node);
        map.put(key, node);
        if (map.size() > capacity) {
            DNode lru = tail.prev;
            remove(lru);
            map.remove(lru.key);
        }
    }
}
