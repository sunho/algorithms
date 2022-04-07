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
    int n,m,w;
    cin >> n >> m >> w;
    vector<ll> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    auto check = [&](int d) {
        vector<ll> R(n);
        ll upd = 0;
        vector<ll> lazy(n+1);
        int days = m;
        for(int i=0;i<n;i++) {
            R[i] = A[i] - d;
        }
        for(int i=0;i<n;i++) {
            upd += lazy[i];
            R[i] += upd;
            if (R[i] < 0) {
                int c = -R[i];
                lazy[min(n,i+1)] += c;
                lazy[min(n,i+w)] -= c;
                if (c > days) {
                    return false;
                }
                days -= c;
            }
        }
        return true;
    };
    int l = 0, r = 1e9+m+20;
    while (r-l > 1) {
        int mid = (l+r)/2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
