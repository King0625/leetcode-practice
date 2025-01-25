#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int current = nums[0];
	int count = 1;
	for(vector<int>::iterator it = nums.begin() + 1; it != nums.end();) {
		if(*it != current) {
			current = *it;
			count = 1;
			++it;
		} else if (count == 2) {
			it = nums.erase(it);
		} else {
			count++;
			++it;
		}
	}

	int result = nums.size();
	return result;
}

int main(){
	vector<int> nums = {0,0,1,1,1,1,2,3,3};
	cout << removeDuplicates(nums);
	return 0;
}
