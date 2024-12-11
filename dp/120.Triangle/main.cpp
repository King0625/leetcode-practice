#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	int row_count = triangle.size();
	for(int i = 1; i < row_count; i++) {
		int col_size = triangle[i].size();
		for(int j = 0; j < col_size - 1; j++) {
			if(j != 0 && j != col_size - 1) {
				triangle[i][j] = min(
						triangle[i][j],
						triangle[i][j] - triangle[i-1][j-1] + triangle[i-1][j]
						);
			} else {
				triangle[i][j] += triangle[i-1][j];
			}
			triangle[i][j+1] += triangle[i-1][j];
		}
	}

	int min = INT_MAX;
	for(int k = 0; k < row_count; k++) {
		int sum = triangle[row_count - 1][k];
		cout << sum << " ";
		if(sum < min) {
			min = sum;
		}
	}
	cout << "\n";
	return min;
}

int main(){
	vector<vector<int>> triangle = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};

	int result = minimumTotal(triangle);
	cout << result << "\n";
	return 0;
}
