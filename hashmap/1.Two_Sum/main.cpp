#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	map<int, int> num_map;
	for (int i = 0; i < nums.size(); i++) {
		num_map[nums[i]] = i;
	}

	vector<int> result;
	for (int j = 0; j < nums.size(); j++) {
		int sub = target - nums[j];
		if (num_map.count(sub) && j != num_map[sub]) {
			result = {num_map[sub], j};
			break;
		}
	}

	return result;
}

int main() {
	vector<int> nums = {3, 2, 4};
	int target = 6;
	vector<int> result = twoSum(nums, target);
	for (int num : result) {
		cout << num << " ";
	}
	cout << "Hi";
	return 0;
}
