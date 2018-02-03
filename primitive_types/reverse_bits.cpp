/**
 * Reverse bits of 64 bit integer.
 */

#include <iostream>

using namespace std;

// swap bits function copied from swap_bits.cpp
// is used to brute-force precompute values
unsigned short swap_bits(unsigned short word, int x, int y) {
        if (((word >> x)&1) != ((word >> y)&1)) {
                unsigned short bit_mask = (1 << x) | (1 << y);
                word ^= bit_mask;
        }
        return word;
}

// 64k 16bit precomputed values
unsigned short * precomputed_values = new unsigned short[1<<16];

// precompute values:
void precompute_values() {
	for(unsigned int i = 0; i < 1<<16; ++i) {
		precomputed_values[i] = i;
		for (unsigned int bit = 0; bit < 8; ++bit) {
			precomputed_values[i] = swap_bits(precomputed_values[i], bit, 15-bit);
		}
		cout<<hex<<"In: "<<i<<" out: "<<precomputed_values[i]<<endl;
	}
}

// and now the real problem
// reverse 64-bit number
unsigned long reverse_bits(unsigned long word) {
	return static_cast<unsigned long>(precomputed_values[word >> 48]) |
		static_cast<unsigned long>(precomputed_values[(word >> 32)&0xFFFF])<<16 |
		static_cast<unsigned long>(precomputed_values[(word >> 16)&0xFFFF])<<32 |
		static_cast<unsigned long>(precomputed_values[word&0xFFFF])<<48;
}

// test stuff
int main() {
	precompute_values();
	unsigned long num = 0xF0F00F000F0000FF;
	cout<<"Reverse of "<<hex<<num<<" is "<<reverse_bits(num)<<endl;
}
