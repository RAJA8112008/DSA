// Method 1: Brute
// Time: set O(1), get O(n) | Space: O(n)
// Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

import java.util.*;
class TimeMap {
  Map<String, List<Integer>> times = new HashMap<String, List<Integer>>();
  Map<String, List<String>> vals = new HashMap<String, List<String>>();
  public void set(String key, String value, int timestamp) {
    times.computeIfAbsent(key, k -> new ArrayList<Integer>()).add(timestamp);
    vals.computeIfAbsent(key, k -> new ArrayList<String>()).add(value);
  }
  public String get(String key, int timestamp) {
    List<Integer> ts = times.get(key);
    if (ts == null) return "";
    String ans = "";
    List<String> vs = vals.get(key);
    for (int i = 0; i < ts.size(); i++) if (ts.get(i) <= timestamp) ans = vs.get(i);
    return ans;
  }
}


// Method 2: Optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

import java.util.*;
class TimeMap {
  Map<String, List<Integer>> times = new HashMap<String, List<Integer>>();
  Map<String, List<String>> vals = new HashMap<String, List<String>>();
  public void set(String key, String value, int timestamp) {
    times.computeIfAbsent(key, k -> new ArrayList<Integer>()).add(timestamp);
    vals.computeIfAbsent(key, k -> new ArrayList<String>()).add(value);
  }
  public String get(String key, int timestamp) {
    List<Integer> ts = times.get(key);
    if (ts == null) return "";
    List<String> vs = vals.get(key);
    int lo = 0, hi = ts.size() - 1;
    String ans = "";
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (ts.get(mid) <= timestamp) { ans = vs.get(mid); lo = mid + 1; }
      else hi = mid - 1;
    }
    return ans;
  }
}


// Method 3: More optimal
// Time: set O(1), get O(log n) | Space: O(n)
// Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

import java.util.*;
class TimeMap {
  Map<String, List<Integer>> times = new HashMap<String, List<Integer>>();
  Map<String, List<String>> vals = new HashMap<String, List<String>>();
  public void set(String key, String value, int timestamp) {
    times.computeIfAbsent(key, k -> new ArrayList<Integer>()).add(timestamp);
    vals.computeIfAbsent(key, k -> new ArrayList<String>()).add(value);
  }
  public String get(String key, int timestamp) {
    List<Integer> ts = times.get(key);
    if (ts == null) return "";
    int lo = 0, hi = ts.size();
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (ts.get(mid) <= timestamp) lo = mid + 1;
      else hi = mid;
    }
    return lo == 0 ? "" : vals.get(key).get(lo - 1);
  }
}
