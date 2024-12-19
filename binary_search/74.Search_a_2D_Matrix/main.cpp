#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = matrix.size();
	int col = matrix[0].size();
	int targetRow = -1;
	bool found = false;
	for(int i = 0; i < row; i++) {
		if(matrix[i][0] <= target && matrix[i][col - 1] >= target) {
			targetRow = i;
		}
	}

	if(targetRow == -1) return false;

	int left = 0;
	int right = col - 1;
	while(left <= right) {
		int mid = (left + right) / 2;
		int got = matrix[targetRow][mid];
		if(got == target) {
			found = true;
			break;
		} else if(got < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return found;
}

int main(){
//	vector<vector<int>> matrix = {
//		{1,3,5,7},
//		{10,11,16,20},
//		{23,30,34,60}
//	};
	vector<vector<int>> matrix = {
		{1}
	};
	int target = 1;

	if(searchMatrix(matrix, target)) {
		cout << "found" << '\n';
	}
}
