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

int dfs_preorder(TreeNode *root, int sum) {
	TreeNode *current = root;

	if(current == nullptr) return 0;

	sum = sum * 10 + current->val;

	if(current->left == nullptr && current->right == nullptr) {
		return sum;
	}

	return dfs_preorder(current->left, sum) + dfs_preorder(current->right, sum);
}

int sumNumbers(TreeNode* root) {
	return dfs_preorder(root, 0);
}

int main(){
        TreeNode *root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        //root->left->left = new TreeNode(7);
        //root->left->right = new TreeNode(-8);
	int result = sumNumbers(root);
	cout << result << "\n";
	return 0;
}
