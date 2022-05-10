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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string S;
    cin >> S;
    vector<int> path;
    vector<int> enc(n);
    vector<bool> visited(n);
    auto dfs = [&](int u, int p, auto&& self) -> void {
        visited[u] = true;
        enc[u]++;
        path.push_back(u);
        for(int v : g[u]){
            if (v == p) continue;
            if (visited[v]) continue;
            self(v,u,self);
            path.push_back(u);
            enc[u]++;
        }
        if ((enc[u]&1) != S[u]-'0') {
            if(p != -1) {
                path.push_back(p);
                path.push_back(u);   
                enc[p]++;     
            } else {
                assert(!g[u].empty());
                path.push_back(g[u][0]);
                path.push_back(u);
                path.push_back(g[u][0]);
            }
        }
    };
    if (n==1) {
        if (S[0] == '1') {
            cout << 1 << " " << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {
        dfs(0,-1,dfs);
        cout << path.size() << "\n";
        vector<int> cnt(n);
        for(int u : path) cnt[u]++;
        for(int u : path) { cout << u + 1 << " "; }
        // for(int i=0;i<n;i++) {
        //     if (S[i]-'0' != (cnt[i]&1)) {
        //         cout << "fUck" << "\n";
        //     }
        // }
    }


}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
