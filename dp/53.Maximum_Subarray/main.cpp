#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int max_result = INT_MIN;
	int length = nums.size();
	vector<int> dp(length, 0);
	dp[0] = nums[0];
	max_result = dp[0];

	for(int i = 1; i < length; i++) {
		dp[i] = max(nums[i], nums[i] + dp[i-1]);
		if(dp[i] > max_result) {
			max_result = dp[i];
		}
	}

	return max_result;
}

int main(){
	vector<int> nums = {5,4,-1,7,8};
	cout << maxSubArray(nums) << '\n';
}
