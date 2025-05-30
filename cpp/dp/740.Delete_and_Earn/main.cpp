#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
	unordered_map<int> selectedNum;
	int result = INT_MIN;
	int dp = nums[0];
	selectedNum.insert(dp);
	max = max(result, dp);
	

	for(int i = 1; i < nums.size(); i++) {

	}
}

int main(){
	vector<int> nums = {2,2,3,3,3,4};
	cout << deleteAndEarn(nums) << '\n';
}
