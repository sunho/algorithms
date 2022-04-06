#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve(int T) {
    const ll inf = 1e18;
    int n;
    cin >> n;
    vector<int> A(n+1);
    vector<vector<int>> g(n+1);
    for(int i=0;i<n;i++) {
        cin >> A[i+1];
    }
    vector<int> mdp(n+1, 0);
    vector<vector<ll>> dp(n+1, vector<ll>(2, -1));
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        g[v].push_back(i+1);
    }
    auto dfs = [&](int u, int r, auto&& self) {
        if (g[u].size() == 0) {
            mdp[u] = A[u];
            return A[u];
        }
        ll sum = 0;
        pair<ll,int> mini = {inf,0};
        r = max(A[u],r);
        for (int v : g[u]) {
            ll cand = self(v, r, self);
            sum += cand;
            ckmin(min, {cand,v});
        }
        mdp[u] = max(A[u], mdp[v])
        
        
    };
    dfs(0, 0, dfs);
    cout << "Case #" << T << ": " << dp[0][0] << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        solve(i);
    }

    return 0;
}
