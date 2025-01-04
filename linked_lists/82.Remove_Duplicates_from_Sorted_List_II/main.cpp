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

ListNode* deleteDuplicates(ListNode* head) {
	if(!head || !head->next) return head;

	ListNode* dummy = new ListNode(0, head);

	ListNode* prev = dummy;
	ListNode* current = head;

	while(current) {
		if(current->next && current->val == current->next->val) {
			while(current->next && current->val == current->next->val) {
				current = current->next;
			}

			prev->next = current->next;
		} else {
			prev = current;
		}

		current = current->next;
	}

	return dummy->next;
}

int main(){
	vector<int> nums = {1,2,3,3,4,4,5};
	ListNode* head = formLinkedList(nums);
	ListNode* result = deleteDuplicates(head);
	print_linked_list(result);
	return 0;
}
