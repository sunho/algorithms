#include <iostream>
#include <algorithm>

using namespace std;


// (a + b) /x = a/x + b/x
// a % x != 0 => a/x + 1
// else => a/x
// mimimum make a % x = 0 as much as possible 
//  + sum of all / x would be minimum if sum of all % x == 0
//  or make every item % x = 0
// 
// maximum
// 
// a, b, c, d
// 0  1  0  1 
// if a % x !=0 (a + b) % x
// ( a mod x + b mod x ) mod x = 0
// 0 <= a mod x < x
// 2*x -2 % x
// only if a mod x + b mod x = x or 0
// is 0 iff a mod x = 0 b mod x = 0
// a mod x + b mod x = x
// a mod x b mod x c mod x d mod x
// if a mod x + b mod x = 0 we can't do further
// another thing: we can't increase number of a % x != 0
// since a mod x (1) + b mod x (0) = (1) # of 1 is same
// 0 + 0 = 0 # of 1 is same


// max = original
// min
// a mod x + b mod x + c mod x != 0
// we can just remove all mod 0's
// a mod x + b mod x = 0 c mod x != 0
// sum of all != 0
// a mod x + b mod x = 0 c mod x + d mod x = 0
// sum of all = 0
// if some combination of a mod x + c mod x is 0
// it will not contribute to modular of sum of all
// other words: (a mod x + b mod x + c mod x) => (a mod x + 0)
// summing up all is mimimum
using ll = long long;
ll roundup(ll a, ll x) {
    if (a % x == 0) return a/x;
    return a/x + 1;
}
int main() {
    int t;
    cin >> t;

    while(t--) {
        ll sum = 0;
        ll bsum = 0;
        ll n, x;
        cin >> n >> x;
        while(n--){
            ll a;
            cin >> a;
            sum += a ;
            bsum += roundup(a, x);
        }
        cout << roundup(sum,x) << " " << bsum << endl;
    }
    return 0;
}