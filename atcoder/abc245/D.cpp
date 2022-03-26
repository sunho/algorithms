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
    
    int n,m;
    cin >> n >> m;
    vector<ll> A(n+1);
    vector<ll> C(n+m+1);
    rep(i,0,n+1) {
        cin >> A[i];        
    }
    rep(i,0,n+m+1) {
        cin >> C[i];     
    }
    vector<ll> B(m+1);
    for (int i = m; i >= 0; i--) {
        if (C[i+n] == 0) continue;
        ll coef = C[i+n] / A[n];
        rep(j, 0, n+1) {
            C[i+j] -= coef * A[j];
        }
        B[i] = coef;
    }
    trav(x, B) cout << x << " ";

    return 0;
}
