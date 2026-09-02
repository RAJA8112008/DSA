// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

int targetGo(vector<int>& nums, int target, int i, int sum) {
    if (i == (int)nums.size()) return sum == target ? 1 : 0;
    return targetGo(nums, target, i + 1, sum + nums[i]) + targetGo(nums, target, i + 1, sum - nums[i]);
}
int findTargetSumWays(vector<int>& nums, int target) {
    return targetGo(nums, target, 0, 0);
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

int targetGo(vector<int>& nums, int target, int i, int sum, unordered_map<string, int>& memo) {
    string key = to_string(i) + ":" + to_string(sum);
    if (memo.count(key)) return memo[key];
    if (i == (int)nums.size()) {
        int ans = sum == target ? 1 : 0;
        memo[key] = ans;
        return ans;
    }
    int ways = targetGo(nums, target, i + 1, sum + nums[i], memo) +
               targetGo(nums, target, i + 1, sum - nums[i], memo);
    memo[key] = ways;
    return ways;
}
int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<string, int> memo;
    return targetGo(nums, target, 0, 0, memo);
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

int findTargetSumWays(vector<int>& nums, int target) {
    int total = 0;
    for (int x : nums) total += x;
    if (abs(target) > total || (total + target) % 2 != 0) return 0;
    int need = (total + target) / 2;
    vector<int> ways(need + 1, 0);
    ways[0] = 1;
    for (int i = 0; i < (int)nums.size(); i++) {
        int num = nums[i];
        for (int s = need; s >= num; s--) ways[s] += ways[s - num];
    }
    return ways[need];
}
