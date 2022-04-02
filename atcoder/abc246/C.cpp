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
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    sort(all(A));
    for(int i=n-1;i>=0;i--) {
        ll c = (A[i] / x);
        A[i] -= min(c,k)*x;
        k-=min(c,k);
    }
    sort(all(A));
    if (k!=0) {
        for(int i=n-1;i>=0;i--) {
            if (k > 0) {
                A[i] = 0;
                k--;
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<n;i++) sum += A[i];
    cout << sum << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
