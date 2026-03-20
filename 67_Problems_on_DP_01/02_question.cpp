/**
 * Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
 * A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
 *
 * For example, "ace" is a subsequence of "abcde".
 * A common subsequence of two strings is a subsequence that is common to both strings.
 *
 * Example 1:
 * Input: text1 = "abcde", text2 = "ace"
 * Output: 3
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 * Example 2:
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 * Example 3:
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 *
 * Constraints:
 * 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English characters.
 */

class Solution {
public:
  vector<vector<int>> dp;
  int f(string &a, string &b, int i, int j) {
    if (i == a.size() or j == b.size())
      return 0;
    if (dp[i][j] != INT_MAX)
      return dp[i][j];
    if (a[i] != b[j]) {
      return dp[i][j] = max(f(a, b, i + 1, j), f(a, b, i, j + 1));
    }
    else {
      return dp[i][j] = 1 + f(a, b, i + 1, j + 1);
    }
  };

  int longestCommonSubsequence(string text1, string text2) {
    dp.clear();
    dp.resize(1005, vector<int>(1005, INT_MAX));
    dp.resize(1005, vector<int>(1005, 0));

    int n = text1.size();
    int m = text2.size();

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (text1[i] != text2[j]) {
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
        else {
          dp[i][j] = 1 + dp[i + 1][j + 1];
        }
      }
    }
    // return f(text1, text2, 0, 0);
    return dp[0][0];
  }
};