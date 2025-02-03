#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
	int maxIncr = 1, maxDecr = 1;
	int currentIncr = 1, currentDecr = 1;

	int prev = nums[0];
	int len = nums.size();

	for(int i = 1; i < len; i++) {
		if(nums[i] < prev) {
			currentDecr++;
		} else {
			maxDecr = max(maxDecr, currentDecr);
			currentDecr = 1;
		}

		if(nums[i] > prev) {
			currentIncr++;
		} else {
			maxIncr = max(maxIncr, currentIncr);
			currentIncr = 1;
		}

		prev = nums[i];
	}

	maxDecr = max(maxDecr, currentDecr);
	maxIncr = max(maxIncr, currentIncr);

	return max(maxIncr, maxDecr);
}

int main(){
	vector<int> nums = {1,4,3,3,2};
	cout << longestMonotonicSubarray(nums);
}
