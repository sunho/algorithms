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
    const ll inf = 1e18;
    int n,m;
    cin >> n >> m;
    set<pair<int,int>> edges;
    vector<vector<int>> g(n, vector<int>(n, -1));
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        --u,--v;
        g[u][v] = w;
        g[v][u] = w;
        edges.insert({u,v});
    }
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] != -1) {
                dist[i][j] = g[i][j];
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
            }
        }
    }
    int ans = 0;
    for(auto [u,v] : edges) {
        for(int i=0;i<n;i++){
            if (dist[u][i] + dist[i][v] <= g[u][v]){
                ans +=1;
                break;
            } 
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
