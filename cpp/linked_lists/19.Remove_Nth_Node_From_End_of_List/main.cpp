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


ListNode *formLinkedList(vector<int> nums) {
	ListNode *head = new ListNode;
	ListNode *sentinel = head;
	for(int num: nums) {
		ListNode *new_node = new ListNode(num);
		sentinel->next = new_node;
		sentinel = sentinel->next;
	}
	return head->next;

}

void print_linked_list(ListNode *head) {
	ListNode *current = head;
	while(current != nullptr) {
		cout << current->val << "->";
		current = current->next;
	}
	cout << "NULL" << "\n";
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	vector<ListNode*> node_addresses;
	ListNode *current = head;
	while(current != nullptr) {
		ListNode *node_addr = current;
		node_addresses.push_back(node_addr);
		current = current->next;
	}

	if(n == node_addresses.size()) {
		return head->next;
	}

	ListNode *target_node = node_addresses[node_addresses.size() - 1 - n];
	target_node->next = target_node->next->next;
	return head;
}


int main() {
	vector<int> nums = {1};
	ListNode *head = formLinkedList(nums);
	print_linked_list(head);

	int n = 1;
	ListNode *result = removeNthFromEnd(head, n);
	cout << "\n" ;
	print_linked_list(result);
	return 0;
}
