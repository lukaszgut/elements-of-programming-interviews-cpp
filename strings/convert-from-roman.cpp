#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


int deromanize(string number)
{
    static unordered_map<char, unsigned long long int> dict =
    {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    unsigned long long int value = 0;
    unsigned long long int last = 10000;
    for (auto c: number)
    {
        auto current = dict[c];
        if (last < current) {
            value -= 2 * last;
        }
        last = current;
        value += current;
    }
    return value;
}

int main()
{
    cout<<deromanize("MCMLXXXIV")<<endl;
    cout<<deromanize("MDCL")<<endl;
    cout<<deromanize("XXXXIIIII")<<endl;
}
