/**
 * Enumerate all the primes to n.
 *
 * Erastotenes sieve
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> generate_primes(int n) {
    vector<int> primes;
    deque<int> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.emplace_back(p);
            for (long i = p*p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

// Further optimization - space ( remove %2 and %3, start inner loop from p*p (done already above)


int main() {
    cout<<"Primes:\n";
    int counter = 1;
    for (auto a : generate_primes(10000)) cout<<a<<"\t"<<(((counter++%10) == 0) ? "\n" : "");
    cout<<endl;
}

