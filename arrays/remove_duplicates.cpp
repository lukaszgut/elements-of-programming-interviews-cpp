/**
 * Remove duplicates from a _sorted_ array.
 */

#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int> & a) {
    if (a.empty()) {
        return 0;
    }
    int write_pos = 0;
    for (int read_pos = 0; read_pos < a.size(); ++read_pos) {
        if (a[read_pos] != a[write_pos]) {
            a[++write_pos] = a[read_pos];
        }
    }
    // just cut the rest
    a.resize(write_pos + 1);
    // return new size
    return write_pos + 1;
}

// variant: remove occurences of key
template<typename obj>
int remove_occurences(vector<obj> & a, obj key) {
    int write_pos = 0;
    for (int read_pos = 0; read_pos < a.size(); ++read_pos) {
        if (a[read_pos] != key) {
            // don't overwrite the same stuff
            if(read_pos != write_pos) {
                a[write_pos++] = a[read_pos];
            } else {
                ++write_pos;
            }
        }
    }
    a.resize(write_pos);
    for (auto el: a) cout<<el<<" ";
    cout<<endl;
    return write_pos;
}

// variant: if x appears m in original, update, so it occurs min(2,m) afterwards
// array is _sorted_, so it should be the same on position i and i+m-1 but not i+m
void leave_at_max_two_occurences(vector<int> & a, int m) {
    // if it's zero or one or two do nothing
    if (m <= 2) {
      return;
    }
    int shift = 2; // min(2, m);
    int write_pos = 0;

    for (int read_pos = 0; read_pos < a.size();) {
        // we have m occurences
        if ((a[read_pos] == a[read_pos + m - 1]) &&
            (a[read_pos] != a[read_pos + m])) {
                a[write_pos++] = a[read_pos];
                a[write_pos++] = a[read_pos];
                read_pos += m;
        // it's less that m occurences of x
        // just rewrite an element and jump to next
        } else if (a[read_pos] != a[read_pos + m - 1]) {
            a[write_pos++] = a[read_pos++];
        // there is more than n of these elements
        } else if (a[read_pos] == a[read_pos + m]) {
            int abundant = a[read_pos];
            while(a[read_pos] == abundant) {
                a[write_pos++] = abundant;
                ++read_pos;
            }
        }
    }
    a.resize(write_pos);
}

int main() {
    vector<int> a = {2,3,5,5,7,11,11,11,13};
    int new_size = remove_duplicates(a);
    cout<<"Vector: ";
    for (auto el: a) cout<<el<<" ";
    cout<<" has size: "<< new_size<<endl;
    vector<int> b = {2,3,5,5,7,11,11,11,13};
    int b_size = remove_occurences(b, 11);
    cout<<"After removing, size: "<<b_size<<endl;
    cout<<"**************************************"<<endl;
    vector<int> c = {1,1,1,1,2,2,2,2,3,3,4,4,4,4,5,5,5,7,7,7,7,7,8};
    leave_at_max_two_occurences(c, 4);
    for (auto el: c) cout<<el<<" "; cout<<endl;

}
