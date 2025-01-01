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

void inorder(TreeNode* root, vector<int>& results) {
	if(!root) return;

	if(root->left) inorder(root->left, results);
	results.push_back(root->val);
	if(root->right) inorder(root->right, results);
}

int kthSmallest(TreeNode* root, int k) {
	vector<int> results;
	inorder(root, results);
	return results[k-1];
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	int k = 1;
	cout << kthSmallest(root, k) << '\n';
}
