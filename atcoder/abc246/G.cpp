#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n-1;i++){
        cin >> A[i+1];
    }
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto go = [&](int k) -> bool {
        auto dfs = [&](int u, int p, auto &&self) -> int {
            int sum = 0;
            for(int v : g[u]) {
                if (p == v) continue;
                sum += self(v,u,self);
            }
            int c = A[u] >= k ? 1 : 0;
            return c + max(sum-1, 0);
        };
        return dfs(0,0,dfs) > 0;
    };
    int l = -1, r = 1e9 + 1;
    while (r-l > 1) {
        int mid = (r+l) >> 1;
        if (go(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
