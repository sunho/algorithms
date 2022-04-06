#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll isqrt(ll N){
	ll sqrtN=sqrt(N)-1;
	while(sqrtN+1<=N/(sqrtN+1))sqrtN++;
	return sqrtN;
}

void solve() {
    ll x;
    cin >> x;
    ll xx = isqrt(isqrt(x));
    vector<ll> dp(xx+1);
    dp[1] = 1;
    for(ll i=2;i<=xx;i++) {
        for(ll j=1;j*j*j*j<=i;j++) {
            dp[i] += dp[j]*(isqrt(i)-j*j+1);
        }
    }
    ll ans = 0;
    for(ll i=1;i<=xx;i++) {
        ans += dp[i]*(isqrt(x) - i*i+1);
    }
    cout << ans << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
