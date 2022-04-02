#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
#define x first
#define y second
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(x,a) for(auto& x : (a))
#define nl '\n'
template<class T> using vec = vector<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <typename T,typename U> pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) { return {l.first+r.first,l.second+r.second}; }
template<class N> N mod(N x, N d) { return ((x%d) + d) % d; }
template<int P> struct zint {
    int x;
    // assumes -P <= x <= 2P
    static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
    template<class T> T power(T a, i64 b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
    zint(int x = 0) : x(norm(x)) {}
    zint(i64 x) : x(norm(x % P)) {}
    int val() const { return x; }
    zint operator-() const { return zint(norm(P - x)); }
    zint inv() const { assert(x != 0); return power(*this, P - 2); }
    zint &operator*=(const zint &rhs) { x = i64(x) * rhs.x % P; return *this; }
    zint &operator+=(const zint &rhs) { x = norm(x + rhs.x); return *this; }
    zint &operator-=(const zint &rhs) { x = norm(x - rhs.x); return *this; }
    zint &operator/=(const zint &rhs) { return *this *= rhs.inv();}
    friend zint operator*(const zint &lhs, const zint &rhs) { zint res = lhs; res *= rhs; return res; }
    friend zint operator+(const zint &lhs, const zint &rhs) { zint res = lhs; res += rhs; return res; }
    friend zint operator-(const zint &lhs, const zint &rhs) { zint res = lhs; res -= rhs; return res; }
    friend zint operator/(const zint &lhs, const zint &rhs) { zint res = lhs; res /= rhs; return res; }
};
using Z = zint<1000000007>;

void solve() {
    int n,m;
    cin >> n >> m;
    int s,t;
    cin >> s >> t;
    --s,--t;
    vec<vec<int>> g(n);
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    pqg<tuple<i64,int,int>> q;
    q.push({0,s,0});
    const i64 inf = 1e9;
    vec<i64> dist(n, -1);
    vec<bool> seen(n);
    vec<vec<Z>> dp(n, vec<Z>(2, Z(0)));
    dist[s] = 0;
    dp[s][0] = 1;
    while(!q.empty()) {
        auto [di, v,j] = q.top();
        q.pop();
        trav(u, g[v]) {
            if (dist[u] == -1) {
                dist[u] = di+1;
                dp[u][0] += dp[v][j];
                q.push({di + 1, u, 0});
            } else if(dist[u] == di+1) {
                dp[u][0] += dp[v][j];
            } else if(dist[u] == di) {
                dp[u][1] += dp[v][j];
                if(!seen[u]) {
                    q.push({di + 1, u, 1});
                    seen[u] = true; 
                }
            }
        }
    }

    cout << (dp[t][1]+ dp[t][0]).val() << nl;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}