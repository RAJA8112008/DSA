// Method 1: Brute
// Time: O(26^L · n) | Space: O(n·L)
// DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

function ladderLength(beginWord, endWord, wordList) {
  const words = new Set(wordList);
  if (!words.has(endWord)) return 0;
  let best = Infinity;

  function dfs(word, dist, left) {
    if (dist >= best) return;
    if (word === endWord) {
      best = dist;
      return;
    }
    for (let i = 0; i < word.length; i++) {
      for (let c = 97; c <= 122; c++) {
        const ch = String.fromCharCode(c);
        const next = word.slice(0, i) + ch + word.slice(i + 1);
        if (!left.has(next)) continue;
        const copy = new Set(left);
        copy.delete(next);
        dfs(next, dist + 1, copy);
      }
    }
  }

  dfs(beginWord, 1, words);
  return best === Infinity ? 0 : best;
}


// Method 2: Optimal
// Time: O(n·L·26) | Space: O(n·L)
// BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

function ladderLength(beginWord, endWord, wordList) {
  const words = new Set(wordList);
  if (!words.has(endWord)) return 0;
  const q = [[beginWord, 1]];
  words.delete(beginWord);
  while (q.length) {
    const cur = q.shift();
    const word = cur[0], dist = cur[1];
    if (word === endWord) return dist;
    for (let i = 0; i < word.length; i++) {
      for (let c = 97; c <= 122; c++) {
        const next = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
        if (!words.has(next)) continue;
        words.delete(next);
        q.push([next, dist + 1]);
      }
    }
  }
  return 0;
}


// Method 3: More optimal
// Time: O(n·L·26) | Space: O(n·L)
// Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

function ladderLength(beginWord, endWord, wordList) {
  const words = new Set(wordList);
  if (!words.has(endWord)) return 0;
  let begin = new Set([beginWord]);
  let end = new Set([endWord]);
  const seen = new Set([beginWord, endWord]);
  let steps = 1;
  while (begin.size && end.size) {
    if (begin.size > end.size) {
      const tmp = begin; begin = end; end = tmp;
    }
    const next = new Set();
    const beginArr = Array.from(begin);
    for (let b = 0; b < beginArr.length; b++) {
      const word = beginArr[b];
      for (let i = 0; i < word.length; i++) {
        for (let c = 97; c <= 122; c++) {
          const cand = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
          if (end.has(cand)) return steps + 1;
          if (!words.has(cand) || seen.has(cand)) continue;
          seen.add(cand);
          next.add(cand);
        }
      }
    }
    begin = next;
    steps++;
  }
  return 0;
}
