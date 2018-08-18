#include <string>
#include <vector>
#include <iostream>

using namespace std;

string make_next(string &s)
{
    string result;
    for (uint i = 0; i < s.size(); ++i)
    {
        int count = 1;
        while (i+1 < s.size() && s[i] == s[i+1])
        {
            ++count; ++i;
        }
        result += to_string(count) + s[i];
    }
    return result;
}

string look_and_say(uint position)
{
    string result = "1";
    for (uint i = 1; i < position; ++i)
    {
        result = make_next(result);
    }
    return result;
}

int main()
{
    for (uint i = 1; i < 20; ++i)
    {
        cout<<"The "<<i<<"st/nd/rd/th number is: "<<look_and_say(i)<<endl;
    }
}
