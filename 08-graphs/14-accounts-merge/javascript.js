// Method 1: Brute
// Time: O(n² · m) | Space: O(n · m)
// Build an email-to-accounts list, then from each unvisited account DFS through shared emails with a copied seen set. Extra copies plus scanning accounts repeatedly.

function accountsMerge(accounts) {
  const emailToIds = {};
  for (let i = 0; i < accounts.length; i++) {
    for (let j = 1; j < accounts[i].length; j++) {
      const e = accounts[i][j];
      if (!emailToIds[e]) emailToIds[e] = [];
      emailToIds[e].push(i);
    }
  }
  const global = Array(accounts.length).fill(false);
  const ans = [];
  for (let i = 0; i < accounts.length; i++) {
    if (global[i]) continue;
    const seen = global.slice();
    const stack = [i];
    seen[i] = true;
    const emails = new Set();
    while (stack.length) {
      const id = stack.pop();
      global[id] = true;
      for (let j = 1; j < accounts[id].length; j++) {
        const e = accounts[id][j];
        emails.add(e);
        const ids = emailToIds[e];
        for (let k = 0; k < ids.length; k++) {
          if (seen[ids[k]]) continue;
          seen[ids[k]] = true;
          stack.push(ids[k]);
        }
      }
    }
    const list = Array.from(emails).sort();
    ans.push([accounts[i][0]].concat(list));
  }
  return ans;
}


// Method 2: Optimal
// Time: O(n · m log m) | Space: O(n · m)
// Graph of emails: link every email in an account to the first email. DFS each component, sort, prepend the name. Sorting emails is the log factor.

function accountsMerge(accounts) {
  const g = {};
  const emailName = {};
  for (let i = 0; i < accounts.length; i++) {
    const name = accounts[i][0];
    for (let j = 1; j < accounts[i].length; j++) {
      const e = accounts[i][j];
      emailName[e] = name;
      if (!g[e]) g[e] = new Set();
      if (j > 1) {
        const first = accounts[i][1];
        g[e].add(first);
        g[first].add(e);
      }
    }
  }
  const seen = {};
  const ans = [];
  const keys = Object.keys(emailName);
  for (let i = 0; i < keys.length; i++) {
    const start = keys[i];
    if (seen[start]) continue;
    const stack = [start];
    seen[start] = true;
    const bag = [];
    while (stack.length) {
      const e = stack.pop();
      bag.push(e);
      const nei = g[e] ? Array.from(g[e]) : [];
      for (let k = 0; k < nei.length; k++) {
        if (seen[nei[k]]) continue;
        seen[nei[k]] = true;
        stack.push(nei[k]);
      }
    }
    bag.sort();
    ans.push([emailName[start]].concat(bag));
  }
  return ans;
}


// Method 3: More optimal
// Time: O(n · m log m) | Space: O(n · m)
// Union-Find on emails. Union every email in an account with the first email. Group by root, sort each group. No adjacency lists; merges are nearly O(1).

function accountsMerge(accounts) {
  const parent = {};
  const emailName = {};
  function find(x) {
    if (parent[x] === undefined) parent[x] = x;
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  function union(a, b) {
    const x = find(a), y = find(b);
    if (x !== y) parent[y] = x;
  }
  for (let i = 0; i < accounts.length; i++) {
    const name = accounts[i][0];
    const first = accounts[i][1];
    for (let j = 1; j < accounts[i].length; j++) {
      const e = accounts[i][j];
      emailName[e] = name;
      union(first, e);
    }
  }
  const groups = {};
  const emails = Object.keys(emailName);
  for (let i = 0; i < emails.length; i++) {
    const e = emails[i];
    const root = find(e);
    if (!groups[root]) groups[root] = [];
    groups[root].push(e);
  }
  const ans = [];
  const roots = Object.keys(groups);
  for (let i = 0; i < roots.length; i++) {
    const list = groups[roots[i]].sort();
    ans.push([emailName[roots[i]]].concat(list));
  }
  return ans;
}
