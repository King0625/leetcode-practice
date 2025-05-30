#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
	set<int, less<int>> s;

    SmallestInfiniteSet() {
        for(int i = 1; i <= 1000; i++) {
			s.insert(i);
		}
    }
    
    int popSmallest() {
        auto smallest = s.begin();
		int result = *smallest;
		s.erase(smallest);
		return result;
    }
    
    void addBack(int num) {
		s.insert(num);
    }
};


int main(){
	SmallestInfiniteSet* obj = new SmallestInfiniteSet();
	obj->addBack(2);
	cout << obj->popSmallest() << '\n';
	cout << obj->popSmallest() << '\n';
	cout << obj->popSmallest() << '\n';
	obj->addBack(1);
	cout << obj->popSmallest() << '\n';
	cout << obj->popSmallest() << '\n';
	cout << obj->popSmallest() << '\n';

	return 0;
}
