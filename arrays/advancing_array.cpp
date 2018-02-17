/**
 * Advance through array - check possibility
 */

 #include <iostream>
 #include <vector>

using namespace std;

bool can_reach_end(const vector<int> & a) {
    int last_index = a.size() - 1;
    int furthest = 0;
    for (int i = 0; (i <= furthest) && (furthest < last_index); ++i) {
        furthest = max(furthest, a[i] + i);
    }
    return (furthest >= last_index);
}

/**
 * Calculate minimum of steps needed to go through the array.
 */
int min_steps(const vector<int> & a) {
    int last_index = a.size() - 1;
    // we will keep the minimum steps needed to reach to each place
    // by default 'uninitialized' state == more than length
    auto steps = vector<int>(a.size(), a.size() + 1);
    // except of first position that requires 0 steps to go
    steps[0] = 0;
    // going through all the array points
    for (int i = 0; i < last_index; ++i) {
        // update all possible states
        for (int j = 1; (j <= a[i]) && ((i+j) <= last_index); ++j) {
            if (steps[i+j] > (steps[i] + 1)) {
                steps[i+j] = steps[i] + 1;
            }
        }
    }
    // for(auto i: steps) cout<<i<<" ";
    // cout<<endl;
    int needed = steps[last_index];
    if (needed > a.size()) needed = -1;
    return needed;
}

int main() {
    vector<int> a = {1,1,0,1,3,0,0,1,2,0,1};
    cout<<"Can reach?: "<<(can_reach_end(a) ? "yes" : "no")<<endl;
    cout<<"We need "<<min_steps(a)<<" to pass through the array"<<endl;
}
