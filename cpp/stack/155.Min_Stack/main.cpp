#include <iostream>
#include <stack>

using namespace std;

class MinStack {
	public:
		stack<pair<int,int>> elements;
		
		MinStack() {}

		void push(int val) {
			if(elements.empty()) {
				elements.push({val, val});
			} else {
				int minVal = min(getMin(), val);
				elements.push({val, minVal});
			}
		}

		void pop() {
			elements.pop();
		}

		int top() {
			auto topElement = elements.top();
			return topElement.first;
		}

		int getMin() {
			auto topElement = elements.top();
			return topElement.second;
		}
};


int main(){
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	cout << obj->getMin() << '\n';
	obj->pop();
	cout << obj->top() << '\n';
	cout << obj->getMin() << '\n';
	return 0;

}
