/**
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 *
 * Example 1:
 * Input: nums = [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 *
 * Example 2:
 * Input: nums = [0,1,0,3,2,3]
 * Output: 4
 *
 * Example 3:
 * Input: nums = [7,7,7,7,7,7,7]
 * Output: 1
 *
 * Constraints:
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 */

class Solution
{
public:
  vector<int> arr;
  vector<int> dp;

  int f(int i) {
    if (i == 0)
      return 1;
    int mx = INT_MIN;
    if (dp[i] != -1)
      return dp[i];
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] < arr[i]) {
        mx = max(mx, f(j));
      }
    }

    if (mx == INT_MIN)
      return dp[i] = 1;
    return dp[i] = 1 + mx;
  };

  int lengthOfLIS(vector<int> &nums) {
    arr = nums;
    dp.resize(2505, -1);
    dp[0] = 1;
    int ans = INT_MIN;
    // for (int i = 0; i < nums.size(); i++) {
    //     ans = max(ans, f(i));
    // }

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j <= i - 1; j++) {
        if (arr[j] < arr[i]) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }

      if (dp[i] == -1)
        dp[i] = 1;
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};