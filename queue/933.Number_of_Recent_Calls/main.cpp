#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
	public:
		queue<int> requests;
		RecentCounter() {
		}

		int ping(int t) {
			int min = t - 3000;
			requests.push(t);
			while(true) {
				if(requests.front() < min) {
					requests.pop();
				} else {
					break;
				}
			}
			return requests.size();
		}
};

int main() {
	RecentCounter* obj = new RecentCounter();
	cout << obj->ping(1) << '\n';
	cout << obj->ping(100) << '\n';
	cout << obj->ping(3001) << '\n';
	cout << obj->ping(3002) << '\n';
	cout << obj->ping(3005) << '\n';
}

