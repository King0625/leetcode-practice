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


class BSTIterator {
	private:
		queue<int> q;

		void inorder(TreeNode* root) {
			if(!root) return;

			if(root->left) inorder(root->left);
			q.push(root->val);
			if(root->right) inorder(root->right);
		}

	public:
		BSTIterator(TreeNode* root) {
			inorder(root);
		}

		int next() {
			int result = q.front();
			q.pop();
			cout << result << " ";
			return result;
		}

		bool hasNext() {
			if(q.empty()) {
				cout << "False" << " ";
			} else {
				cout << "True" << " ";
			}
			return !q.empty();
		}
};


int main(){
	TreeNode* root = new TreeNode(7);
	root->left = new TreeNode(3);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(20);

	BSTIterator* bSTIterator = new BSTIterator(root);
	bSTIterator->next();    // return 3
	bSTIterator->next();    // return 7
	bSTIterator->hasNext(); // return True
	bSTIterator->next();    // return 9
	bSTIterator->hasNext(); // return True
	bSTIterator->next();    // return 15
	bSTIterator->hasNext(); // return True
	bSTIterator->next();    // return 20
	bSTIterator->hasNext(); // return False
	return 0;
}
