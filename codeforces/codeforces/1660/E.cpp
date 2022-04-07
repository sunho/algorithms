#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define nl '\n'
template<class T> using vec = vector<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }
template<class N> N mod(N x, N d) { return ((x%d) + d) % d; }

void solve() {
    int n;
    cin >> n;
    vec<vec<int>> M(n, vec<int>(n));
    rep(i,0,n) {
        rep(j,0,n) {
            char c;
            cin >> c;

            M[i][j] = c-'0';
        }
    }
    
    int maxi = 0;
    rep(i,0,n) {
        int m = 0;
        rep(k,0,n) {
            if (M[(i+k)%n][(k)%n] == 1) {
                m++;
            }
        }
        maxi = max(maxi, m);
    }
    int cnt = 0;
    rep(i,0,n) {
        rep(j,0,n) {
            cnt += M[i][j];
        }
    }
    cout << cnt - maxi + (n-maxi) << nl;
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