#include <iostream>

using namespace std;

bool areAlmostEqual(string s1, string s2) {
	int len = s1.size();
	char diff1 = '0', diff2 = '0';
	bool swapped = false;
	
	for(int i = 0; i < len; i++) {
		if(s1[i] != s2[i]) {
			if(diff1 == '0') {
				diff1 = s1[i];
				diff2 = s2[i];
			} else if(s1[i] != diff2 || s2[i] != diff1) {
				return false;
			} else if(swapped) {
				return false;
			} else {
				swapped = true;
			}
		} 
	}

	if(!swapped && diff1 != '0') return false;
	return true;
}

int main(){
	string s1 = "kanbab";
	string s2 = "bankba";

	if(areAlmostEqual(s1, s2)) {
		cout << 'T';
	}
}
