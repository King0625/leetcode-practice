#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<int> &nums, int k){
	int len = nums.size();
	k %= len;
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

int main(){
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	int k = 3;
	rotate(nums, k);
	for (int num : nums)
	{
		cout << num << " ";
	}
	return 0;
}
