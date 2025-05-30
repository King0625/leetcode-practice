#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool countValidGrid(vector<vector<char>> &board, int x, int y)
{
  map<char, bool> grid_map = {};
  for (int m = 3 * x + 0; m < 3 * x + 3; m++)
  {
    for (int n = 3 * y + 0; n < 3 * y + 3; n++)
    {
      char g_element = board[m][n];
      if (g_element != '.' && grid_map.count(g_element))
      {
        return false;
      }
      grid_map[g_element] = true;
    }
  }

  grid_map.clear();
  return true;
}

bool isValidSudoku(vector<vector<char>> &board)
{
  // row
  for (int i = 0; i < 9; i++)
  {
    map<char, bool> row_map = {};
    for (int i_r = 0; i_r < 9; i_r++)
    {
      char r_element = board[i][i_r];
      if (r_element != '.' && row_map.count(r_element))
        return false;
      row_map[r_element] = true;
    }
    row_map.clear();
  }

  // column
  for (int j = 0; j < 9; j++)
  {
    map<char, bool> column_map = {};
    for (int j_c = 0; j_c < 9; j_c++)
    {
      char c_element = board[j_c][j];
      if (c_element != '.' && column_map.count(c_element))
        return false;
      column_map[c_element] = true;
    }

    column_map.clear();
  }

  // grid (divided into 3*3 3x3 grid)
  for (int x = 0; x < 3; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      if (!countValidGrid(board, x, y))
        return false;
    }
  }

  return true;
}

int main()
{
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  string result;
  result = isValidSudoku(board) ? "true" : "false";
  cout << result << '\n';
}