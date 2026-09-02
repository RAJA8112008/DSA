# Method 1: Brute
# Time: O(26^L · n) | Space: O(n·L)
# DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

def ladderLength(beginWord, endWord, wordList):
  words = set(wordList)
  if endWord not in words: return 0
  best = float("inf")
  def dfs(word, dist, left):
    nonlocal best
    if dist >= best: return
    if word == endWord:
      best = dist
      return
    for i in range(len(word)):
      for c in range(97, 123):
        nxt = word[:i] + chr(c) + word[i+1:]
        if nxt not in left: continue
        copy = set(left)
        copy.discard(nxt)
        dfs(nxt, dist+1, copy)
  dfs(beginWord, 1, words)
  return 0 if best == float("inf") else best


# Method 2: Optimal
# Time: O(n·L·26) | Space: O(n·L)
# BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

from collections import deque
def ladderLength(beginWord, endWord, wordList):
  words = set(wordList)
  if endWord not in words: return 0
  q = deque([(beginWord, 1)])
  words.discard(beginWord)
  while q:
    word, dist = q.popleft()
    if word == endWord: return dist
    for i in range(len(word)):
      for c in range(97, 123):
        nxt = word[:i] + chr(c) + word[i+1:]
        if nxt not in words: continue
        words.discard(nxt)
        q.append((nxt, dist+1))
  return 0


# Method 3: More optimal
# Time: O(n·L·26) | Space: O(n·L)
# Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

def ladderLength(beginWord, endWord, wordList):
  words = set(wordList)
  if endWord not in words: return 0
  begin = {beginWord}
  end = {endWord}
  seen = {beginWord, endWord}
  steps = 1
  while begin and end:
    if len(begin) > len(end):
      begin, end = end, begin
    nxt = set()
    for word in list(begin):
      for i in range(len(word)):
        for c in range(97, 123):
          cand = word[:i] + chr(c) + word[i+1:]
          if cand in end: return steps + 1
          if cand not in words or cand in seen: continue
          seen.add(cand)
          nxt.add(cand)
    begin = nxt
    steps += 1
  return 0
