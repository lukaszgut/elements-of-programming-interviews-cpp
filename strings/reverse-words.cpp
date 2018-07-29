#include <iostream>
#include <string>

using namespace std;

string reverse_words(const string& str)
{
    string result;
    result.reserve(str.size());
    // begin and end pointers to cut the word out
    int32_t b = str.size() - 1, e = str.size();
    while (b >= 0) {
        while (str[b] != ' ' && b >= 0) --b;
        result += str.substr(b + 1, e - b);
        // add space if not in the beginning
        if (b > 0) {
            result += str[b];
        }
        e = b - 1;
        --b;
    }
    return result;
}

// the book solution is to reverse the whole string and then reverse each word

int main()
{
    cout<<"\""<<reverse_words("hello everyone this is a b c cool stuff!! ?!")<<"\""<<endl;
}
