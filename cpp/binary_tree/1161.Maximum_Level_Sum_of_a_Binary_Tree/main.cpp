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

void bfs(TreeNode *root, vector<int> &level_sum) {
	queue<TreeNode*> q;
	q.push(root);
	int level = 1;
	while(!q.empty()) {
		level_sum.push_back(0);
		int queue_size = q.size();
		for (int i = 0; i < queue_size; i++) {
			TreeNode *current = q.front();
			level_sum[level - 1] += current->val;		

			q.pop();

			if (current->left) q.push(current->left);
			if (current->right) q.push(current->right);
		}

		level++;
	}
}

int maxLevelSum(TreeNode* root) {
	vector<int> level_sum;

	bfs(root, level_sum);
	int max = INT_MIN;
	int max_level = 0;
	for(int i = 0; i < level_sum.size(); i++) {
		if(max < level_sum[i]) {
			max = level_sum[i];
			max_level = i + 1;
		}
	}

	return max_level;
}

int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(7);
	root->right = new TreeNode(0);
	root->left->left = new TreeNode(7);
	root->left->right = new TreeNode(-8);

	cout << maxLevelSum(root);
	return 0;
}
