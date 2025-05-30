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

ListNode* oddEvenList(ListNode* head) {
	if(head == nullptr || head->next == nullptr){
		return head;
	}

	ListNode *odd_node = head;
	ListNode *even_node = head->next;
	ListNode *tail = even_node;

	while(even_node && even_node->next) {
		odd_node->next = odd_node->next->next;
		even_node->next = even_node->next->next;
		
		odd_node = odd_node->next;
		even_node = even_node->next;
	}

	odd_node->next = tail;

	return head;
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

	// print_linked_list(head);
	ListNode *oddeven = oddEvenList(head);
	print_linked_list(oddeven);
	return 0;
}
