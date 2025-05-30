#include <iostream>
#include <vector>

using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
	const int n = values.size();
	if(n == 2) return values[0] + values[1] + 0 - 1;

	int dp = values[0];
	int score = 0;

	for(int i = 1; i < n; i++) {
		int current = values[i];

		score = max(score, dp + current - i);
		dp = max(dp, current + i);
	}

	return score;
}

int main(){
	vector<int> values = {8,1,5,2,16,7,1,12};
	cout << maxScoreSightseeingPair(values) << '\n';
}
