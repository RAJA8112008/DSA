# Method 1: Brute
# Time: O(n² · m) | Space: O(n · m)
# Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

def accountsMerge(accounts):
  emailToIds = {}
  for i, acc in enumerate(accounts):
    for j in range(1, len(acc)):
      e = acc[j]
      emailToIds.setdefault(e, []).append(i)
  globalv = [False]*len(accounts)
  ans = []
  for i in range(len(accounts)):
    if globalv[i]: continue
    seen = globalv[:]
    stack = [i]; seen[i]=True
    emails = set()
    while stack:
      id_ = stack.pop(); globalv[id_]=True
      for j in range(1, len(accounts[id_])):
        e = accounts[id_][j]
        emails.add(e)
        for k in emailToIds[e]:
          if seen[k]: continue
          seen[k]=True; stack.append(k)
    lst = sorted(emails)
    ans.append([accounts[i][0]] + lst)
  return ans


# Method 2: Optimal
# Time: O(n · m log m) | Space: O(n · m)
# Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

def accountsMerge(accounts):
  g = {}; emailName = {}
  for acc in accounts:
    name = acc[0]
    for j in range(1, len(acc)):
      e = acc[j]
      emailName[e]=name
      g.setdefault(e, set())
      if j>1:
        first=acc[1]
        g[e].add(first); g[first].add(e)
  seen={}; ans=[]
  for start in emailName:
    if seen.get(start): continue
    stack=[start]; seen[start]=True; bag=[]
    while stack:
      e=stack.pop(); bag.append(e)
      for nei in (g.get(e) or []):
        if seen.get(nei): continue
        seen[nei]=True; stack.append(nei)
    bag.sort()
    ans.append([emailName[start]]+bag)
  return ans


# Method 3: More optimal
# Time: O(n · m log m) | Space: O(n · m)
# Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

def accountsMerge(accounts):
  parent = {}; emailName = {}
  def find(x):
    if x not in parent: parent[x]=x
    while parent[x] != x:
      parent[x]=parent[parent[x]]
      x=parent[x]
    return x
  def union(a,b):
    x,y=find(a),find(b)
    if x!=y: parent[y]=x
  for acc in accounts:
    name=acc[0]; first=acc[1]
    for j in range(1, len(acc)):
      e=acc[j]; emailName[e]=name; union(first, e)
  groups={}
  for e in emailName:
    root=find(e)
    groups.setdefault(root, []).append(e)
  ans=[]
  for root, lst in groups.items():
    lst.sort()
    ans.append([emailName[root]]+lst)
  return ans
