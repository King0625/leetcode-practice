#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool preorder(TreeNode* node, ListNode* head) {
	if(!head) return true;
	if(!node) return false;

	if(node->val != head->val) return false;

	return preorder(node->left, head->next) || preorder(node->right, head->next);
}

bool checkPath(TreeNode* node, ListNode* head) {
	if(!node) return false;
	if(preorder(node, head)) return true;

	return checkPath(node->left, head) || checkPath(node->right, head);
}

bool isSubPath(ListNode* head, TreeNode* root) {
	return checkPath(root, head);
}


int main(){
	ListNode* head = new ListNode(2);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);

	TreeNode* root = new TreeNode(2);
	//	root->left = new TreeNode(4);
	//	root->left->right = new TreeNode(2);
	//	root->left->right->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(2);
	root->right->right->right = new TreeNode(1);
	//	root->right->left = new TreeNode(2);
	//	root->right->left->left = new TreeNode(6);
	//	root->right->left->right = new TreeNode(8);
	//	root->right->left->right->left = new TreeNode(1);
	//	root->right->left->right->right = new TreeNode(3);

	if(isSubPath(head, root)) {
		cout << "Yes" << '\n';
	}

	return 0;
}
