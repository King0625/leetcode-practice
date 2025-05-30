#include <iostream>
#include <vector>

using namespace std;

bool isArraySpecial(vector<int>& nums) {
	int len = nums.size();
	if(len == 1) return true;
	
	for(int i = 1; i < len; i++) {
		if(nums[i] % 2 == nums[i-1] % 2) {
			return false;
		}
	}

	return true;
}

int main(){
	vector<int> nums = {2,1,4};
	if(isArraySpecial(nums)) {
		cout << "Yes";
	}
}
