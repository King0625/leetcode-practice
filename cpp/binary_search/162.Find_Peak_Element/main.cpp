#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
	int length = nums.size();
	int left = 0;
	int right = length - 1;

	// must consider if the mid is on either side
        while(left < right) {
                int mid = left + (right - left) / 2;
		if((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == length - 1 || nums[mid] > nums[mid + 1])) {
			return mid;
		}
		
		if(mid < length - 1 && nums[mid + 1] > nums[mid]) {
			left = mid + 1;	
		} else {
			right = mid - 1;
		}
        }

        return left;
}

int main(){
	vector<int> nums = {2,1};
	int result = findPeakElement(nums);
	cout << result << "\n";
}
