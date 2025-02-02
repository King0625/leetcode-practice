#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& nums) {
	bool sorted = true;
	bool rotated = false;
	int firstNum = nums[0];
	int len = nums.size();
	int prev = firstNum;
	for(int i = 1; i < len; i++) {
		if(nums[i] < prev) {
			if(rotated) {
				sorted = false;
				break;
			} else {
				rotated = true;
				if(firstNum < nums[len - 1]) {
					sorted = false;
					break;
				}
			}
		}
		prev = nums[i];
	}

	return sorted;
}

int main(){
	vector<int> nums = {2,7,4,1,2,6,2};
	if(check(nums)) {
		cout << "True" << '\n';
	}
}
