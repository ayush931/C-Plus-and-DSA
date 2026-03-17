/**
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 *
 *Example 1:
 *
 *Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 */

class Solution {
  public:
  vector<int> dp;
  int f(int i, vector<int> &arr) {
    if (i >= arr.size())
      return 0;
    if (dp[i] != -1)
      return dp[i];
    return dp[i] = max(arr[i] + f(i + 2, arr), f(i + 1, arr));
  };
  int rob(vector<int> &nums) {
    dp.resize(nums.size() + 10, -1);
    return f(0, nums);
  }
};

// or bottom up

class Solution {
  public:
  vector<int> dp;
  int f (int i, vector<int> &arr) {
    int n = arr.size();
    if (n == 1) return arr[n - 1];
    dp[n - 1] = arr[n - 1];
    dp[n - 2] = max(arr[n - 1], arr[n - 2]);
    for (int i = n - 3; i >= 0; i--) {
      dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
  }

  int rob(vector<int> &nums) {
    dp.resize(nums.size() + 10, -1);
    return f(0, nums);
  }
}