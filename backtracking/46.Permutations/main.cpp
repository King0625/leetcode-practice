#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<bool>& visited, vector<int>& perm) {
	int numLength = nums.size();
	int permSize = perm.size();
	if(permSize == numLength) {
		result.push_back(perm);
		return;
	}

	for(int i = 0; i < numLength; i++) {
		if(visited[i]) continue;

		perm.push_back(nums[i]);
		visited[i] = true;
		backtrack(nums, result, visited, perm);

		perm.pop_back();
		visited[i] = false;
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	int numLength = nums.size();
	vector<bool> visited(numLength, false);
	vector<vector<int>> result;
	vector<int> perm;
	backtrack(nums, result, visited, perm);
	return result;
}

int main(){
	vector<int> nums = {1,2,3};
	int numLength = nums.size();
	vector<vector<int>> result = permute(nums);
	int size = result.size();
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < numLength; j++) {
			cout << result[i][j] << ' ';
		}

		cout << '\n';
	}

}
