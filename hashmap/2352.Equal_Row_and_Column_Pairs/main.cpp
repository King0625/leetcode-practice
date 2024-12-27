#include <iostream>
#include <vector>

using namespace std;

int equalPairs(vector<vector<int>>& grid) {
	int count = 0;
	int size = grid.size();
	
	vector<vector<int>> rows_map(size, vector<int>(size, 0));
	vector<vector<int>> cols_map(size, vector<int>(size, 0));
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			rows_map[i][j] = grid[i][j];
		}
	}

	for(int j = 0; j < size; j++) {
		for(int i = 0; i < size; i++) {
			cols_map[j][i] = grid[i][j];
		}
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(rows_map[i] == cols_map[j]) {
				count++;
			}
		}
	}

	return count;
}

int main(){
	vector<vector<int>> grid = {
		{3,1,2,2},
		{1,4,4,5},
		{2,4,2,2},
		{2,4,2,2}
	};

	cout << equalPairs(grid) << '\n';
	return 0;
}
