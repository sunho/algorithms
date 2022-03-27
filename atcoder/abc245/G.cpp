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
    priority_queue<tuple<ll,int, int>, vector<tuple<ll,int,int>>, greater<>> q;
    vector<vector<pair<ll,int>>> d(n, vector<pair<ll,int>>(2, {inf, -1}));
    vi seen(n);
    vector<ll> dd(n, inf);

    rep(i,0,l) {
        int x;
        cin >> x;
        --x;
        q.push({0, x, 0});
        d[x][0] = {0, A[x]};
    }
    rep(i,0,m) {
        int x,y,z;
        cin >> x >> y >> z;
        --x, --y;
        g[x].push_back({y,z});
        g[y].push_back({x,z});
    }

    //     a
    // S   b
    //     c
    //
    while (!q.empty()) {
        auto [di, v, j] = q.top();
        q.pop();
        if (d[v][j].x < di) continue;

        for (auto edge : g[v]) {
            auto [u, w] = edge;
            //ll last = d[u];
            pair<ll,int> nn = {d[v][j].x + w, d[v][j].y};
            if (nn.y == d[u][0].y && nn.x >= d[u][0].x) {
                continue;
            }
            if (nn < d[u][0]) {
                if (nn.y != d[u][0].y) {
                    d[u][1] = d[u][0];
                    q.push({d[u][0].x, u, 1});
                }
                d[u][0]=nn;
                q.push({d[u][0].x, u, 0});
            } else {
                if (ckmin(d[u][1], nn)) {
                    q.push({d[u][1].x, u, 1});
                }
            }
        }
    }

    trav(x, d) trav(y, x) if (y.x==inf) y.x = -1;

    rep(i,0,n) {
        if (d[i][0].y != A[i]) {
            cout << d[i][0].x << " ";
        } else {
            cout << d[i][1].x << " ";
        }
    }    


    return 0;
}
