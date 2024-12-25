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


vector<int> largestValues(TreeNode* root) {
	vector<int> results;
	if(!root) return results;

	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		int largest = INT_MIN;
		int queueSize = q.size();
		for(int i = 0; i < queueSize; i++) {
			TreeNode* current = q.front();
			if(largest < current->val) {
				largest = current->val;
			}
			q.pop();
			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
		}

		results.push_back(largest);
	}	
	return results;
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->right = new TreeNode(2);
//	root->left->left = new TreeNode(5);
//	root->left->right = new TreeNode(3);
//	root->right->right = new TreeNode(9);
		
	vector<int> results = largestValues(root);
	for(int result: results) {
		cout << result << ' ';
	}
}

