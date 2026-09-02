// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Sort by position. For each car, scan every car closer to the target. If this car's time is <= that car's time, it joins that fleet. Extra scans that a stack would skip.

#include <stdlib.h>
typedef struct { double p, t; } Car;
int cmp_p_desc(const void* a, const void* b) {
  double d = ((const Car*)b)->p - ((const Car*)a)->p;
  return d > 0 ? 1 : d < 0 ? -1 : 0;
}
int carFleet(int target, int* position, int n, int* speed) {
  Car* cars = (Car*)malloc(sizeof(Car)*n);
  for (int i = 0; i < n; i++) { cars[i].p = position[i]; cars[i].t = (target - position[i]) * 1.0 / speed[i]; }
  qsort(cars, n, sizeof(Car), cmp_p_desc);
  int* used = (int*)calloc(n, sizeof(int));
  int fleets = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    fleets++;
    for (int j = i + 1; j < n; j++) if (cars[j].t <= cars[i].t) used[j] = 1;
  }
  free(cars); free(used);
  return fleets;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort cars from closest to target backward. Push time onto a stack if it is strictly slower than the fleet ahead (it cannot catch). Stack length is the fleet count. Sort dominates.

#include <stdlib.h>
typedef struct { int p, s; } Car;
int cmp_p_asc(const void* a, const void* b) { return ((const Car*)a)->p - ((const Car*)b)->p; }
int carFleet(int target, int* position, int n, int* speed) {
  Car* cars = (Car*)malloc(sizeof(Car)*n);
  for (int i = 0; i < n; i++) { cars[i].p = position[i]; cars[i].s = speed[i]; }
  qsort(cars, n, sizeof(Car), cmp_p_asc);
  double* st = (double*)malloc(sizeof(double)*n);
  int sn = 0;
  for (int i = n - 1; i >= 0; i--) {
    double time = (target - cars[i].p) * 1.0 / cars[i].s;
    if (!sn || time > st[sn-1]) st[sn++] = time;
  }
  free(cars); free(st);
  return sn;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// Same sort, no stack. Walk from the target backward and count a new fleet whenever time > currentMaxTime. Extra space is the cars array only. Sort is still the bottleneck.

#include <stdlib.h>
typedef struct { double p, t; } Car;
int cmp_p_asc2(const void* a, const void* b) {
  double d = ((const Car*)a)->p - ((const Car*)b)->p;
  return d > 0 ? 1 : d < 0 ? -1 : 0;
}
int carFleet(int target, int* position, int n, int* speed) {
  Car* cars = (Car*)malloc(sizeof(Car)*n);
  for (int i = 0; i < n; i++) { cars[i].p = position[i]; cars[i].t = (target - position[i]) * 1.0 / speed[i]; }
  qsort(cars, n, sizeof(Car), cmp_p_asc2);
  int fleets = 0;
  double cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (cars[i].t > cur) { fleets++; cur = cars[i].t; }
  }
  free(cars);
  return fleets;
}
