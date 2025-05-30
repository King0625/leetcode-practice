#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums){
	int length = nums.size();
	if(length == 1) return nums[0];

	vector<int> solutions(length, 0);
	solutions[0] = nums[0];
	solutions[1] = max(nums[0], nums[1]);
	for(int i = 2; i < length; i++) {
		solutions[i] = max(solutions[i - 1], nums[i] + solutions[i - 2]);
	}
	
	return solutions[length - 1];
}

int main(){
	vector<int> nums = {1,2,3,1};
	cout << rob(nums) << '\n';

}
