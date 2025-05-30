#include <iostream>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> maxHeap;
	for(int num: nums) {
		maxHeap.emplace(num);
	}

	for(int i = 0; i < k - 1; i++) {
		maxHeap.pop();
	}

	return maxHeap.top();
}


int main(){
	vector<int> nums = {3,2,1,5,6,4};
	int k = 2;
	cout << findKthLargest(nums, k);
	return 0;
}
