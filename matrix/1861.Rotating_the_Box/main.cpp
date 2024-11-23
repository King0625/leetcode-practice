#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
{
  int rows, cols;
  rows = box.size();
  cols = box[0].size();
  vector<vector<char>> results;
  // 1. rotate
  vector<char> new_row;
  for (int i = 0; i < cols; i++)
  {
    for (int j = rows - 1; j >= 0; j--)
    {
      new_row.push_back(box[j][i]);
    }
    results.push_back(new_row);
    new_row.clear();
  }

  // 2. drop
  int row_temp = 0;
  for (int m = 0; m < results.size() - 1; m++)
  {
    for (int n = 0; n < results[0].size(); n++)
    {
      row_temp = m;
      while (row_temp >= 0 && results[row_temp + 1][n] == '.' && results[row_temp][n] != '*')
      {
        char temp = results[row_temp][n];
        results[row_temp][n] = results[row_temp + 1][n];
        results[row_temp + 1][n] = temp;
        row_temp--;
      }
    }
  }
  return results;
}

int main()
{
  vector<vector<char>> box;
  vector<char> row1 = {'#', '#', '*', '.', '*', '.'};
  vector<char> row2 = {'#', '#', '#', '*', '.', '.'};
  vector<char> row3 = {'#', '#', '#', '.', '#', '.'};
  box.push_back(row1);
  box.push_back(row2);
  box.push_back(row3);
  rotateTheBox(box);
}