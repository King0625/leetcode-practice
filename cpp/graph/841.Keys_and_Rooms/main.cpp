#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
	bool canVisit = true;
	int roomCount = rooms.size();


}


int main(){
	vector<vector<int>> rooms = {
		{1,3},{3,0,1},{2},{0}
	};

	if(canVisitAllRooms(rooms)) {
		cout << "yes\n";
	}
}
