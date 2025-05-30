#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	if(!head || !head->next) {
		return head;
	}

	ListNode *current = head;
	ListNode *prev = nullptr;
	while(current) {
		ListNode *forward = current->next;
		current->next = prev;
		prev = current;
		current = forward;
	}
	return prev;
}

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

int main() {
	vector<int> nums = {1};
	ListNode *head = formLinkedList(nums);

	// print_linked_list(head);
	return 0;
}
