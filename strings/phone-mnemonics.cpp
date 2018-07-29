#include <iostream>
#include <string>
#include <vector>

using namespace std;

void helper(const string& number, int32_t digit, vector<string> *result, string *single_realisation)
{
    static vector<string> all_mnemonics {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    if (digit == number.size())
    {
        result->emplace_back(*single_realisation);
        return;
    }
    string mnemonics = all_mnemonics[number[digit] - '0'];

    for (auto mnemonic: mnemonics)
    {
        (*single_realisation)[digit] = mnemonic;
        helper(number, digit + 1, result, single_realisation);
    }
}

vector<string> generate_mnemonics(const string& number)
{
    vector<string> result;
    string single_realisation(number.size(), 0); //*< reserve space and initialize with 0
    helper(number, 0, &result, &single_realisation);
    return result;
}

int main()
{
    for (auto s: generate_mnemonics("86852"))
    {
        cout<<s<<endl;
    }
}



