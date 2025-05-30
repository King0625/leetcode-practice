#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
	int len = nums.size();
	if(len == 1) return true;

	// find max reach index
	int lastMaxReach = nums[0];
	for(int i = 0; i < len - 1; i++) {
		int maxReach = nums[i] + i;
		if(maxReach >= len - 1) {
			return true;
		}

		// stucked at start and last 2nd index
		if(nums[i] == 0 && lastMaxReach <= i) {
			return false;
		}

		lastMaxReach = max(lastMaxReach, maxReach);
	}

	return false;
}

int main(){
	vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
	if(canJump(nums)) {
		cout << "Yes" << '\n';
	}
	return 0;
}
