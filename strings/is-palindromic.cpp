/**
 * Check if string is a palindrome.
 */


#include <iostream>
#include <string>

using namespace std;

bool is_palindromic(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string ana = "ana", banana = "banana";
    cout<<ana<<": "<<is_palindromic(ana)<<endl;
    cout<<banana<<": "<<is_palindromic(banana)<<endl;
}
