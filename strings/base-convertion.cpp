#include <iostream>

using namespace std;

int64_t value(string &number, int from_base)
{
    int64_t result = 0;
    bool negative = number[0] == '-';
    for (int i = negative ? 1 : 0; i < number.size(); ++i)
    {
        result *= from_base;
        result += (isdigit(number[i]) ? number[i] - '0' : number[i] - 'A' + 10);
    }
    return result;
}

string express_in_base(int64_t number, int to_base)
{
    if (number == 0) return "";
    else return
        express_in_base(number/to_base, to_base) + static_cast<char>((number % to_base) < 10 ? '0' + (number % to_base) : 'A' + (number % to_base) - 10);
}

string convert(string &&number, int from_base, int to_base)
{
    return express_in_base(value(number, from_base), to_base);
}

int main()
{
    cout<<convert("FF", 16, 10)<<endl;
}
