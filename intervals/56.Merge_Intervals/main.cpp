#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMerge(vector<int> intv1, vector<int> intv2) {
	return intv1[0] <= intv2[0] && intv1[1] >= intv2[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
		return a[0] < b[0];
	});

	vector<vector<int>> result;
	
	int length = intervals.size();

	result.push_back(intervals[0]);
	
	int index = 0;

	for(int i = 1; i < length; i++) {
		if(!canMerge(result[index], intervals[i])) {
			result.push_back(intervals[i]);
			index++;
		} else {
			result[index] = {
				min(result[index][0],intervals[i][0]),
				max(result[index][1], intervals[i][1])
			};
		}
	}

	return result;
}

int main(){
	vector<vector<int>> intervals = {
		{1,3},{2,6},{8,10},{15,18}
	};

	vector<vector<int>> result = merge(intervals);
	int size = result.size();

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 2; j++) {
			cout << result[i][j] << "~";
		}

		cout << "\n";
	}
}
