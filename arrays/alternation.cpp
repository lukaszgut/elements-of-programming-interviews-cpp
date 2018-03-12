/**
 * Rearrange the array so b0 <= b1 >= b2 <= b3 >= b4 ...
 */

#include <iostream>
#include <vector>

using namespace std;


void rearrange(vector<int> * a_ptr) {
    auto &a = *a_ptr;
    for (int i = 0; i < a.size() - 1; ++i) {
      if ((!(i%2) && (a[i] > a[i+1])) || ((i%2) && (a[i] < a[i+1]))) {
          swap(a[i], a[i+1]);
      }
    }
}

int main() {
    vector<int> a{1,2,3,4,5,6,7,8,9,10,11,12};
    rearrange(&a);
    for (auto &aa: a) cout<<aa<<" "; cout<<endl;
}
