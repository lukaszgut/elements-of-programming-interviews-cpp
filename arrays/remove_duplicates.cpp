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

int main() {
    vector<int> a = {2,3,5,5,7,11,11,11,13};
    int new_size = remove_duplicates(a);
    cout<<"Vector: ";
    for (auto el: a) cout<<el<<" ";
    cout<<" has size: "<< new_size<<endl;
}
