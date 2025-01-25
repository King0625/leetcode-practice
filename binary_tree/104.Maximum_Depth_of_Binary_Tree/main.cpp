#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
	int result = 0;
	if(!root) return result;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		result++;
		int size = q.size();

		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			q.pop();

			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
		}
	}

	return result;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << maxDepth(root);
	return 0;
}
