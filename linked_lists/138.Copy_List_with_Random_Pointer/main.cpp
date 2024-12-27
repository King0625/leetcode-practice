#include <iostream>
#include <unordered_map>

class Node {
	public:
		int val;
		Node* next;
		Node* random;

		Node(int _val) {
			val = _val;
			next = NULL;
			random = NULL;
		}
};

Node* copyRandomList(Node* head) {
	if(head == nullptr) {
		return head;
	}

	unordered_map<Node*, Node*> nodes;
	
	Node* copy = new Node(0);
	Node* current = copy;

	while(head != nullptr) {
		if(!nodes.count(head)) {
			nodes[head] = new Node(head->val);
		}

		if(head->next != nullptr && !nodes.count(head->next)) {
			nodes[head->next] = new Node(head->next->val);
		}

		if(head->random != nullptr && !nodes.count(head->random)) {
			nodes[head->random] = new Node(head->random->val);
		}

		current->next = head != nullptr ? nodes[head] : nullptr;
		current->next->random = head->random != nullptr ? nodes[head->random] : nullptr;
		head = head->next;
		current = current->next;
	}

	return copy->next;
}
