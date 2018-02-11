/**
 * Increment arbitrary precision integer stored as array of digits.
 */

#include <iostream>
#include <vector>

using namespace std;



vector<int> plus_one(vector<int> a) {
	++a.back();
	for(int i = a.size() -1; i > 0 && a[i] == 10; --i) {
		a[i] = 0;
		++a[i-1];
	}
	if (a[0] == 10) {
		a[0] = 1;
		a.emplace_back(0);// since any way its 10000000..... we can just put new zero at the end
	}
	return a;
}

int main() {
	vector<int> a = {9,9,9,9,9};
	vector<int> b = plus_one(a);
	for(auto i: b) cout<<i<<" ";
	cout<<endl;
}


