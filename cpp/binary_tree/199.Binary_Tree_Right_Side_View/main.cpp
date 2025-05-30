#include <iostream>
#include <vector>
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

vector<int> rightSideView(TreeNode* root) {
	vector<int> results;
	if(!root) {
		return results;
	}

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			q.pop();
			if(i == size - 1) {
				results.push_back(current->val);
			}

			if(current->left) {
				q.push(current->left);
			}

			if(current->right) {
				q.push(current->right);
			}
		}
	}

	return results;
}


int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(5);
	vector<int> results = rightSideView(root);
	for(int val: results) {
		cout << val << ' ';
	}

	return 0;
}
