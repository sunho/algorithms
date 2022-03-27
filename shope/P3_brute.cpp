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

#define inf 1e11+10
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n,m,d;
    cin >> n >> m >> d;
    map<int, vector<pii>> F;
    rep(i, 0, m) {
        int ai,bi,ti;
        cin >> ai >> bi >> ti;
        ai--;
        F[ti].push_back({ai,bi});
    }
    int tm = F.size();
    vector<vector<ll>> rewards(tm, vector<ll>(n));
    vector<ll> times;
    {
        int t=0;
        trav(ft, F) { // ft: fireworks at each timing
            times.push_back(ft.first);
            trav(f, ft.second) {
                rep(i, 0, n) {
                    rewards[t][i] += f.y - abs(i-f.x);
                }
            }
            t++;
        }
    }
    vector<ll> avail(tm); // distance allowed t=0 -> t=times[i]
    rep(i, 0, tm) {
        if (i==0) {
            avail[i] = times[i] * d;
        } else {
            avail[i] = (times[i]-times[i-1]) * d;
        }
    }

    // trav(x, avail) {
    //     cout << x << ' ';
    // }
    // trav(x, rewards) {
    //     trav(y, x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<ll>> dp(tm, vector<ll>(n));
    rep(i,0,n) {
        dp[0][i] = rewards[0][i];
    }
    rep(i,1,tm) {
        rep(j,0,n) {
            ll best = -inf;
            rep(k,0,n) {
                if (abs(j-k) <= avail[i]) {
                    ckmax(best, dp[i-1][k] + rewards[i][j]);
                }
            }
            dp[i][j] = best;
        }
    }
    ll maxi = -inf;
    rep(i,0,n) {
        ckmax(maxi, dp[tm-1][i]);
    }
    trav(x, dp) {
        trav(y, x) {
            cout << y << ' ';
        }
        cout << '\n';
    }
    cout << maxi << '\n';

    return 0;
}