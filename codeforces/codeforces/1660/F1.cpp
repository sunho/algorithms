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
    string s;
    cin >> s;
    int cnt = 0;
    vec<int> pf(n+1);
    rep(i,0,n) {
        pf[i+1] = pf[i] + (s[i] == '+');
    }
    bool last_zero = false;
    vec<int> pf2(n+1);
    rep(i,0,n) {
        if (s[i] == '-' && last_zero) {
            pf2[i+1] = pf2[i] + 1;
        } else {
            if (s[i] == '-') last_zero=true;
            else last_zero=false;
            pf2[i+1] = pf2[i];
        }
    }
    rep(i,0,s.size()) {
        rep(j,i,s.size()) {
            int one = pf[j+1] - pf[i];
            int zero = (j-i+1) - one;
            int zz = pf2[j+1]-pf2[i];
            int z = (zero - one);
            if (z % 3 != 0 || z < 0) continue;
            z/=3;
            if (z > zz) continue;
            cnt++;
        }
    }
    cout << cnt << nl;
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
