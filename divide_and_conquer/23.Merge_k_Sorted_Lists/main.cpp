#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	priority_queue<int, vector<int>, greater<int>> pq;
	int listsLength = lists.size();
	for(int i = 0; i < listsLength; i++) {
		ListNode* current = lists[i];
		while(current) {
			pq.push(current->val);
			current = current->next;
		}
	}

	ListNode* dummy = new ListNode();
	ListNode* now = dummy;
	for(; !pq.empty(); pq.pop()) {
		now->next = new ListNode(pq.top());
		now = now->next;
	}

	return dummy->next;
}

int main(){

}
