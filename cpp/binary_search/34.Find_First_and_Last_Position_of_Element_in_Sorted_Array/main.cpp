#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> result = {-1,-1};
	int left = 0;
	int right = nums.size() - 1;
	int found_index = -1;

	while(left <= right) {
		int mid = (left + right) / 2;
		if(nums[mid] == target) {
			found_index = mid;
			break;
		} else if(nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	if(found_index == -1) return result;
	int left_most_index = found_index;
	int right_most_index = found_index;
	while(left_most_index >= 0 && nums[left_most_index] == nums[found_index]) {
		left_most_index--;
	}

	while(right_most_index < nums.size() && nums[right_most_index] == nums[found_index]) {
		right_most_index++;
	}

	result[0] = left_most_index + 1;
	result[1] = right_most_index - 1;

	return result;
	
}



int main(){
	vector<int> nums = {8};
	int target = 8;

	vector<int> result = searchRange(nums, target);

	cout << result[0] << " " << result[1] << "\n";
}
