#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define endl '\n'
template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n,k;
    cin >> n >> k;
    vi A(n);
    rep(i,0,n) cin >> A[i];
    sort(all(A));

    if (n == 1) {
        cout << k + A[0] << "\n";
        return 0;
    }
// 1 1 1 1 2

    ll ans = A[n/2];
    rep(i, n/2 + 1, n) {
        ll d = i - n/2;
        if (k >= d*(A[i] - A[i-1])) {
            k -= d*(A[i] - A[i-1]);
            ans += A[i] - A[i-1];
        } else {
            ans += k/d;
            k %= d;
            break;
        }
    }
    if (k != 0) {
        ans += k/(n-n/2);
    }
    cout << ans << "\n";
    return 0;
}
