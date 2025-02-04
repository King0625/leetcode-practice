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

ListNode* reverseKGroup(ListNode* head, int k) {
	if(!head || k == 1) return head;

	ListNode dummy(0);
	dummy.next = head;
	ListNode* prev = &dummy;
	ListNode* current = head;

	int count = 1;
	while(current != nullptr) {
		++count;
		current = current->next;
	}

	while(count >= k) {
		current = prev->next;
		ListNode* nextOne = current->next;

		for(int i = 1; i < k; i++) {
			current->next = nextOne->next;
			nextOne->next = prev->next;
			prev->next = nextOne;
			nextOne = current->next;
		}

		prev = current;
		count -= k;
	}

	return dummy.next;
}

int main() {
	vector<int> nums = {1,2,3,4,5};
	ListNode* head = formLinkedList(nums);
	printLinkedList(head);

	int k = 2;
	ListNode* result = reverseKGroup(head, k);
	printLinkedList(result);
	return 0;
}
