/**
 * Given an integer n, return the number of structurally unique BST's (binary
 search trees) which has exactly n nodes of unique values from 1 to n.

 * Example 1:
 * Input: n = 3
 * Output: 5

 * Example 2:
 * Input: n = 1
 * Output: 1

 * Constraints:
 * 1 <= n <= 19
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dp;
  int f(int n) {
    if (n == 0 or n == 1)
      return 1;
    if (n == 2)
      return 2;
    if (dp[n] != -1)
      return dp[n];
    int sum = 0;

    for (int k = 1; k <= n; k++) {
      // k -> potential root
      sum += f(k - 1) * f(n - k);
    }
    return dp[n] = sum;
  };

  int numTrees(int n) {
    dp.clear();
    // dp.resize(30, -1);
    dp.resize(30, 0);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      // f(i)
      for (int k = 1; k <= i; k++) {
        // k -> potential root
        dp[i] += dp[k - 1] * dp[i - k];
      }
    }
    // return f(n);
    return dp[n];
  };
};
