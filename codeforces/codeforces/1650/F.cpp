#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<pii> O;
        vector<vi> OM(n);
        vi A(n);
        for(int i=0;i<n;i++) {
            cin >> A[i];
        }
        for(int i=0;i<m;i++) {
            int e,t,p;
            cin >> e >> t >> p;
            --e;
            O.push_back({t,p});
            OM[e].push_back(i);
        }
        bool okay = true;
        vi ans;
        vi mini;
        for(int i=0;i<n;i++) {
            int k = OM[i].size();
            int inf = 1e9+10;
            vector<vi> dp(k+1, vi(101, inf));
            vector<vi> sel(k+1, vi(101));
            for(int j=0;j<k;j++) {
                dp[j][0] = 0;
            }
            for(int j=0;j<k;j++) {
                for(int z=0;z<=100;z++) {
                    auto opt = O[OM[i][j]];
                    int nz = min(z + opt.second,100);
                    int ndp = dp[j][z] + opt.first;
                    if (ckmin(dp[j+1][nz], ndp)) {
                        sel[j+1][nz] = nz - z;
                    }
                    if (ckmin(dp[j+1][z], dp[j][z])) {
                        sel[j+1][z] = 0;
                    }
                }
            }
            if (dp[k][100] == inf) {
                okay = false;
                break;
            }
            mini.push_back(dp[k][100]);
            vi cand;
            int r = 100;
            for(int j=k;j>0;j--) {
                if (sel[j][r] != 0) {
                    r -= sel[j][r];
                    cand.push_back(OM[i][j-1]);
                }
            }
            reverse(cand.begin(),cand.end());
            ans.insert(ans.end(), cand.begin(), cand.end());
        }
        if (!okay) {
            cout << -1 << '\n';
            continue;
        }
        okay = true;
        int tt = 0;
        for(int i=0;i<n;i++) {
            tt += mini[i];
            if (tt > A[i]) {
                okay = false;
            }
        }
        if (!okay) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for (auto& x:ans) cout << x + 1 << ' ';
        cout << '\n';

    }

    return 0;
}