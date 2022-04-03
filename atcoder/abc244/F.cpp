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
    const int inf = 1e9;
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int N = 1 << n;
    vector<vector<int>> dist(N, vector<int>(n, inf));
    //dist[0][0] = 0;
    queue<tuple<int, int, int>> q;
    for (int i=0;i<n;i++) {
        q.push({1, 1<<i, i});
    }
    while (!q.empty()) {
        auto [d, r, u] = q.front();
        q.pop();
        if (dist[r][u] == inf) {
            dist[r][u] = d;
        } else {
            continue;
        }
        for (int v : g[u]) {
            int rr = r;
            rr ^= (1<<v);
            q.push({d+1, rr, v});
        }
    }
    ll ans = 0;
    for (int s = 1; s < N; s++) {
        ans += *min_element(all(dist[s]));
    }
    cout << ans << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
