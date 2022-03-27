#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
// a, b, c, d, a/x, a/x, a/x/x
// if q / x % x == 0 sum += q / x
// if it could reach d
// only if a % x == 0 ...., process end 
// end = a/x, b/x, c/x, d/x, 
// += a/x*x and add a/x/x to back
// a/x % x == 0 sum += a/x/x
// 
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, x;
        cin >> n >> x;
        ll sum = 0;
        queue<ll> q;
        queue<ll> val;
        bool shouldend = false;
        while (n--) {
            ll a;
            cin >> a;
            sum += a;
            if (a % x == 0) {
                if (!shouldend) {
                    q.push(a/x);
                    val.push(a);
                }
            } else {
                shouldend = true;
            }
        }
        while(!q.empty()) {
            ll a = q.front();
            q.pop();
            ll v = val.front();
            val.pop();
            sum += v;
            if (a % x == 0) {
                if (!shouldend) {
                    q.push(a/x);
                    val.push(v);
                }
            } else {
                shouldend = true;
            }
        }
        cout << sum << endl;
    }
    return 0;
}