#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool is_palindromic(const string& str)
{
    uint32_t a = 0, b = str.size();
    while (a < b)
    {
        if (0 == isalnum(str[a]))
        {
            ++a;
            continue;
        }
        if (0 == isalnum(str[b]))
        {
            --b;
            continue;
        }
        if (toupper(str[a]) != toupper(str[b]))
        {
            return false;
        }
        ++a;
        --b;
    }
    return true;
}

string print_result(const string& str)
{
    return ("\"" + str + "\"" + (is_palindromic(str) ? " is palindromic" : " is NOT palindromic") + "\n");
}

int main()
{
    cout<<print_result("A man, a plan, a canal, Panama");
    cout<<print_result("Able was I, ere I saw Elba!");
    cout<<print_result("Ray a Ray");
}
