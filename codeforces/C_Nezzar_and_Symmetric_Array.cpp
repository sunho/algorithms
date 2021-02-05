#include <iostream>
#include <algorithm>

using namespace std;
// a-b a+b, 2a 1
// a-b 2b, a+b 2 
// a+b 2b, a-b 3
// 2a,a+b, a-b 4
// | a - c_i | | -c_i - a |
// | -a - c_i | | -c_i +a|
// sym => diff same

// diff same => either minus or same value
// 
//   t1    t2     s2  s1
// a    b      c
// a: t1 + t2 + s2 + s1 (2a + 2a + 2a) 6a
// b: t1 + t3 + s1 + s3 (2a + 2b + 2b) 2a + 4b
// c: t2 + t3 + s2 + s3 (2a + 2b + 2c) 2a + 2b + 2c
//
// d_a = d_b iff a = b
// 
// d_a = d_ab + s_ab + d_ac + s_ac + 2a
// = (a+b) + (a-b) + (a+c) + (a-c) + 2a
// 2a + 2a + 2a
// 
// a > b > c > d > ...
// d_a = 2*(n-1) *a + 2a
// d_b = 2*(n-2) *b + 2a + 2b
#define N 200000
#define endl '\n'
using ll = long long;
ll diff[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=0; i<2*n; ++i) {
            ll d;
            cin >> d;
            diff[i] = d;
        }
        bool ok = true;
        ll factor = 0;
        sort(diff, diff + 2*n, greater<ll>());
        for (int i=0; i<n; ++i) {
            int k = ((n-i)*2);
            if ((diff[2*i+1] != diff[2*i]) 
                ||(i!=0 && diff[2*i] == diff[2*(i-1)])
                ||(diff[2*i] <= factor)
                ||((diff[2*i] - factor) % k != 0))  {
                ok = false;
                break;
            }
            factor += (diff[2*i] - factor)/k*2;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}