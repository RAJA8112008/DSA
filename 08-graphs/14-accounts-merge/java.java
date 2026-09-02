// Method 1: Brute
// Time: O(n² · m) | Space: O(n · m)
// Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

import java.util.*;
class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    Map<String, List<Integer>> emailToIds=new HashMap<String, List<Integer>>();
    for (int i=0;i<accounts.size();i++) {
      List<String> acc=accounts.get(i);
      for (int j=1;j<acc.size();j++) {
        String e=acc.get(j);
        if (!emailToIds.containsKey(e)) emailToIds.put(e, new ArrayList<Integer>());
        emailToIds.get(e).add(i);
      }
    }
    boolean[] global=new boolean[accounts.size()];
    List<List<String>> ans=new ArrayList<List<String>>();
    for (int i=0;i<accounts.size();i++) {
      if (global[i]) continue;
      boolean[] seen=global.clone();
      ArrayDeque<Integer> stack=new ArrayDeque<Integer>();
      stack.push(i); seen[i]=true;
      Set<String> emails=new HashSet<String>();
      while (!stack.isEmpty()) {
        int id=stack.pop(); global[id]=true;
        List<String> acc=accounts.get(id);
        for (int j=1;j<acc.size();j++) {
          String e=acc.get(j); emails.add(e);
          for (int k : emailToIds.get(e)) {
            if (seen[k]) continue;
            seen[k]=true; stack.push(k);
          }
        }
      }
      List<String> list=new ArrayList<String>(emails);
      Collections.sort(list);
      List<String> row=new ArrayList<String>();
      row.add(accounts.get(i).get(0)); row.addAll(list);
      ans.add(row);
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(n · m log m) | Space: O(n · m)
// Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

import java.util.*;
class Solution {
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    Map<String, Set<String>> g=new HashMap<String, Set<String>>();
    Map<String, String> emailName=new HashMap<String, String>();
    for (List<String> acc : accounts) {
      String name=acc.get(0);
      for (int j=1;j<acc.size();j++) {
        String e=acc.get(j);
        emailName.put(e, name);
        if (!g.containsKey(e)) g.put(e, new HashSet<String>());
        if (j>1) { String first=acc.get(1); g.get(e).add(first); g.get(first).add(e); }
      }
    }
    Set<String> seen=new HashSet<String>();
    List<List<String>> ans=new ArrayList<List<String>>();
    for (String start : emailName.keySet()) {
      if (seen.contains(start)) continue;
      ArrayDeque<String> stack=new ArrayDeque<String>();
      stack.push(start); seen.add(start);
      List<String> bag=new ArrayList<String>();
      while (!stack.isEmpty()) {
        String e=stack.pop(); bag.add(e);
        for (String nei : g.getOrDefault(e, new HashSet<String>())) {
          if (seen.contains(nei)) continue;
          seen.add(nei); stack.push(nei);
        }
      }
      Collections.sort(bag);
      List<String> row=new ArrayList<String>(); row.add(emailName.get(start)); row.addAll(bag);
      ans.add(row);
    }
    return ans;
  }
}


// Method 3: More optimal
// Time: O(n · m log m) | Space: O(n · m)
// Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

import java.util.*;
class Solution {
  Map<String, String> parent=new HashMap<String, String>();
  String find(String x) {
    if (!parent.containsKey(x)) parent.put(x, x);
    while (!parent.get(x).equals(x)) { parent.put(x, parent.get(parent.get(x))); x=parent.get(x); }
    return x;
  }
  void union(String a, String b) {
    String x=find(a), y=find(b);
    if (!x.equals(y)) parent.put(y, x);
  }
  public List<List<String>> accountsMerge(List<List<String>> accounts) {
    Map<String, String> emailName=new HashMap<String, String>();
    for (List<String> acc : accounts) {
      String name=acc.get(0), first=acc.get(1);
      for (int j=1;j<acc.size();j++) { String e=acc.get(j); emailName.put(e, name); union(first, e); }
    }
    Map<String, List<String>> groups=new HashMap<String, List<String>>();
    for (String e : emailName.keySet()) {
      String root=find(e);
      if (!groups.containsKey(root)) groups.put(root, new ArrayList<String>());
      groups.get(root).add(e);
    }
    List<List<String>> ans=new ArrayList<List<String>>();
    for (String root : groups.keySet()) {
      List<String> list=groups.get(root); Collections.sort(list);
      List<String> row=new ArrayList<String>(); row.add(emailName.get(root)); row.addAll(list);
      ans.add(row);
    }
    return ans;
  }
}
