#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<vector<int>> &results, vector<int> &nums, int start, int n, int k) {
	if(nums.size() == k) {
		results.push_back(nums);
		return;
	}

	for(int i = start; i <= n; i++) {
		nums.push_back(i);
		backtrack(results, nums, i+1, n, k);
		nums.pop_back();
	}
}

vector<vector<int>> combine(int n, int k){
	vector<vector<int>> results;
	vector<int> nums;

	backtrack(results, nums, 1, n, k);
	return results;
}

int main(){
	int n = 4;
	int k = 2;

	vector<vector<int>> results = combine(n, k);
	for(auto &result: results) {
		for(auto el: result) {
			cout << el << " ";
		}
		cout << "\n";
	}
	return 0;
}
