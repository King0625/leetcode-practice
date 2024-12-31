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


vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	if(!root) return result;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		vector<int> levelElements;

		int size = q.size();

		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			levelElements.push_back(current->val);
			q.pop();

			if(current->left)  q.push(current->left);
			if(current->right) q.push(current->right);
		}

		result.push_back(levelElements);
	}

	return result;
}

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<vector<int>> result = levelOrder(root);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}
