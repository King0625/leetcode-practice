#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* formLinkedList(vector<int> nums) {
	ListNode* head = new ListNode;
	ListNode* sentinel = head;
	for(int num: nums) {
		ListNode* new_node = new ListNode(num);
		sentinel->next = new_node;
		sentinel = sentinel->next;
	}
	return head->next;

}

void printLinkedList(ListNode* head) {
	ListNode* current = head;
	while(current != nullptr) {
		cout << current->val << "->";
		current = current->next;
	}
	cout << "NULL" << "\n";
}

int main() {
	vector<int> nums = {1};
	ListNode* head = formLinkedList(nums);

	// printLinkedList(head);
	return 0;
}
