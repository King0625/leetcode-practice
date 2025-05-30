#include <iostream>
#include <vector>

using namespace std;

vector<int> findRightInterval(vector<vector<int>>& intervals) {
	int length = intervals.size();
	vector<int> results(length, 0);
	if(length == 1) {
		results[0] = -1;
		return results;
	}


}

int main(){
	vector<vector<int>> intervals = {
		{3,4},
		{2,3},
		{1,2}
	};

	vector<int> results = findRightInterval(intervals);

	for(int val: results) {
		cout << val << ' ';
	}

	cout << '\n';
}
