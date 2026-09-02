// Method 1: Brute
// Time: O(n^4) | Space: O(n)
// Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

function restoreIpAddresses(s) {
  const ans = [];
  function ok(part) {
    if (!part.length || part.length > 3) return false;
    if (part.length > 1 && part[0] === "0") return false;
    const v = Number(part);
    return v >= 0 && v <= 255;
  }
  const n = s.length;
  for (let i = 1; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      for (let k = j + 1; k < n; k++) {
        const a = s.slice(0, i), b = s.slice(i, j), c = s.slice(j, k), d = s.slice(k);
        if (ok(a) && ok(b) && ok(c) && ok(d)) ans.push([a, b, c, d].join("."));
      }
    }
  }
  return ans;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

function restoreIpAddresses(s) {
  const ans = [];
  function ok(part) {
    if (!part.length || part.length > 3) return false;
    if (part.length > 1 && part[0] === "0") return false;
    return Number(part) <= 255;
  }
  function go(i, parts) {
    if (parts.length === 4) {
      if (i === s.length) ans.push(parts.join("."));
      return;
    }
    for (let len = 1; len <= 3 && i + len <= s.length; len++) {
      const piece = s.slice(i, i + len);
      if (!ok(piece)) continue;
      parts.push(piece);
      go(i + len, parts);
      parts.pop();
    }
  }
  go(0, []);
  return ans;
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

function restoreIpAddresses(s) {
  const ans = [];
  function go(i, parts) {
    const leftParts = 4 - parts.length;
    const leftChars = s.length - i;
    if (leftChars < leftParts || leftChars > 3 * leftParts) return;
    if (parts.length === 4) { ans.push(parts.join(".")); return; }
    for (let len = 1; len <= 3 && i + len <= s.length; len++) {
      if (len > 1 && s[i] === "0") break;
      const piece = s.slice(i, i + len);
      if (Number(piece) > 255) continue;
      parts.push(piece);
      go(i + len, parts);
      parts.pop();
    }
  }
  go(0, []);
  return ans;
}
