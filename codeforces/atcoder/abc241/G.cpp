#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct Flow {
    const int INF = 1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };
    vector<Edge> e;
    vector<vector<int>> g;
    vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        queue<int> q;
        h[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : g[u]) {
                int v = e[i].to;
                int c = e[i].cap;
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (; cur[u] < g[u].size(); cur[u]++) {
            int j = g[u][cur[u]];
            int v = e[j].to;
            int c = e[j].cap;
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void add_edge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int max_flow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> S(n);
    vector<set<int>> M;
    int N = n*n;
    Flow oflow(N+n+2);
    set<pair<int,int>> added;
    int s = N+n, t = N+n+1;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        --u,--v;
        oflow.add_edge(u*n+v,N+u,1);
        oflow.add_edge(s,u*n+v,1);
        added.insert({u,v});
        added.insert({v,u});
    }
    for(int k=0;k<n;k++){
        Flow flow = oflow;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if (!added.count({i,j}) && !(i == k || j ==k)){
                    flow.add_edge(i*n+j,N+i,1);
                    flow.add_edge(i*n+j,N+j,1);
                    flow.add_edge(s, i*n+j, 1);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!added.count({k,i})){
                flow.add_edge(k*n+i,N+k,1);
                flow.add_edge(s, k*n+i, 1);
            }
        }
        int win = flow.g[N+k].size();
        for(int i=0;i<n;i++){
            if (i == k){
                flow.add_edge(N+i,t,win);
            } else {
                flow.add_edge(N+i,t,win-1);
            }
        }
        if (flow.max_flow(s,t) == n*(n+1)/2) {
            cout << k + 1 << " ";
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
