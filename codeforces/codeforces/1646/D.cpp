#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template<class T> bool ckmin(T&a, T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, T&b) { bool B = a < b; a = max(a,b); return B; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand() uniform_int_distribution<int>(0, UINT_MAX)(rng)

const int N = 2e5+10;


vector<int> g[N];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    
    if (n == 2) {
        cout << "2 2\n";
        cout << "1 1\n";
        return 0;
    }

    vector<bool> visited(n);
    vector<vector<pii>> dp(n, vector<pii>(2, pii(-1,0)));
    
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto solve = [&](int u, int i, int p, auto&& solve) -> pii {
        if (dp[u][i] != pii(-1,0)) {
            return dp[u][i];
        }
        pii& res = dp[u][i];
        res.first = 0;
        res.second = 0;
        for (auto& x:g[u]) {
            if (x == p) continue;
            auto ri = solve(x, 0, u, solve);
            if (i == 1) {
                res.first += ri.first;
                res.second += ri.second;
            } else {
                auto li = solve(x, 1, u, solve);
                if (ri > li) {
                    res.first += ri.first;
                    res.second += ri.second;
                } else {
                    res.first += li.first;
                    res.second += li.second;
                }
            }
        }
        res.first += i;
        if (i == 0) {
            res.second -= 1;
        } else {
            res.second -= g[u].size();
        }

        return res;
    };

    vector<bool> good(n);
    auto dfs = [&](pii res, int u, int p, auto&& dfs) -> pii {
        if (res == dp[u][0]) {
            good[u] = 0;
            for (auto& x:g[u]) {
                if (x == p) continue;
                dfs(max(dp[x][0], dp[x][1]), x, u, dfs);
            }
        } else {
            good[u] = 1;
            for (auto& x:g[u]) {
                if (x == p) continue;
                dfs(dp[x][0], x, u, dfs);
            }
        }
      
        return res;
    };

    auto res = max(solve(0, 0, -1, solve), solve(0, 1, -1, solve));
    dfs(max(dp[0][0], dp[0][1]), 0, -1, dfs);
    res.second *= -1;
    cout << res.first << " " << res.second << '\n';
    for (int i=0;i<n;i++) {
        if (good[i]) {
            cout << g[i].size() << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
    cout << '\n';

    return 0;
}