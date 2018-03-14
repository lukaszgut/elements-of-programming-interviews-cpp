/**
 * Interconvert strings and integers.
 */

#include <iostream>
#include <string>

using namespace std;

string int_to_string(int i) {
    bool negative = (i<0);
    string s = "";
    while (i!=0) {
          s += '0' + abs(i%10);
          i/=10;
    }
    if (negative) s+= "-";
    return {s.rbegin(), s.rend()};
}

int string_to_int(const string && s) {
    if (s.empty()) return 0;
    bool negative = (s[0] == '-');
    int result = 0;
    for (int i = (negative ? 1 : 0); i < s.size(); ++i) {
        result = result*10 + (s[i] - '0');
    }
    return negative ? -result : result;
}


int main() {
    cout<<int_to_string(-12658)<<" "<<string_to_int("-3468")<<endl;
}
