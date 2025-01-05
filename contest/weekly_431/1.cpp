#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool equal(int prod, int lcm, int gcd) {
	return prod == lcm * gcd;
}
int maxLength(vector<int>& nums) {
	int size = nums.size();
	int maxLength = 0;
	int currentLength = 1;
	int currentLcm = 0;
	int currentGcd = 0;
	int currentProduct = 0;
	for(int i = 0; i < size; i++) {
		int j = i;
		currentProduct = nums[i];
		currentLcm = nums[i];
		currentGcd = nums[i];
		currentLength = 1;
		while(j < size - 1) {
			j++;
			currentProduct *= nums[j];
			currentLcm = lcm(currentLcm, nums[j]);
			currentGcd = gcd(currentGcd, nums[j]);
			if(equal(currentProduct, currentLcm, currentGcd)) {
				currentLength++;
			} else {
				currentLcm = 0;
				currentGcd = 0;
				currentProduct = 0;
				break;
			}
		}

		maxLength = max(currentLength, maxLength);
	}

	return maxLength;
}

int main(){
	vector<int> nums = {1,2,1,2,1,1,1};
	cout << maxLength(nums);
	return 0;
}
