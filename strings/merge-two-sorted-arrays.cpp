#include <iostream>

using namespace std;

void merge(int a[], int asz, int b[], int bsz)
{
    int apos = asz - 1, bpos = bsz - 1;
    for (int i = asz + bsz - 1; (i > -1) && (bpos > -1); --i)
    {
        cout<<"Comparing "<<a[apos]<<" and "<<b[bpos]<<endl;
        if (a[apos] < b[bpos] || apos == -1)
        {
            a[i] = b[bpos--];
        } else
        {
            a[i] = a[apos--];
        }
    }
}

int main()
{
    int one[50] {1,2,3,4,5,6,7,8,9,11,13,15,17};
    int two[]   {0,1,2,3,4,5,6,7,8,9, 10,12,14,17,18};
    for (int i: one) cout<<i<<" "; cout<<endl;
    for (int i: two) cout<<i<<" "; cout<<endl;
    merge(one, 13, two, 15);
    cout<<"Result: ";
    for (int i: one) cout<<i<<" "; cout<<endl;
}
