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
    int m = 2*n + 1;
    rep(i,0,m) {
        rep(j,0,m) {
            int d = abs(m/2 - i) + abs(m/2 - j);
            if (d <= n) {
                cout << n - d; 
                if (n-d != 0 || j < n) cout << " ";
            } else {
                if (j < n) {
                    cout << "  ";
                }
            }
        }
        cout << nl;
    }
}
    
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    solve();
    
    return 0;
}