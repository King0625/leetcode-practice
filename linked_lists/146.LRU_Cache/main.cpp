#include <iostream>
#include <unordered_map>

using namespace std;

// doubly-linked-lists
class Node {
	public:
		int key;
		int val;
		Node* next;
		Node* prev;

		Node(int key, int val) {
			this->key = key;
			this->val = val;
		}
};

class LRUCache {
	public:
		Node* head = new Node(-1,-1);
		Node* tail = new Node(-1,-1);

		int cap;

		unordered_map<int, Node*> indexes;


		LRUCache(int capacity) {
			cap = capacity;
			head->next = tail;
			tail->prev = head;
		}

		void addNode(Node* newNode) {
			Node* temp = head->next;
			newNode->next = temp;
			newNode->prev = head;

			head->next = newNode;
			temp->prev = newNode;
		}

		void deleteNode(Node* deletedNode) {
			Node* prev = deletedNode->prev;
			Node* next = deletedNode->next;

			prev->next = next;
			next->prev = prev;
		}

		int get(int key) {
			if(indexes.find(key) == indexes.end()) return -1;
			Node* current = indexes[key];
			indexes.erase(key);
			deleteNode(current);
			addNode(current);

			indexes[key] = head->next;

			return current->val;
		}

		void put(int key, int value) {
			if(indexes.find(key) != indexes.end()) {
				Node* current = indexes[key];
				indexes.erase(key);
				deleteNode(current);
			}

			int listLen = indexes.size();
			if(listLen == cap) {
				indexes.erase(tail->prev->key);
				deleteNode(tail->prev);
			}

			addNode(new Node(key, value));
			indexes[key] = head->next;
		}
};


int main(){
	LRUCache* obj = new LRUCache(2);
	obj->put(1,1);
	obj->put(2,2);
	cout << obj->get(1) << '\n';
	obj->put(3,3);
	cout << obj->get(2) << '\n';
	obj->put(4,4);
	cout << obj->get(1) << '\n';
	cout << obj->get(3) << '\n';
	cout << obj->get(4) << '\n';

	return 0;
}
