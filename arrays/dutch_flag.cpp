/**
 * Dutch national flag problem.
 */

#include <iostream>
#include <vector>

using namespace std;

typedef enum {r,g,b} color;

void dutch_flag(int pivot_idx, vector<color>* a_ptr) {
	vector<color> &a = *a_ptr;
	color pivot = a[pivot_idx];
	int smaller = 0, bigger = a.size() - 1, equal = 0;
	bool changed;
	while(equal < bigger) {
		if(a[equal] < pivot) {
			swap(a[equal++], a[smaller++]);
		} else if(a[equal] == pivot) {
			++equal;
		} else {
			swap(a[equal], a[bigger--]);
		}
	}	
}


int main() {
	vector<color> a = {r,g,g,b,g,r,g,b,r};
	dutch_flag(2,&a);
	for(auto i: a) cout<<i<<" ";
	cout<<endl;
}
