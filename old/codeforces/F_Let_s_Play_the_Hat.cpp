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

// (n/m+1)*a + (n/m)*(m-a) = n
// (n/m+1)*a + (n/m)*(-a) = n-(n/m)*m
// a = n-(n/m)*m
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n,m,k;
        cin >> n >> m >> k;
        if (n % m == 0) {
            int t = n/m;
            rep(i, 0, k) {
                rep(j, 0, m) {
                    cout << t << ' ';
                    rep(z, 0, t) {
                        cout << z + 1 + t*j << ' ';
                    }
                    cout << '\n';
                }
            }
        } else {
            int t0 = n/m;
            int t1 = n/m + 1;
            int T1 = n-(n/m)*m;
            int T0 = m - T1;
            int of = 0;
            rep(i, 0, k) {
                rep(j, 0, T1) {
                    cout << t1 << ' ';
                    rep(z, 0, t1) {
                        int o = (of + z) % n;
                        cout << o + 1 << ' ';
                    }
                    of += t1;
                    cout << '\n';
                }
                int of2 = of;
                rep(j, 0, T0) {
                    cout << t0 << ' ';
                    rep(z, 0, t0) {
                        int o = (of2 + z) % n;
                        cout << o + 1 << ' ';
                    }
                    of2 += t0;
                    cout << '\n';
                }
            }
        }
    }
    
    return 0;
}