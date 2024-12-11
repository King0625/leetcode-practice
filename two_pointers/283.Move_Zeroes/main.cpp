#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	for(int i = 1; i < nums.size(); i++) {
		if(nums[i] != 0) {
			int index = i;
			while(index > 0 && nums[index-1] == 0) {
				swap(nums[index], nums[index-1]);
				index--;
			}
		}
	}
}


int main(){
	vector<int> nums = {0};
	moveZeroes(nums);
	for(int num: nums) {
		cout << num << " ";
	}
}
