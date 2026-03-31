/**
 * You are given an m x n grid where each cell can have one of three values:
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 *
 * Example 1:
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 *
 * Example 2:
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
 *
 * Example 3:
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 *
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 */

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> qu;
    int fo = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1)
          fo++;
        else if (grid[i][j] == 2)
          qu.push({i, j}); // multi source bfs steps
      }
    }
    // we have added all the src
    qu.push({-1, -1});
    int mins = 0;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (not qu.empty()) {
      auto cell = qu.front();
      qu.pop();
      if (cell.first == -1 and cell.second == -1) {
        mins++;
        if (not qu.empty()) {
          qu.push({-1, -1});
        }
        else {
          break;
        }
      }
      else {
        int i = cell.first;
        int j = cell.second;
        for (int d = 0; d < 4; d++) {
          int nr = i + dir[d][0];
          int nc = j + dir[d][1];
          if (nc < 0 or nr < 0 or nr >= n or nc >= m)
            continue;
          if (grid[nr][nc] == 2 || grid[nr][nc] == 0)
            continue;
          fo--;
          grid[nr][nc] = 2;
          qu.push({nr, nc});
        }
      }
    }
    return (fo == 0) ? mins - 1 : -1;
  }
};