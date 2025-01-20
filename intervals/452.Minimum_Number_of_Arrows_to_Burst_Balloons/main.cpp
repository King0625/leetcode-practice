#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
	int result = 1;
	sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
			return a[1] < b[1];
			});

	int length = points.size();

	int prevEnd = points[0][1];

	for(int i = 1; i < length; i++) {
		if(points[i][0] > prevEnd) {
			result++;
			prevEnd = points[i][1];
		}
	}

	return result;
}


int main(){
	vector<vector<int>> points = {
		{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}
	};

	cout << findMinArrowShots(points);
	return 0;
}
