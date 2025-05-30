#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int ones = 0;
	int twos = 0;

	for(int i = 0; i < nums.size(); i++) {
		ones = (~twos) & (ones ^ nums[i]);
		twos = (~ones) & (twos ^ nums[i]);
	}

	return ones;
}


int main(){
	vector<int> nums = {2,2,3,2};
	cout << singleNumber(nums) << "\n";	
	return 0;
}
