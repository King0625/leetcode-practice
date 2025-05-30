#include <iostream>
#include <vector>

using namespace std;

bool canOverlap(vector<int> intv1, vector<int> intv2) {
	return 
}

vector<int> maximumWeight(vector<vector<int>>& intervals) {
	int maxScore = -1;


}

int main(){
	vector<vector<int>> intervals = {
		{1,3,2},
		{4,5,2},
		{1,5,5},
		{6,9,3},
		{6,7,1},
		{8,9,1}
	};

	vector<int> result = maximumWeight(intervals);
	for(int i: result) {
		cout << i << ' ';
	}
	return 0;
}
