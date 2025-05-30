#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	int row = grid.size();
	int col = grid[0].size();
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(i - 1 >= 0 && j - 1 >= 0) {
				grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
			} else if(i - 1 >= 0) {
				grid[i][j] += grid[i-1][j];
			} else if(j - 1 >= 0) {
				grid[i][j] += grid[i][j-1];
			}
		}
	}

	return grid[row-1][col-1];
}

int main(){
	vector<vector<int>> grid = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};

	int result = minPathSum(grid);
	cout << result << "\n";
}
