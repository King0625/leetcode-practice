#include <iostream>
#include <vector>

using namespace std;

int waysToSplitArray(vector<int>& nums) {
	int ways = 0;
	int length = nums.size();
	long long left_sum = 0;
	long long right_sum = 0;

	for(int i = 0; i < length; i++) {
		right_sum += nums[i];
	}


	for(int i = 0; i < length - 1; i++) {
		left_sum += nums[i];
		right_sum -= nums[i];

		if(left_sum >= right_sum) {
			ways++;
		}
	}

	return ways;
}

int main(){
	vector<int> nums = {10,4,-8,7};
	cout << waysToSplitArray(nums) << '\n';
	return 0;
}
