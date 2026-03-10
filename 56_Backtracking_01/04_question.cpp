/**
 * Consider a 9 * 9 2D array grid number that is partially filled with numbers from 1 to 9. The Sudoku solver problem is to fill remaining blocks with the number 1 to 9 so that every row, column and subgrid (3 * 3) contains exactly one instance of digits (1 to 9).
 */

class Solution
{
public:
  bool canWePlace(vector<vector<char>> &board, int row, int col, char num)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[row][j] == num)
        return false;
    }
    for (int i = 0; i < 9; i++)
    {
      if (board[i][col] == num)
        return false;
    }

    int r = (row / 3) * 3;
    int c = (col / 3) * 3;

    for (int i = r; i < (r + 3); i++)
    {
      for (int j = c; j < (c + 3); j++)
      {
        if (board[i][j] == num)
          return false;
      }
    }

    return true;
  };

  bool sudoku(vector<vector<char>> &board, int row, int col)
  {
    if (col == 9)
      return sudoku(board, row + 1, 0);
    if (row == 9)
      return true;
    if (board[row][col] == '.')
    {
      for (int num = 1; num <= 9; num++)
      {
        if (canWePlace(board, row, col, '0' + num))
        {
          board[row][col] = '0' + num;
          bool res = sudoku(board, row, col + 1);
          if (res)
            return true;
          board[row][col] = '.';
        }
      }
      return false;
    }
    else
    {
      return sudoku(board, row, col + 1);
    }
  };

  void solveSudoku(vector<vector<char>> &board)
  {
    sudoku(board, 0, 0);
  }
};