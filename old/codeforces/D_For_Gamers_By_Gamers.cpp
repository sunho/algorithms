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
    
    int n, C;
    cin >> n >> C;

    map<int, ll> U;
    rep(i, 0, n) {
        int c;
        ll d, h;
        cin >> c >> d >> h;
        U[c] = max(d*h, U[c]);
    }

    int m;
    cin >> m;
    vector<ll> M(m);
    rep(i,0, m) {
        ll D, H;
        cin >> D >> H;
        M[i] = D*H;
    }

    vector<ll> MC(C+1);
    trav(x, U) {
        auto [c, dh] = x;
        rep(i, 1, C/c+ 1) {
            ckmax(MC[c*i], dh*(ll)i);
        }
    }
    rep(i,1,C+1) {
        MC[i] = max(MC[i], MC[i-1]);
    }
    rep(i,0,m) {
        int l = -1, r = C+1;
        while (r-l > 1){
            int mid = (l+r)/2;
            if (MC[mid] > M[i]) r = mid;
            else l = mid;
        }
        if (r == C+1) cout << -1 << " ";
        else cout << r << " ";
    }


    return 0;
}
