#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> num_map;

	int length = nums.size();

	for (int i = 0; i < length; i++) {
		int sub = target - nums[i];
		if (num_map.count(sub) && i != num_map[sub]) {
			return {num_map[sub], i};
		}

		num_map[nums[i]] = i;
	}

	return {-1,-1};
}

int main() {
	vector<int> nums = {3, 3};
	int target = 6;
	vector<int> result = twoSum(nums, target);
	for (int num : result) {
		cout << num << " ";
	}
	return 0;
}
