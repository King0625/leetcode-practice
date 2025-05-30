#include <iostream>

using namespace std;

int gcd(int a, int b){
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

string gcdOfStrings(string str1, string str2) {
	if(str1 + str2 != str2 + str1) return "";

	int lenGcd = gcd(str1.size(), str2.size());

	return str1.substr(0, lenGcd);
}



int main(){
	string str1 = "ABCABC";
	string str2 = "ABC";

	string result = gcdOfStrings(str1, str2);
	cout << result << "\n";
	return 0;
}
