# Word Break

**Topic:** Strings  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/word-break/)
- [GFG](https://www.geeksforgeeks.org/problems/word-break-2/1)

## Problem

Return true if s can be split into a sequence of dictionary words. Words may be reused. Order in wordDict does not matter.

Example: s = "leetcode", wordDict = ["leet","code"] is true. Example: "catsandog" with ["cats","dog","sand","and","cat"] is false.

Trying every split recursively is exponential. A boolean DP array ok[i] means s[0..i) can be broken. Combining DP with a Set and a max word length avoids scanning impossible slices.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(2ⁿ)
- **Space:** O(n)

Each position may start many words. Overlapping failures are recomputed. Stack depth is O(n).
How it works: dfs(i) is true if i is the end, or some wordDict entry matches s starting at i and dfs continues after it.

### 2. Optimal

- **Time:** O(n² · k)
- **Space:** O(n)

ok[i] loops previous starts and slices. k is cost of string compare / slice.
How it works: ok[0] = true. ok[j] is true if some i < j has ok[i] and s.slice(i,j) is in the dictionary Set.

### 3. More optimal

- **Time:** O(n · L)
- **Space:** O(n)

From each true index i, only try lengths 1..longest word, not every j. L is that max length times slice cost, still typically much less than n for each i.
How it works: same ok array. If ok[i], try each length up to longest. If the slice is a word, mark ok[i+len].

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
