// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every pair of bars is an area. Quadratic checks.
// How it works: i is the left wall, j the right wall. Area is min height times width. Keep the max.

/* pass n for array length; simple loops */
int maxArea(int* height, int n) {
  int best = 0;
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int h = (height[i] < height[j] ? height[i] : height[j]);
      int area = h * (j - i);
      if (area > best) best = area;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// Each step moves one pointer, so at most n-1 steps.
// How it works: start at both ends. Record the area. Move the shorter wall inward. A taller inner wall might win; a shorter width with the same short wall cannot.

/* pass n for array length; simple loops */
int maxArea(int* height, int n) {
  int left = 0;
  int right = n - 1;
  int best = 0;
  while (left < right) {
    int h = (height[left] < height[right] ? height[left] : height[right]);
    int area = h * (right - left);
    if (area > best) best = area;
    if (height[left] < height[right]) left++;
    else right--;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Still O(n) worst case, but bars no taller than the current min height are skipped, so fewer area multiplies on flat stretches.
// How it works: after recording the area for height h, advance left while height[left] <= h and right while height[right] <= h.

/* pass n for array length; simple loops */
int maxArea(int* height, int n) {
  int left = 0;
  int right = n - 1;
  int best = 0;
  while (left < right) {
    int h = (height[left] < height[right] ? height[left] : height[right]);
    int area = h * (right - left);
    if (area > best) best = area;
    while (left < right && height[left] <= h) left++;
    while (left < right && height[right] <= h) right--;
  }
  return best;
}
