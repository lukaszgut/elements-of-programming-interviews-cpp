#include <iostream>

using namespace std;

// assumming size == current size
void replace_and_remove(char s[], size_t size)
{
    auto write{0}, read{0};
    int a_count{0}, b_count{0};

    for (int pos = 0; pos < size; ++pos)
    {
        if (s[pos] == 'a') {
            ++a_count;
        }

        if (s[pos] != 'b') {
            s[write] = s[read];
            ++write;
        }
        ++read;
    }
    // add extra shift for each a
    read = write;
    write = write + a_count;
    while (write > read) {
        if (s[read] == 'a') {
            s[write--] = 'd';
            s[write--] = 'd';
            --read;

        } else {
            s[write--] = s[read--];
        }
    }
}


int main()
{
    char text[] = "ana good bad no a more a or some bbb to be                               ";
    replace_and_remove(text, sizeof(text));
    cout<<text<<endl;
    char nasty[] = "anabbabba";
    replace_and_remove(nasty, sizeof(nasty));
    cout<<nasty<<endl;
}
