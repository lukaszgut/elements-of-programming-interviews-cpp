/**
 * Return the closest int with the same amount of bits set to 1.
 */

#include <iostream>
#include <stdexcept>

using namespace std;

unsigned long closest_with_same_weight(unsigned long num) {
	const static int size = 64;
	for(int i = 0; i < size - 1; ++i) {
		if( ((num>>i)&1) != ((num>>(i+1))&1) ) {
			num^= (1<<i) | (1<<(i+1));
			return num;
		}
	}
	throw invalid_argument("All bits 0 or all bits 1");
}

int main() {
	unsigned long x = 21;
	cout<<"Closest to: "<<x<<" is: "<<closest_with_same_weight(x)<<endl;
}
