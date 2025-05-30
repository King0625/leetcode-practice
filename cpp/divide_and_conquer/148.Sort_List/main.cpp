#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* sortList(ListNode* head) {
	return head;
}

int main(){
	ListNode* head = new ListNode(-1);
	head->next = new ListNode(5);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(0);

	ListNode* result = sortList(head);
	while(result) {
		cout << result->val << "->";
		result = result->next;
	}
}
