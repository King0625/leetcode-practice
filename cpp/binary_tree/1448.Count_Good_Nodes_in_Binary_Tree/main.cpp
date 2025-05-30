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

void preorder(int &result, TreeNode *root, int max = INT_MIN) {
	int val = root->val;
	if(root->val >= max) {
		result++;
		max = val;
	}
}
	if(root->left){
		preorder(result, root->left, max);
	}
	if(root->right){
		preorder(result, root->right, max);
	}	
}

int goodNodes(TreeNode* root) {
	int result = 0;
	preorder(result, root);
	return result;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	//root->right = new TreeNode(4);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	//root->right->left = new TreeNode(1);
	int result = goodNodes(root);
	cout << result << "\n";
}

