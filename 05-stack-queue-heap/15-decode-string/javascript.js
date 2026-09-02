// Method 1: Brute
// Time: O(n · out) | Space: O(n · out)
// Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

function decodeString(s) {
  function parse(i) {
    let out = "";
    while (i < s.length && s[i] !== "]") {
      if (s[i] < "0" || s[i] > "9") {
        out += s[i];
        i++;
        continue;
      }
      let k = 0;
      while (s[i] >= "0" && s[i] <= "9") {
        k = k * 10 + Number(s[i]);
        i++;
      }
      i++; // skip '['
      const inner = parse(i);
      out += inner.text.repeat(k);
      i = inner.i + 1; // skip ']'
    }
    return { text: out, i: i };
  }
  return parse(0).text;
}


// Method 2: Optimal
// Time: O(n + out) | Space: O(n + out)
// One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

function decodeString(s) {
  const st = [];
  let cur = "";
  let k = 0;
  for (let i = 0; i < s.length; i++) {
    const ch = s[i];
    if (ch >= "0" && ch <= "9") k = k * 10 + Number(ch);
    else if (ch === "[") {
      st.push([cur, k]);
      cur = "";
      k = 0;
    } else if (ch === "]") {
      const frame = st.pop();
      cur = frame[0] + cur.repeat(frame[1]);
    } else cur += ch;
  }
  return cur;
}


// Method 3: More optimal
// Time: O(n + out) | Space: O(n + out)
// Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

function decodeString(s) {
  const counts = [];
  const strs = [];
  let cur = "";
  let k = 0;
  for (let i = 0; i < s.length; i++) {
    const ch = s[i];
    if (ch >= "0" && ch <= "9") k = k * 10 + Number(ch);
    else if (ch === "[") {
      counts.push(k);
      strs.push(cur);
      cur = "";
      k = 0;
    } else if (ch === "]") {
      cur = strs.pop() + cur.repeat(counts.pop());
    } else cur += ch;
  }
  return cur;
}
