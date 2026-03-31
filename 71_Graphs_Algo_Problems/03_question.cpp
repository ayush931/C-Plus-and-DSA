/**
 * There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

 * The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
 *
 * The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
 *
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
 *
 * Example 1:
 *
 * Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean
 *        [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean
 *        [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
 *        [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
 *        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean
 *        [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean
 *        [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean
 *        [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
 *
 * Example 2:
 * Input: heights = [[1]]
 * Output: [[0,0]]
 * Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 *
 * Constraints:
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 105
 */

class Solution {
public:
  vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // i, j -> i + 1, j -> i - 1, j -> i, j - 1 -> i, j + 1
  int rows;
  int cols;
  vector<vector<int>> h;

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    rows = heights.size();
    cols = heights[0].size();
    h = heights;
    queue<pair<int, int>> pacificbfs;
    queue<pair<int, int>> atlanticbfs;

    // steps for multisource bfs
    for (int i = 0; i < rows; i++) {
      pacificbfs.push({i, 0});
      atlanticbfs.push({i, cols - 1});
    }

    for (int j = 1; j < cols; j++) {
      pacificbfs.push({0, j});
    }

    for (int j = 0; j < cols - 1; j++) {
      atlanticbfs.push({rows - 1, j});
    }

    vector<vector<bool>> pacific = bfs(pacificbfs);
    vector<vector<bool>> atlantic = bfs(atlanticbfs);
    vector<vector<int>> result;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (pacific[i][j] and atlantic[i][j])
          result.push_back({i, j});
      }
    }
    return result;
  }

  vector<vector<bool>> bfs(queue<pair<int, int>> &qu) {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    while (not qu.empty()) {
      auto cell = qu.front();
      qu.pop();
      int i = cell.first;
      int j = cell.second;
      visited[i][j] = true;
      for (int d = 0; d < 4; d++) {
        int newRow = i + dir[d][0];
        int newCol = j + dir[d][1];
        if (newRow < 0 or newCol < 0 or newRow >= rows or newCol >= cols)
          continue; // you exited the grid
        if (visited[newRow][newCol])
          continue;
        if (h[newRow][newCol] < h[i][j])
          continue; // h[newRol][newCol] -> neighbours, height, h[i][j] -> curr cell high
        qu.push({newRow, newCol});
      }
    }
    return visited;
  }
};