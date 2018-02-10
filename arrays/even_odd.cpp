/**
 * Sort numbers the way even are first and odd are last.
 */

#include <iostream>
#include <vector>

using namespace std;


void even_odd(vector<int>* A_ptr) {
	vector<int>& A = *A_ptr;
	int next_even = 0, next_odd = A.size() - 1;
	while (next_even < next_odd) {
		if (A[next_even] % 2 == 0) {
			++next_even;
		}
		else {
			std::swap(A[next_even], A[next_odd--]);
		}
	}
}

int main() {
	vector<int> A = {1,2,3,4,5,6,7,8,9,0};
	even_odd(&A);
	for (auto a: A) cout<<a<<" ";
	cout<<endl;
}
