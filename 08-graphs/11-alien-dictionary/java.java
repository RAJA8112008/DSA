// Method 1: Brute
// Time: O(k! · n · L) | Space: O(k)
// Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

import java.util.*;
class Solution {
  String ans;
  boolean valid(String order, String[] words) {
    int[] rank=new int[128];
    for (int i=0;i<order.length();i++) rank[order.charAt(i)]=i;
    for (int i=0;i<words.length-1;i++) {
      String a=words[i], b=words[i+1];
      int n=Math.min(a.length(), b.length());
      boolean diff=false;
      for (int j=0;j<n;j++) if (a.charAt(j)!=b.charAt(j)) {
        if (rank[a.charAt(j)]>rank[b.charAt(j)]) return false;
        diff=true; break;
      }
      if (!diff && a.length()>b.length()) return false;
    }
    return true;
  }
  void dfs(char[] letters, boolean[] used, StringBuilder path, String[] words) {
    if (ans.length()>0) return;
    if (path.length()==letters.length) {
      String s=path.toString();
      if (valid(s, words)) ans=s;
      return;
    }
    for (int i=0;i<letters.length;i++) {
      if (used[i]) continue;
      used[i]=true; path.append(letters[i]); dfs(letters, used, path, words);
      path.deleteCharAt(path.length()-1); used[i]=false;
    }
  }
  public String alienOrder(String[] words) {
    LinkedHashSet<Character> set=new LinkedHashSet<Character>();
    for (String w : words) for (char ch : w.toCharArray()) set.add(ch);
    char[] letters=new char[set.size()]; int k=0;
    for (char ch : set) letters[k++]=ch;
    ans="";
    dfs(letters, new boolean[letters.length], new StringBuilder(), words);
    return ans;
  }
}


// Method 2: Optimal
// Time: O(n·L + k) | Space: O(k²)
// Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

import java.util.*;
class Solution {
  boolean cycle;
  void dfs(char u, Map<Character, Set<Character>> g, int[] state, List<Character> out) {
    if (state[u]==1) { cycle=true; return; }
    if (state[u]==2) return;
    state[u]=1;
    for (char v : g.get(u)) dfs(v, g, state, out);
    state[u]=2; out.add(u);
  }
  public String alienOrder(String[] words) {
    Map<Character, Set<Character>> g=new HashMap<Character, Set<Character>>();
    int[] state=new int[128];
    for (String w : words) for (char ch : w.toCharArray()) if (!g.containsKey(ch)) g.put(ch, new HashSet<Character>());
    for (int i=0;i<words.length-1;i++) {
      String a=words[i], b=words[i+1];
      int n=Math.min(a.length(), b.length()); boolean found=false;
      for (int j=0;j<n;j++) if (a.charAt(j)!=b.charAt(j)) { g.get(a.charAt(j)).add(b.charAt(j)); found=true; break; }
      if (!found && a.length()>b.length()) return "";
    }
    List<Character> out=new ArrayList<Character>(); cycle=false;
    for (char k : g.keySet()) dfs(k, g, state, out);
    if (cycle) return "";
    Collections.reverse(out);
    StringBuilder sb=new StringBuilder();
    for (char c : out) sb.append(c);
    return sb.toString();
  }
}


// Method 3: More optimal
// Time: O(n·L + k) | Space: O(k²)
// Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

import java.util.*;
class Solution {
  public String alienOrder(String[] words) {
    Map<Character, Set<Character>> g=new HashMap<Character, Set<Character>>();
    Map<Character, Integer> indeg=new HashMap<Character, Integer>();
    for (String w : words) for (char ch : w.toCharArray()) {
      if (!g.containsKey(ch)) { g.put(ch, new HashSet<Character>()); indeg.put(ch, 0); }
    }
    for (int i=0;i<words.length-1;i++) {
      String a=words[i], b=words[i+1];
      int n=Math.min(a.length(), b.length()); boolean found=false;
      for (int j=0;j<n;j++) if (a.charAt(j)!=b.charAt(j)) {
        if (!g.get(a.charAt(j)).contains(b.charAt(j))) {
          g.get(a.charAt(j)).add(b.charAt(j)); indeg.put(b.charAt(j), indeg.get(b.charAt(j))+1);
        }
        found=true; break;
      }
      if (!found && a.length()>b.length()) return "";
    }
    ArrayDeque<Character> q=new ArrayDeque<Character>();
    for (char k : indeg.keySet()) if (indeg.get(k)==0) q.addLast(k);
    StringBuilder order=new StringBuilder();
    while (!q.isEmpty()) {
      char u=q.pollFirst(); order.append(u);
      for (char v : g.get(u)) {
        indeg.put(v, indeg.get(v)-1);
        if (indeg.get(v)==0) q.addLast(v);
      }
    }
    return order.length()==indeg.size() ? order.toString() : "";
  }
}
