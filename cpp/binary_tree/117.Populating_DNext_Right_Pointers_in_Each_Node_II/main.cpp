#include <iostream>
#include <queue>

using namespace std;

class Node {
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;

		Node() : val(0), left(NULL), right(NULL), next(NULL) {}

		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
	if(!root) return root;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()) {
		int size = q.size();
		Node* prevNode = q.front();
		q.pop();
		if(prevNode->left) q.push(prevNode->left);
		if(prevNode->right) q.push(prevNode->right);

		for(int i = 0; i < size - 1; ++i) {
			Node* nextNode = q.front();
			prevNode->next = nextNode;
			q.pop();
			if(nextNode->left) q.push(nextNode->left);
			if(nextNode->right) q.push(nextNode->right);
			prevNode = nextNode;
		}

		prevNode->next = nullptr;
	}

	return root;
}


int main(){
	return 0;
}
