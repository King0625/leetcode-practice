#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 1. need to indicate the sorted groups
// 2. mapping
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
	priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
	
	vector<queue<int>> groups;
	unordered_map<int, int> numToGroup;

	for(; !pq.empty(); pq.pop()) {
		int groupsLen = groups.size();
		int el = pq.top();
		if(!groupsLen || el - groups[groupsLen - 1].back() > limit) {
			queue<int> q;
			q.push(el);
			groups.push_back(q);
			numToGroup[el] = groupsLen;
		} else {
			groups[groupsLen - 1].push(el);
			numToGroup[el] = groupsLen - 1;
		}
	}

	vector<int> result;
	
	for(int val: nums) {
		int groupIdx = numToGroup[val];
		int pushed = groups[groupIdx].front();
		groups[groupIdx].pop();
		result.push_back(pushed);
	}

	return result;
}

int main(){
	vector<int> nums = {1,7,6,18,2,1};
	int limit = 3;
	vector<int> result = lexicographicallySmallestArray(nums, limit);
	for(int val: result) {
		cout << val << ' ';
	}

	return 0;
}
