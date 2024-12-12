#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int length = nums.size();
	int left = 0;
	int right = length - 1;

	int result = -1;
	while(left <= right) {
		int mid = (left + right) / 2;
		if(target == nums[mid]) {
			result = mid;
			break;
		} 

		if(nums[left] <= nums[mid]) {
			if(nums[left] <= target && target <= nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else if(nums[mid] <= target && target <= nums[right]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return result;
}


int main(){
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 6;
	cout << search(nums, target);
}
