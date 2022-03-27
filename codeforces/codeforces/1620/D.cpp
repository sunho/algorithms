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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi A(n);
        rep(i, 0, n) cin >> A[i];
        int mx = *max_element(all(A));
        auto check = [&](int r, vi& c, int l, auto&& check) {
            int cnt = 0;
            rep(i, 0, 3) cnt += c[i]; 
            if (r % 3 == 0 && r <= l*3) {
                return true;
            }
            if (cnt == 0 && r%3 != 0) {
                return false;
            }
            bool res = false;
            rep(i, 1, 4) {
                if (c[i-1] > 0) {
                    if (r >= i) {
                        c[i-1]--;
                        res |= check(r-i,c,l,check);
                        c[i-1]++;
                    }
                }
            }
            return res;
        };
        ll ans2 = 1e9+10;
        vi O = {0,1,2,3,4,5,6,7,8};
        trav(o, O) {
            if (mx < o) continue;
            if ((mx - o) % 3 != 0) continue;
            ll l = (mx - o)/ 3;
            vector<vi> C;
            auto genCases = [&](int r, int i, vi& c, auto&& genCases) {
                if (r == 0) {
                    C.push_back(c);
                    return;
                }
                rep(j, 1, 4) {
                    if (r >= j) {
                        c[j-1]++;
                        genCases(r-j, i+1, c, genCases);
                        c[j-1]--;
                    }
                }
            };
            C.resize(unique(all(C))-C.begin());
            vi tmp(3);
            ll ans = 1e9+10;
            genCases(o, 0, tmp, genCases);
            trav(c, C) {
                bool okay = true;
                trav(a, A) {
                    okay &= check(a, c, l, check);
                }
                if (okay) {
                    ll cnt = 0;
                    trav(x, c) cnt+=x;
                    ckmin(ans, cnt);
                }
            }
            ckmin(ans2, ans+l);
        }
        cout << ans2 << '\n';
    }

    return 0;
}
