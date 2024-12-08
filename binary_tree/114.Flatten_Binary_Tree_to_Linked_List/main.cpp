#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
	right(right) {}
};

void preOrder(TreeNode* root, vector<int> &nums) {
	if (!root) {
		return;
	}

	nums.push_back(root->val);

	preOrder(root->left, nums);
	preOrder(root->right, nums);
}

void flatten(TreeNode* root) {
	vector<int> nums;	
	preOrder(root, nums);

	TreeNode *current = root;
	for(int i = 1; i < nums.size(); i++) {
		current->left = nullptr;
		current->right = new TreeNode(nums[i]);
		current = current->right;
	}
}
