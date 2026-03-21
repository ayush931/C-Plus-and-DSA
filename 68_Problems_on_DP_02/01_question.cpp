/**
 * You are given an m x n integer array grid. There is a robot initially located
 at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
 bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
 down or right at any point in time.
 * An obstacle and space are marked as 1 or 0 respectively in grid. A path that
 the robot takes cannot include any square that is an obstacle.
 * Return the number of possible unique paths that the robot can take to reach
 the bottom-right corner.
 * The testcases are generated so that the answer will be less than or equal to
 2 * 109.

 * Example 1:
 * Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right

 * Example 2:
 * Input: obstacleGrid = [[0,1],[0,0]]
 * Output: 1

 * Constraints:
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] is 0 or 1.
 */

#include <vector>
using namespace std;

class Solution {
public:
  int n, m;
  vector<vector<long long int>> grid, dp;

  int f(int i, int j) {
    if (i == n - 1 and j == m - 1)
      return 1;
    if (i < 0 or j < 0 or i >= n or j >= m)
      return 0;
    if (grid[i][j] == 1)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];
    return dp[i][j] = f(i, j + 1) + f(i + 1, j);
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // grid = obstacleGrid;
    n = obstacleGrid.size();
    m = obstacleGrid[0].size();
    dp.clear();
    // dp.resize(100, vector<int>(100, -1));
    dp.resize(105, vector<long long int>(105, 0));
    if (obstacleGrid[n - 1][m - 1] == 1)
      return 0;

    dp[n - 1][m - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (obstacleGrid[i][m - 1] == 1)
        dp[i][m - 1] = 0;
      else
        dp[i][m - 1] = dp[i + 1][m - 1];
    }

    for (int i = m - 2; i >= 0; i--) {
      if (obstacleGrid[n - 1][i] == 1)
        dp[n - 1][i] = 0;
      else
        dp[n - 1][i] = dp[n - 1][i + 1];
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (obstacleGrid[i][j] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    // return f(0, 0);
    return dp[0][0];
  }
};
