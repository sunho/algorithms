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
    vi B(n);
    rep(i,0,n)cin>>A[i];
    rep(i,0,n)cin>>B[i];

    if (n == 1) {
        cout << "Yes" << "\n";
        return 0;
    }

    const int inf = 1e9 + 10;

    vector<vi> dp(n, vi(2, inf));
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    rep(i, 0, n-1) {
        rep(j,0,2) {
            int c = j == 0 ? A[i] : B[i];
            ckmin(dp[i+1][0], max(abs(A[i+1]-c), dp[i][j]));
            ckmin(dp[i+1][1], max(abs(B[i+1]-c), dp[i][j]));
        }
    }

    if (min(dp[n-1][0], dp[n-1][1]) <= k) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
