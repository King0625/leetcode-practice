#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int unique_num = 0;
	for(int num: nums) {
		unique_num ^= num;
	}

	return unique_num;
}


int main(){
	vector<int>nums = {4,1,2,1,2};
	cout << singleNumber(nums) << "\n";
	
	return 0;
}
