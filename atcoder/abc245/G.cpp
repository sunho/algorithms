#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define endl '\n'

template<class T> bool ckmin(T&a, const T&b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T&b) { bool B = a < b; a = max(a,b); return B; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vi A(n);
    rep(i,0,n) cin >> A[i];

    vector<vector<pii>> g(n);
    const ll inf = 1e18+10;
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> q;
    vector<vector<pair<ll,int>>> dist(n, vector<pair<ll,int>>(2, {-1,-1}));

    rep(i,0,l) {
        int x;
        cin >> x;
        --x;
        q.push({0, x, A[x]});
    }
    rep(i,0,m) {
        int x,y,z;
        cin >> x >> y >> z;
        --x, --y;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }

    while (!q.empty()) {
        auto [d, u, c] = q.top();
        q.pop();
        if (dist[u][0].x == -1) {
            dist[u][0] = {d, c};
        } else if (dist[u][1].x == -1 && dist[u][0].y != c) {
            dist[u][1] = {d, c};
        } else {
            continue;
        }
        trav(v, g[u]) q.push({d + v.y, v.x, c});
    }

    rep(i,0,n) {
        if (dist[i][0].y != A[i]) {
            cout << dist[i][0].x << " ";
        } else {
            cout << dist[i][1].x << " ";
        }
    }

    return 0;
}
