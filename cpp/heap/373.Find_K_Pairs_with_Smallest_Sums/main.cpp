#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	unordered_map<int, vector<int>> sumMap;
	int len1 = nums1.size();
	int len2 = nums2.size();

}

int main(){
	vector<int> nums1 = {1,7,11};
	vector<int> nums2 = {2,4,6};
	vector<vector<int>> result = kSmallestPairs(nums1, nums2);
	int size = result.size();
	for(int i = 0; i < size; i++) {
		for(int val: result[i]) {
			cout << val << ' ';
		}

		cout << '\n';
	}
}
