#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_map<int, bool> numMap;
	for (int num : nums) {
		numMap[num] = true;
	}

	int maxLen = 0;

	for (int num : nums) {
		if(!numMap.count(num - 1)) {
			int currentLen = 1;
			int i = 1;
			while (numMap.count(num + i)) {
				currentLen++;
				i++;
			}

			maxLen = max(maxLen, currentLen);

		}
	}

	return maxLen;
}


int main(){
	vector<int> nums = {100,4,200,1,3,2};
	cout << longestConsecutive(nums) << '\n';
}
