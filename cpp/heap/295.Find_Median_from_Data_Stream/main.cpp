#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
	public:
		priority_queue<int, vector<int>, greater<int>> upper;
		priority_queue<int> lower;

		MedianFinder() {}

		void addNum(int num) {
			if(upper.size() == 0 && lower.size() == 0) {
				upper.push(num);
			} else if(upper.size() > 0 && num >= upper.top()) {
				upper.push(num);
			} else {
				lower.push(num);
			}

			// rebalance
			if(upper.size() - lower.size() == 2) {
				lower.push(upper.top());
				upper.pop();
			} else if(lower.size() - upper.size() == 2) {
				upper.push(lower.top());
				lower.pop();
			}
		}

		double findMedian() {
			if(upper.size() > lower.size())  {
				return upper.top();
			} else if (upper.size() < lower.size()) {
				return lower.top();
			} else {
				return ( upper.top() + lower.top() ) / 2.0;
			}
		}
};


int main(){
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(4);
	cout << obj->findMedian() << '\n';
	obj->addNum(3);
	cout << obj->findMedian() << '\n';

}
