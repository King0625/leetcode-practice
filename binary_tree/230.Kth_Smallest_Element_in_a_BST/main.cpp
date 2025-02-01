#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root, int& k, int& ans) {
	if(!root) {
		return;
	}

	inorder(root->left, k, ans);
	k--;
	if(k == 0) {
		ans = root->val;
		return;
	}
	inorder(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
	int ans = -1;
	inorder(root, k, ans);
	return ans;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	int k = 1;
	cout << kthSmallest(root, k) << '\n';
}
