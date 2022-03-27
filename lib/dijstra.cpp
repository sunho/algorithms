pqg<pair<ll,int>> q;
q.push({0,0});
const i64 inf = 1e18 + 10;
vector<i64> d(n, inf);

while(!q.empty()) {
    auto [di, v] = q.top();
    q.pop();
    if (d[v] == inf) {
        d[v] = di;
    } else {
        continue;
    }
    trav(x, g[v]) {
        auto [u, w] = x;
        q.push({di + w, u});
    }
}