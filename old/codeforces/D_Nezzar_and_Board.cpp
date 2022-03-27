#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>
using namespace std;
// 2x - y
// x + (x-y)
// a b
// add or subract diff
// a + (a - (a - (a-b))
// a + (a-b)
// x + (x-y) - y
// 2x - 2y
// we can always add or subtract by lin comb of all integers
// z = x - (x - y)
// z + (x-z) =
// z + (x-y)
// add by multiples of (x-y)'s
// k = o + a *(x-y) + b*(z-y) + c*(x-z)
// k-x or y or ...
// is lin comb of x-y, z-y, x-z, ..
// iff k-x is multiple of gcd
// (gcd(x-a_1, x-a_2, x-a_3))
// gcd(gcd(x-a_1, x-a_2), x-a_3)
// gcd(gcd((x-a_1)-(x-a_2), x-a_2),x-a_3)
// gcd(a_2-a_1, a_3-a_2, x-a_3)
// gcd(a_1-a_2, a_2-a_3, )

using ll = long long;
#define endl '\n'
#define N 200000
ll nums[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll gg = 0;
        set<ll> queue;
        for(int i=0; i< n; ++i) {
            ll x;
            cin >> x;
            if (i!=0) {
                ll z = abs(x-nums[i-1]);
                if (gg == 0) {
                    gg = z;
                }  else {
                    gg = gcd(z, gg);
                }
            }
            nums[i] = x;
        }
        bool ok = false;
        for (int i = 0; i<n; ++i) {
            if ((k-nums[i]) % gg == 0) {
                ok = true;
            }
        }
        if (ok) {
            cout <<"YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}