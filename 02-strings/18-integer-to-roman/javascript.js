// Method 1: Brute
// Time: O(1) | Space: O(1)
// The input is at most 3999, so the number of appended symbols is bounded. Separate while loops per unit are verbose.
// How it works: peel thousands as M, then hundreds with C/D/CM/CD, then tens, then ones, with explicit ifs for 9 and 4.

function intToRoman(num) {
  let n = num;
  let out = "";
  while (n >= 1000) { out += "M"; n -= 1000; }
  if (n >= 900) { out += "CM"; n -= 900; }
  if (n >= 500) { out += "D"; n -= 500; }
  if (n >= 400) { out += "CD"; n -= 400; }
  while (n >= 100) { out += "C"; n -= 100; }
  if (n >= 90) { out += "XC"; n -= 90; }
  if (n >= 50) { out += "L"; n -= 50; }
  if (n >= 40) { out += "XL"; n -= 40; }
  while (n >= 10) { out += "X"; n -= 10; }
  if (n >= 9) { out += "IX"; n -= 9; }
  if (n >= 5) { out += "V"; n -= 5; }
  if (n >= 4) { out += "IV"; n -= 4; }
  while (n >= 1) { out += "I"; n -= 1; }
  return out;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// Same greedy idea, data-driven: walk a values array and append the matching glyph count times.
// How it works: values and glyphs are aligned. For each pair, while num >= values[i], append glyphs[i] and subtract.

function intToRoman(num) {
  const values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
  const glyphs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
  let out = "";
  for (let i = 0; i < values.length; i++) {
    while (num >= values[i]) {
      out += glyphs[i];
      num -= values[i];
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Use division to append a glyph in a batch instead of a per-unit inner while for large counts (e.g. 3 -> "III" in one repeat).
// How it works: count = Math.floor(num / values[i]); append glyphs[i] that many times; num %= values[i].

function intToRoman(num) {
  const values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
  const glyphs = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
  let out = "";
  for (let i = 0; i < values.length; i++) {
    const count = Math.floor(num / values[i]);
    for (let c = 0; c < count; c++) out += glyphs[i];
    num %= values[i];
  }
  return out;
}
