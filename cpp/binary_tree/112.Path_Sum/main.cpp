#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode* root, int sum, int targetSum, bool &got) {
	sum += root->val;
	if(!root->left && !root->right && sum == targetSum) {
		got = true;
		return;
	}
	if(root->left) preOrder(root->left, sum, targetSum, got);
	if(root->right) preOrder(root->right, sum, targetSum, got);
}

bool hasPathSum(TreeNode* root, int targetSum) {
	bool got = false;
	if(!root) return got;

	preOrder(root, 0, targetSum, got);
	return got;
}


int main(){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 21;
	if(hasPathSum(root, targetSum)) {
		cout << "yes" << '\n';
	}
	return 0;
}
