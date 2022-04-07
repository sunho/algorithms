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
    string s;
    cin >> s;
    int n = s.size();
    map<char, set<int>> pos;
    const int inf = 1e9;
    int cnt = 0;
    rep(i,0,n) pos[s[i]].insert(i);
    int i = 0;
    while (i != n) {
        if (s[i] != s[i+1]) {
            int mini = inf;
            int mi;
            trav(ss, pos) {
                auto it = ss.y.lower_bound(i);
                if (it != ss.y.end()) {
                    auto jt = ss.y.lower_bound(*it+1);
                    if (jt != ss.y.end()) {
                        int d = *it - i;
                        d += *jt - *it - 1;
                        if (ckmin(mini, d)) {
                            mi = *jt+1;
                        }
                    }
                }
            }
            if (mini != inf) {
                cnt+= mini;
                i = mi;
            } else {
                cnt += n-i;
                i = n;
            }
        } else {
            i += 2;
        }
    }
    cout << cnt << '\n';
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