#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> results;
	int productAll = 1;
	int productWithoutZero = 1;
	int zeroCounts = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == 0) {
			zeroCounts++;
		} else {
			productWithoutZero *= nums[i];
		}
		productAll *= nums[i];
	}

	for(int j = 0; j < nums.size(); j++) {
		int result = 1;
		if(nums[j] == 0) {
			if(zeroCounts - 1 == 0) {
				result = productWithoutZero;
			} else {
				result = 0;
			}

		} else {
			result = productAll / nums[j];
		}

		results.push_back(result);
	}

	return results;
}

int main(){
	vector<int> nums = {1,2,0,4};
	vector<int> results = productExceptSelf(nums);
	for(int result: results) {
		cout << result << " ";
	}
}
