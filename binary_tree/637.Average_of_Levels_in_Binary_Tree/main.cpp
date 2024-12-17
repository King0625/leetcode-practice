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

vector<double> averageOfLevels(TreeNode* root) {
	vector<double> avgs;
	if(!root) return avgs;	
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()) {
		double sum = 0.0;
		int size  = q.size();
		for(int i = 0; i < size; i++) {
			TreeNode *current = q.front();
			sum += current->val;
			q.pop();
			if(current->left) q.push(current->left);
			if(current->right) q.push(current->right);
		}

		double avg = sum / size;
		avgs.push_back(avg);

	}

	return avgs;
}


int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(7);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(7);
	root->left->right = new TreeNode(-8);

	vector<double> result = averageOfLevels(root);
	for(double val: result) {
		cout << val << " ";
	}
	return 0;
}
