#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void backtrack(vector<vector<int>>& combinationResult, vector<int>& comb, int sum, int index, vector<int>& candidates, int target) {
	if(sum == target) {
		combinationResult.push_back(comb);
		return;
	}

	int length = candidates.size();

	if(sum > target || index >= length) {
		return;
	}

	comb.push_back(candidates[index]);
	backtrack(combinationResult, comb, sum+candidates[index], index, candidates, target);
	comb.pop_back();
	backtrack(combinationResult, comb, sum, index+1, candidates, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> combinationResult;
	vector<int> comb;
	backtrack(combinationResult, comb, 0, 0, candidates, target);

	return combinationResult;
}


int main(){
	vector<int> candidates = {2,3,6,7};
	int target = 7;
	vector<vector<int>> result = combinationSum(candidates, target);
	int size = result.size();
	for(int i = 0; i < size; i++) {
		for(int val: result[i]) {
			cout << val << ' ';
		}

		cout << '\n';
	}
	return 0;
}
