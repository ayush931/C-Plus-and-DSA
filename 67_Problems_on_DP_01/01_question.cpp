/**
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * 
 * Example 1:
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * 
 * Example 2:
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * Constraints:
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -104 <= triangle[i][j] <= 104
 */

class Solution {
public:
  vector<vector<int>> grid;
  vector<vector<int>> dp;

  // int f (int r, int c) {
  //     if (r == grid.size() - 1) {
  //         return grid[r][c];
  //     }

  //     if (dp[r][c] != -1) return dp[r][c];
  //     return dp[r][c] = grid[r][c] + min(f(r + 1, c), f(r + 1, c + 1));
  // };

  int minimumTotal(vector<vector<int>> &triangle) {
    dp.clear();
    dp.resize(205, vector<int>(205, -1));
    grid = triangle;
    int rows = grid.size();
    // base case
    for (int i = 0; i < grid[rows - 1].size(); i++) {
      dp[rows - 1][i] = grid[rows - 1][i];
    }

    for (int r = rows - 2; r >= 0; r--) {
      for (int c = 0; c < grid[r].size(); c++) {
        dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r + 1][c + 1]);
      }
    }
    return dp[0][0];
  }
};