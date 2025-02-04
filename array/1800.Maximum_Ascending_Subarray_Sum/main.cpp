#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxAscendingSum(vector<int>& nums) {
	int len = nums.size();
	int prev = nums[0];
	int currentSum = prev, maxSum = prev;

	for(int i = 0; i < len; i++) {
		if(nums[i] <= prev) {
			maxSum = max(maxSum, currentSum);
			currentSum = nums[i];
		} else {
			currentSum += nums[i];
		}

		prev = nums[i];
	}

	maxSum = max(maxSum, currentSum);

	return maxSum;
}

int main(){
	vector<int> nums = {12,17,15,13,10,11,12};
	cout << maxAscendingSum(nums);
}
