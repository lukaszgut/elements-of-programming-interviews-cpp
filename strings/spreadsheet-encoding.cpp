#include <iostream>

using namespace std;

int to_number(string &&sscol)
{
    int result = 0;
    for (char c : sscol)
    {
        result *= 26;
        result += c - 'A' + 1;
    }
    return result;
}



int main()
{
    cout<<to_number("A")<<endl;
    cout<<to_number("D")<<endl;
    cout<<to_number("AA")<<endl;
    cout<<to_number("ZZ")<<endl;
}
