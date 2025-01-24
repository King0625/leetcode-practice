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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* dummy = new ListNode(-101);
	ListNode* current = dummy;
	while(list1 || list2) {
		if(list1 && list2) {
			if(list1->val >= list2->val) {
				current->next = new ListNode(list2->val);
				list2 = list2->next;
			} else {
				current->next = new ListNode(list1->val);
				list1 = list1->next;
			}
		} else if(!list1) {
			current->next = new ListNode(list2->val);
			list2 = list2->next;
		} else {
			current->next = new ListNode(list1->val);
			list1 = list1->next;
		}

		current = current->next;
	}

	return dummy->next;
}

int main() {
	vector<int> nums1 = {5};
	ListNode *list1 = formLinkedList(nums1);
	vector<int> nums2 = {1,3,4};
	ListNode *list2 = formLinkedList(nums2);

	ListNode* head = mergeTwoLists(list1, list2);

	print_linked_list(head);

	return 0;
}
