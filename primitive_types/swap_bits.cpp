/**
 * Swap two selected bits from 64bit word.
 */

#include <iostream>

using namespace std;

long swap_bits(long word, int x, int y) {
	if (((word >> x)&1) != ((word >> y)&1)) {
		unsigned long bit_mask = (1L << x) | (1L << y);
		word ^= bit_mask;
	}
	return word;
}


int main() {
	long word = 6;
	int x = 1, y = 4; // move 1 to position 4 => 4 + 2 -> 16 + 4
	cout<<swap_bits(word, x, y)<<endl;
}


