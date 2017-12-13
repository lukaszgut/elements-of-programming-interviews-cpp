/** 
 * Compute parity of very large number of 64-bit words
 */

#include<iostream>
#include<unordered_map>

using namespace std;

// parity is associative, of course

// my first implementation O(n)
short parity(uint64_t word) {
	short par = 0;
	while (word) {
		par += (word & 0x1);
		par &= 0x1;
		// in book above reduces to par ^= word & 1;
		word >>= 1;
	}
	return par;
}

// Ok, this is cool, would never figure it out myself...
// From the book: erase lower bit with x&=(x-1)
// It has far less instructions
// Complexity is O(k) where k is number of set bits
short parity_with_erase_lower_bit_instruction(uint64_t word) {
	short par = 0;
	while (word) {
		par ^= 1;
		word &= (word - 1);
	}
	return par;
}

// use dynamic caching - my first implementation
short parity(uint64_t *words, uint64_t size) {
	auto bytes = reinterpret_cast<uint8_t*>(words);
	auto bytesLen = size * (sizeof(uint64_t)/sizeof(uint8_t));
	auto lookup = unordered_map<uint64_t, short>();
	short total_parity = 0;
	for (auto i = 0; i < bytesLen; ++i) {
		short local_parity;
		auto search = lookup.find(bytes[i]);
		if (search == lookup.end()) {
			lookup[bytes[i]] = parity(bytes[i]);
		}
		total_parity += lookup[bytes[i]];
		total_parity &= 0x1;
		// could be also total_parity = (total_parity + lookup[bytes[i]])%2;
	}
	return total_parity;
}


// Similarily to the book, caching 2^16 values
// Complexity is O(64/16) assuming constant time bit operations.
// if we precomile these:
constexpr const int lookup_size_bits = 16;
constexpr const int lookup_size = 65536;
constexpr const int lookup_mask = lookup_size -1;
short parities[lookup_size];
// then we can just use them in the parity method directly:
short parity_with_precompiled_lookup(uint64_t word) {
	return
		parities[word & lookup_mask] ^
		parities[(word>>lookup_size_bits) & lookup_mask] ^
		parities[(word>>(lookup_size_bits*2)) & lookup_mask] ^
		parities[(word>>(lookup_size_bits*3)) /*This IS NOT NECESSARY: & lookup_mask*/];
}

// This is an O(log n) algorithm using asoc property of parity
short parity_with_recursive_xor(uint64_t word) {
	word ^= word >> 32;
	word ^= word >> 16;
	word ^= word >>  8;
	word ^= word >>  4;
	word ^= word >>  2;
	word ^= word >>  1;
	return word & 0x1;
}

// Combine recursive and lookup would be like:
short parity_xor_and_lookup(uint64_t word) {
	word ^= word >> 32;
	word ^= word >> 16;
	return parities[word & lookup_mask];
}

/** 
 * Next three variants should be all O(1):
 */

// Propagate rightmost bit that is 1 all the way to the right
// Not sure if nice, because uses decrement not stated in list of allowed ops.
uint8_t propagate_rightmost_set_bit(uint8_t word) {
	return word | (word -1);
}

// I assume that numIsPow2 is actually a power of two
// Again, not sure however if can use -1, as it was not mentioned.
// If instead of numIsPow2 a 'power' would be known' 
// then one can use shift left and right approach.
uint64_t modPowerOfTwo(uint64_t left, uint64_t numIsPow2) {
	return left & (numIsPow2 - 1);
}

// Use trick to reset lowest bit to zero
// Power of two has only one so it will zero it.
bool isPowerOf2(uint64_t word) {
	return (word & (word -1)) == 0;
}

int main() {
	cout<<"Parity of 0: "<<parity(0)<<endl;
	cout<<"Parity of 1: "<<parity(1)<<endl;
	uint64_t array[] = {1244, 1232, 6546, 9879879, 22222};
	cout<<"Parity is: "<<parity(array, 5)<<endl;
	
}

