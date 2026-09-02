// Method 1: Brute
// Time: O(26^L · n) | Space: O(n·L)
// DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

class Solution {
  int best;
  void dfs(string word, int dist, unordered_set<string> left, string endWord) {
    if (dist >= best) return;
    if (word == endWord) { best = dist; return; }
    for (int i = 0; i < (int)word.size(); i++) {
      char old = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        word[i] = c;
        if (!left.count(word)) continue;
        auto copy = left; copy.erase(word);
        dfs(word, dist+1, copy, endWord);
      }
      word[i] = old;
    }
  }
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;
    best = INT_MAX;
    dfs(beginWord, 1, words, endWord);
    return best == INT_MAX ? 0 : best;
  }
};


// Method 2: Optimal
// Time: O(n·L·26) | Space: O(n·L)
// BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;
    queue<pair<string,int>> q;
    q.push({beginWord, 1});
    words.erase(beginWord);
    while (!q.empty()) {
      auto cur = q.front(); q.pop();
      string word = cur.first; int dist = cur.second;
      if (word == endWord) return dist;
      for (int i = 0; i < (int)word.size(); i++) {
        char old = word[i];
        for (char c = 'a'; c <= 'z'; c++) {
          word[i] = c;
          if (!words.count(word)) continue;
          words.erase(word);
          q.push({word, dist+1});
        }
        word[i] = old;
      }
    }
    return 0;
  }
};


// Method 3: More optimal
// Time: O(n·L·26) | Space: O(n·L)
// Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;
    unordered_set<string> begin{beginWord}, end{endWord}, seen{beginWord, endWord};
    int steps = 1;
    while (!begin.empty() && !end.empty()) {
      if (begin.size() > end.size()) swap(begin, end);
      unordered_set<string> next;
      for (string word : begin) {
        for (int i = 0; i < (int)word.size(); i++) {
          char old = word[i];
          for (char c = 'a'; c <= 'z'; c++) {
            word[i] = c;
            if (end.count(word)) return steps + 1;
            if (!words.count(word) || seen.count(word)) continue;
            seen.insert(word); next.insert(word);
          }
          word[i] = old;
        }
      }
      begin.swap(next); steps++;
    }
    return 0;
  }
};
