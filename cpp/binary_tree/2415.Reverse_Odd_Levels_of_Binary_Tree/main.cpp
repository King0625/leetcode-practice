#include <iostream>
#include <deque>
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

TreeNode* reverseOddLevels(TreeNode* root) {
	deque<TreeNode*> q;
	q.push_back(root);
	int level = 0;

	while(!q.empty()) {
		int size = q.size();
		vector<int> levelValues;
		for(TreeNode* i: q) {
			levelValues.push_back(i->val);
		}

		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			if(level % 2) {

				current->val = levelValues[size - 1 - i];
			}

			q.pop_front();
			if(current->left) q.push_back(current->left);
			if(current->right) q.push_back(current->right);
		}

		level++;
	}

	return root;
}


void bfs(TreeNode* root) {
	if(!root) return;

	deque<TreeNode*> q;
	q.push_back(root);

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			TreeNode* current = q.front();
			cout << current->val << ' ';
			q.pop_front();
			if(current->left) q.push_back(current->left);
			if(current->right) q.push_back(current->right);
		}
	}
}

int main(){
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(3);
	root->right = new TreeNode(5);

	root->left->left = new TreeNode(8);
	root->left->right = new TreeNode(13);

	root->right->left = new TreeNode(21);
	root->right->right = new TreeNode(34);

	TreeNode* result = reverseOddLevels(root);
	bfs(result);
	return 0;
}
