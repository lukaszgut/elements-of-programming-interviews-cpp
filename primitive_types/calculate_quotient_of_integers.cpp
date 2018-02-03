/**
 * Calculate a quotient of two integers x and y.
 */

#include <iostream>

using namespace std;

int divide(int x, int y) {
	int result = 0;
	int power = 32;
	unsigned long long y_power = static_cast<unsigned long long>(y) << power;
	while (x >= y) {
		while (y_power > x) {
			y_power >>= 1;
			--power;
		}
		result += (1<<power);
		x -= y_power;
	}
	return result;
}


int main() {
	int x = 520, y = 7;
	cout<<x<<" divided by "<<y<<" is: "<<divide(x, y)<<endl;
}
