#include<iostream>

using namespace std;

unsigned char count_bits_set_to_one(int integer) {
	unsigned char counter = 0;
	while(integer) {
		if (integer & 1) {
			++counter;
		}
		integer >>= 1;
	}
	return counter;
}

int main() {
	int test = 31;
	cout<<"Number of non-zero bits is: "<<(int)count_bits_set_to_one(test)<<endl;
}
