// Method 1: Brute
// Time: O(k^t) | Space: O(k)
// At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

import java.util.*;
class Solution {
  int best;
  int left(Map<Character, Integer> count) {
    int s = 0; for (int v : count.values()) s += v; return s;
  }
  void dfs(int time, Map<Character, Integer> count, Map<Character, Integer> cool, int n) {
    if (time >= best) return;
    if (left(count) == 0) { best = time; return; }
    boolean placed = false;
    for (char t : new ArrayList<Character>(count.keySet())) {
      if (count.get(t) == 0) continue;
      if (cool.getOrDefault(t, 0) > time) continue;
      placed = true;
      count.put(t, count.get(t) - 1);
      int old = cool.getOrDefault(t, 0);
      cool.put(t, time + n + 1);
      dfs(time + 1, count, cool, n);
      cool.put(t, old);
      count.put(t, count.get(t) + 1);
    }
    if (!placed) dfs(time + 1, count, cool, n);
  }
  public int leastInterval(char[] tasks, int n) {
    Map<Character, Integer> count = new HashMap<Character, Integer>();
    for (char t : tasks) count.put(t, count.getOrDefault(t, 0) + 1);
    best = Integer.MAX_VALUE;
    dfs(0, count, new HashMap<Character, Integer>(), n);
    return best;
  }
}


// Method 2: Optimal
// Time: O(t log k) | Space: O(k)
// Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

import java.util.*;
class Solution {
  ArrayList<Integer> h = new ArrayList<Integer>();
  void up(int i) {
    while (i > 0) { int p=(i-1)>>1; if (h.get(i) <= h.get(p)) break;
      int t=h.get(i); h.set(i,h.get(p)); h.set(p,t); i=p; }
  }
  void down(int i) {
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<h.size() && h.get(l)>h.get(s)) s=l;
      if (r<h.size() && h.get(r)>h.get(s)) s=r;
      if (s==i) break; int t=h.get(i); h.set(i,h.get(s)); h.set(s,t); i=s; }
  }
  void push(int x) { h.add(x); up(h.size()-1); }
  int pop() {
    int top = h.get(0); int last = h.remove(h.size()-1);
    if (!h.isEmpty()) { h.set(0, last); down(0); }
    return top;
  }
  public int leastInterval(char[] tasks, int n) {
    int[] freq = new int[26];
    for (char t : tasks) freq[t - 65]++;
    for (int i = 0; i < 26; i++) if (freq[i] > 0) push(freq[i]);
    ArrayDeque<int[]> cool = new ArrayDeque<int[]>();
    int time = 0;
    while (!h.isEmpty() || !cool.isEmpty()) {
      time++;
      if (!h.isEmpty()) {
        int left = pop() - 1;
        if (left > 0) cool.addLast(new int[]{left, time + n});
      }
      if (!cool.isEmpty() && cool.peekFirst()[1] == time) push(cool.pollFirst()[0]);
    }
    return time;
  }
}


// Method 3: More optimal
// Time: O(t) | Space: O(1)
// The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

class Solution {
  public int leastInterval(char[] tasks, int n) {
    int[] freq = new int[26];
    for (char t : tasks) freq[t - 65]++;
    int maxF = 0, maxCount = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] > maxF) { maxF = freq[i]; maxCount = 1; }
      else if (freq[i] == maxF) maxCount++;
    }
    int frame = (maxF - 1) * (n + 1) + maxCount;
    return Math.max(frame, tasks.length);
  }
}
