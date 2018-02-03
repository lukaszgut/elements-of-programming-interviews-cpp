/**
 * Compute x*y without any arithmetic operators.
 * Only >>, <<, |, &, ~, ^, = can be used.
 */

#include <iostream>

using namespace std;


unsigned int add(unsigned int a, unsigned int b) {
	// result
	unsigned int sum = 0;

	// make tmp copies to bitshift them right to check how much we need to calculate (while condition)
	unsigned int tmp_a = a, tmp_b = b;

	// carry in hold extra bit to carry to next position
	unsigned int carry_in = 0;

	// mask pointing to current bit of operation 
	unsigned int k = 1;

	while(tmp_a || tmp_b) {
		// k-th bit of word a and word b:
		// !!! This is taken from original word
		unsigned int bit_k_a = a & k;
		unsigned int bit_k_b = b & k;
		// calculate carry-out:
		unsigned int carry_out = 
			(bit_k_a & bit_k_b) | // both bits are 1
			(bit_k_a & carry_in) | // bit a is 1 and carry_in is 1
			(bit_k_b & carry_in); // bit b is 1 and carry_in is 1
		// sum is EXOR of a,b and carry_in:
		sum |= (bit_k_a ^ bit_k_b ^ carry_in);
		// new carry_in is current carry_out shifted to next position
		carry_in = carry_out << 1;
		// move to next bit position
		k <<= 1;
		// right-shift a and b copies to update while condition
		tmp_a >>= 1;
		tmp_b >>= 1;
	}
	return sum | carry_in;
}


unsigned int multiply_first_try(unsigned int a, unsigned int b) {
	unsigned int sum = 0;
	unsigned int a_powered = a;
	unsigned int b_shifted = b;

	while(b_shifted) {
		if(b_shifted&1) {
			sum = add(sum, a_powered);
		}
		a_powered = add(a_powered, a_powered);
		b_shifted >>= 1;
	}
	return sum;
}

unsigned int multiply(unsigned int a, unsigned int b) {
	unsigned int sum = 0;
	while(a) {
		if (a&1) {
			sum = add(sum, b);
		}
		a >>= 1;
		b <<= 1;
	}
}





int main() {
	unsigned int a = 25, b = 122;
	cout<<"Sum of "<<a<<" and "<<b<<" is "<<add(a, b)<<endl;
	cout<<"Mutliplied: "<<multiply_first_try(a, b)<<endl;
	cout<<"Or multiplied: "<<multiply(a, b)<<endl;
}

