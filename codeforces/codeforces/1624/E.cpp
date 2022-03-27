#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;
#define TU(X,Y,Z,T) auto X = get<0>(T); auto Y = get<1>(T); auto Z = get<2>(T);
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        map<string, tiii> db;
        for(int i=0;i<n;i++) {
            string s;
            cin >> s;
            for(int j=0;j<m-1;j++) {
                db[s.substr(j, 2)] = {j, j+2, i};
            }
            for(int j=0;j<m-2;j++) {
                db[s.substr(j, 3)] = {j, j+3, i};
            }
        }
        string s;
        cin >> s;
        vi dp(m+1);
        vector<int> sels(m+1);
        dp[0] = true;
        for(int i=0;i<m-1;i++) {
            string k2 = s.substr(i,2);
            if (dp[i]) {
                if (db.count(k2)) {
                    dp[i+2] = true;
                    sels[i+2] = 2;
                }
                if (i < m-2) {
                    string k3 = s.substr(i,3);
                    if (db.count(k3)) {
                        dp[i+3] = true;
                        sels[i+3] = 3;
                    }
                }
            }
        }
        if (!dp[m]) {
            cout << "-1" << '\n';
        } else {
            vector<tiii> ans;
            int i = m;
            while (i > 0) {
                int k = sels[i];
                ans.push_back(db[s.substr(i-k, k)]);
                i -= k;
            }
            reverse(ans.begin(),ans.end());
            cout << ans.size() << '\n';
            for (auto& x:ans) {
                TU(l,r,j,x);
                cout << l + 1 << " " << r << " " << j + 1 << '\n';
            }
        }
    }

    return 0;
}