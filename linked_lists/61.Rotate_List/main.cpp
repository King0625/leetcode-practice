#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	// calculate node count
	ListNode *last = head;

	if(!last || !last->next) {
		return head;
	}

	int count = 1;
	
	while(last->next) {
		last = last->next;
		count++;
	}

	k = k % count;

	if(k == 0) {
		return head;
	}

	last->next = head;

	int steps = count - k - 1;

	ListNode *current = head;

	for(int i = 0; i < steps; i++) {
		current = current->next;			
	}

	ListNode *result = current->next;

	current->next = nullptr;

	return result;
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
	vector<int> nums = {1,2,3,4,5};
	ListNode *head = formLinkedList(nums);
	print_linked_list(head);
	int k = 2;

	ListNode *result = rotateRight(head, k);
	print_linked_list(result);
	return 0;
}
