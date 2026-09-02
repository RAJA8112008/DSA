// Method 1: Brute
// Time: O(n³) | Space: O(k)
// Every triple of indexes is summed. Uniqueness is handled by a sorted-key set. k is the number of triplets stored.
// How it works: i < j < l. If the three numbers sum to 0, sort them and keep the key in a Set so duplicates are dropped.

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    int n = nums.length;
    Set<Integer> seen = new HashSet<>();
    List<Integer> out = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int l = j + 1; l < n; l++) {
          if (nums[i] + nums[j] + nums[l] == 0) {
            int[] trip = trip.clone();
            Arrays.sort(trip);
            int key = trip[0] + "," + trip[1] + "," + trip[2];
            if (!seen.contains(key)) {
              seen.add(key);
              out.add(trip);
            }
          }
        }
      }
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort once. For each pair, binary-search the third value. Each search is log n, and there are n² pairs.
// How it works: after sort, for i and j look for -(nums[i]+nums[j]) in the suffix. Skip used indexes. A set of keys still blocks duplicate triplets.

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    int n = nums.length;
    int[] list = nums.clone();
    Arrays.sort(list);
    Set<Integer> seen = new HashSet<>();
    List<Integer> out = new ArrayList<>();

    public void find(from, target) {
      int lo = from;
      int hi = n - 1;
      while (lo <= hi) {
        int mid = ((lo + hi) / 2);
        if (list[mid] == target) return mid;
        if (list[mid] < target) lo = mid + 1;
        else hi = mid - 1;
      }
      return -1;
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int need = -(list[i] + list[j]);
        int k = find(j + 1, need);
        if (k != -1) {
          int trip = [list[i], list[j], list[k]];
          int key = trip[0] + "," + trip[1] + "," + trip[2];
          if (!seen.contains(key)) {
            seen.add(key);
            out.add(trip);
          }
        }
      }
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(k)
// Sort plus two pointers is the standard bound. Extra memory is only the output (and the sort copy).
// How it works: skip duplicate first numbers. For each i, left = i+1, right = end. Move left/right by comparing the sum to 0, and skip duplicate left/right values after a hit.

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    int[] list = nums.clone();
    Arrays.sort(list);
    int n = list.length;
    List<Integer> out = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (i > 0 && list[i] == list[i - 1]) continue;
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        int sum = list[i] + list[left] + list[right];
        if (sum == 0) {
          out.add([list[i], list[left], list[right]]);
          left++;
          right--;
          while (left < right && list[left] == list[left - 1]) left++;
          while (left < right && list[right] == list[right + 1]) right--;
        } else if (sum < 0) {
          left++;
        } else {
          right--;
        }
      }
    }
    return out;
  }
}
