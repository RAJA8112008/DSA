// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

function partition(s) {
  const ans = [];
  function isPal(parts) {
    for (let p = 0; p < parts.length; p++) {
      const w = parts[p];
      let l = 0, r = w.length - 1;
      while (l < r) { if (w[l] !== w[r]) return false; l++; r--; }
    }
    return true;
  }
  function go(i, parts, cur) {
    if (i === s.length) {
      const all = cur.length ? parts.concat([cur]) : parts.slice();
      if (isPal(all)) ans.push(all);
      return;
    }
    go(i + 1, parts.slice(), cur + s[i]);
    if (cur.length) go(i, parts.concat([cur]), "");
  }
  go(0, [], "");
  return ans;
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

function partition(s) {
  const ans = [];
  function isPal(l, r) {
    while (l < r) { if (s[l] !== s[r]) return false; l++; r--; }
    return true;
  }
  function go(start, path) {
    if (start === s.length) { ans.push(path.slice()); return; }
    for (let end = start; end < s.length; end++) {
      if (!isPal(start, end)) continue;
      path.push(s.slice(start, end + 1));
      go(end + 1, path);
      path.pop();
    }
  }
  go(0, []);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n^2)
// pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

function partition(s) {
  const n = s.length;
  const pal = Array.from({ length: n }, function () { return Array(n).fill(false); });
  for (let i = 0; i < n; i++) pal[i][i] = true;
  for (let i = 0; i < n - 1; i++) pal[i][i + 1] = s[i] === s[i + 1];
  for (let len = 3; len <= n; len++) {
    for (let l = 0; l + len - 1 < n; l++) {
      const r = l + len - 1;
      pal[l][r] = s[l] === s[r] && pal[l + 1][r - 1];
    }
  }
  const ans = [];
  function go(start, path) {
    if (start === n) { ans.push(path.slice()); return; }
    for (let end = start; end < n; end++) {
      if (!pal[start][end]) continue;
      path.push(s.slice(start, end + 1));
      go(end + 1, path);
      path.pop();
    }
  }
  go(0, []);
  return ans;
}
