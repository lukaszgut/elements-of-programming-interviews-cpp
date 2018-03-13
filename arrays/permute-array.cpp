/**
 * Permute the elements of an array.
 */

#include <iostream>
#include <vector>

using namespace std;

// uses only constant additional storage explicitly 
// and o(n) implicit bits to mark permutations done.
void apply(vector<int> * permutation_ptr, vector<int> * array_ptr) {
    auto & permutation = *permutation_ptr;
    auto & array = *array_ptr;
    for (int i = 0; i < array.size(); ++i) {
        cout<<i<<endl;
        int next = i;
        while (permutation[next] >= 0) {
            cout<<"\tcheck"<<endl;
            swap(array[i], array[permutation[next]]);
            int temp = permutation[next];
            permutation[next] -= permutation.size();
            next = temp;
        }
    }
}

int main() {
    vector<int> p = {0,2,4,3,1};
    vector<int> a = {1,2,3,4,5};
    apply(&p, &a);
    for (auto e : a) cout<<e<<" "; cout<<endl;
}
