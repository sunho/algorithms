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
#define inf 1e18+10
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
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> q;
    vector<ll> d(n, -1);
    vi dc(n,-1);
    vi seen(n);
    vector<ll> dd(n, -1);

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

    while(!q.empty()) {
        auto [di, v, c] = q.top();
        q.pop();
        if (seen[v] == 0) {
            seen[v] = c;
            dc[v] = c;
            d[v] = di;
        } else if (seen[v] != -1 && seen[v] != c) {
            seen[v] = -1;
            dd[v] = di;
        } else {
            continue;
        }
        trav(x, g[v]) { 
            auto [u, w] = x;
            q.push({di + w, u, c});
        }
    }

    rep(i,0,n) {
        if (A[i] != dc[i]) {
            cout << d[i] << " ";
        } else {
            cout << dd[i] << " ";
        }
    }    


    return 0;
}
