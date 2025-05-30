#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int max_result = INT_MIN;
	int length = nums.size();
	int latest_result = nums[0];
	max_result = latest_result;

	for(int i = 1; i < length; i++) {
		latest_result = max(nums[i], nums[i] + latest_result);
		if(latest_result > max_result) {
			max_result = latest_result;
		}
	}

	return max_result;
}

int main(){
	vector<int> nums = {5,4,-1,7,8};
	cout << maxSubArray(nums) << '\n';
}
