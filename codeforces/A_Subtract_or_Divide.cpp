#include <iostream>
#include <algorithm>

using namespace std;

// divide n by one of its proper divisors
// subtract 1 from n if n is grator than
// if a mod 2 = 0, a / (a/2) = 2 (+1) 2 - 1 (+2) within 2
// if a mod 2 = 1, a / (a/(smallest prime)) >= 3 (+1)
// 3 - 1 -1 (+2)
// is same as -1 first and do even op (+3)
// 
// base case: if a == 2: a--
// if even a = 2
// if odd a--
// if 1: end
// 
// 

using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int cost = 0;
        while (n != 1) {
            if (n == 2) {
                --n;
            } else if (n % 2 == 1) {
                --n;
            } else {
                n = 2;
            }

            ++cost;
        }
        cout << cost << endl;
    }
    return 0;
}