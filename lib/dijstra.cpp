template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

pqg<pair<ll,int>> q;
q.push({0,0});
vector<ll> d(n, -1);

while(!q.empty()) {
    auto [di, v] = q.top();
    q.pop();
    if (d[v] == -1) {
        d[v] = di;
    } else if() {
        continue;
    }
    for(auto x: g[v]) {
        auto [u, w] = x;
        q.push({di + w, u});
    }
}