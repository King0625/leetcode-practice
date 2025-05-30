#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while(left < right) {
		int mid = (left + right) / 2;
		if(nums[mid] == target) {
			return mid;
		} else if(nums[mid] > target) {
			if(mid - 1 < 0 || nums[mid - 1] < target) {
				return mid;
			} else {
				right = mid;	
			}
		} else {
			if(mid + 1 == nums.size() || nums[mid + 1] > target) {
				return mid + 1;
			} else {
				left = mid + 1;
			}
		}
	}

	if(left >= nums.size() - 1 && nums[left] < target) {
		return left + 1;
	}
	return left;
}

int main(){
	vector<int> nums = {1,3,5,6};
	int target = 7;
	int result = searchInsert(nums, target);
	cout << result << "\n";
}
