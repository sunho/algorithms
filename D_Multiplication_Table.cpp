#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    auto count = [&](ll x) {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++) {
            cnt += min((x)/i,(ll)m);
        }
        return cnt;
    };
    //k--;
    ll l = 0, r = n*m+1;
    while (r-l > 1) {
        ll mid = (l+r)/2;
        if (count(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
