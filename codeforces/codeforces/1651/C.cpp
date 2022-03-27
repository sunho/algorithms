#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        ll v0 = 1e9, v1 = 1e9, v2 = 1e9, v3 = 1e9;
        for(int i=0;i<n;i++) {
            v0 = min(abs(a[0]-b[i]), v0);
            v1 = min(abs(a[n-1]-b[i]), v1);
            v2 = min(abs(a[i]-b[0]), v2);
            v3 = min(abs(a[i]-b[n-1]), v3);
        }
        ll ans = abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]);
        ans = min(ans, abs(a[0] - b[n-1]) + abs(a[n-1] - b[0]));
        ans = min(ans, v0 + v1 + v2 + v3);
        ans = min(ans, abs(a[n-1] - b[0]) + v0 + v3);
        ans = min(ans, abs(a[0] - b[n-1]) + v1 + v2);
        ans = min(ans, abs(a[0] - b[0]) + v1 + v3);
        ans = min(ans, abs(a[n-1] - b[n-1]) + v0 + v2);

        cout << ans << '\n';
    }

    return 0;
}