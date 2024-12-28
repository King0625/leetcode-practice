#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	vector<int> rowsZero;
	vector<int> colsZero;
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			if(matrix[i][j] == 0) {
				rowsZero.push_back(i);
				colsZero.push_back(j);
			}
		}
	}

	for(int rowNum: rowsZero) {
		for(int col = 0; col < matrix[0].size(); col++) {
			matrix[rowNum][col] = 0;
		}
	}

	for(int colNum: colsZero) {
		for(int row = 0; row < matrix.size(); row++) {
			matrix[row][colNum] = 0;
		}
	}
}

int main(){
	vector<vector<int>> matrix = {
		{0,1,2,0},
		{3,4,5,2},
		{1,3,1,5}
	};

	setZeroes(matrix);

	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			cout << matrix[i][j] << ' ';
		}

		cout << '\n';
	}
}
