#include <iostream>
#include <vector>

using namespace std;

int shortestSubarray(vector<int> &nums, int k) {
	long long left_sum = 0;
	long long right_sum = 0;
	
	for(int num: nums) {
		right_sum += num;
	}

	int length = nums.size();
	int result = -1;
	int left = 0;
	int right = 0;
	while(left < length) {
		left_sum += nums[right];
		right++;

		if(left_)
	}

	return result;

}

int main() {
	vector<int> nums = {2,-1,2};
	int k = 3;
	cout << shortestSubarray(nums, k) << endl;
	return 0;
}
