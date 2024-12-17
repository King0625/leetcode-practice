#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			if(i != j) {
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}

	for(int m = 0; m < n; m++) {
		reverse(matrix[m].begin(), matrix[m].end());
	}
}


int main(){
	vector<vector<int>> matrix = {
		{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16}
	};

	rotate(matrix);

	for(auto &vec: matrix) {
		for(int val: vec) {
			cout << val << " ";
		}

		cout << "\n";
	}
}
