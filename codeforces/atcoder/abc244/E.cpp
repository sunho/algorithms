#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
template<int P> struct g_zint {
    int x;
    // assumes -P <= x <= 2P
    static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
    g_zint(int x = 0) : x(norm(x)) {}
    g_zint(ll x) : x(norm(x % P)) {}
    int val() const { return x; }
    g_zint operator-() const { return g_zint(norm(P - x)); }
    g_zint inv() const { assert(x != 0); return power(*this, P - 2); }
    g_zint& operator*=(const g_zint& rhs) { x = ll(x) * rhs.x % P; return *this; }
    g_zint& operator+=(const g_zint& rhs) { x = norm(x + rhs.x); return *this; }
    g_zint& operator-=(const g_zint& rhs) { x = norm(x - rhs.x); return *this; }
    g_zint& operator/=(const g_zint& rhs) { return *this *= rhs.inv();}
    friend g_zint operator*(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res *= rhs; return res; }
    friend g_zint operator+(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res += rhs; return res; }
    friend g_zint operator-(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res -= rhs; return res; }
    friend g_zint operator/(const g_zint& lhs, const g_zint& rhs) { g_zint res = lhs; res /= rhs; return res; }
    friend ostream& operator << (ostream& out, const g_zint& rhs) { out << rhs.val(); return out; }
    friend istream& operator >> (istream& in, g_zint& rhs) { ll x; in >> x; rhs = g_zint(x); return in; }
};
using zint = g_zint<998244353>;
void solve() {
    int n,m,k,s,t,x;
    cin >> n >> m >> k >> s >> t >> x;
    --s,--t,--x;
    vector<vector<int>> g(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<vector<zint>>> dp(2, vector<vector<zint>>(n, vector<zint>(2, zint(0))));
    set<int> visited;
    visited.insert(s);
    dp[0][s][0] = 1;
    for(int i=0;i<k;i++) {
        int c = i&1;
        set<int> added;
        dp[c^1].assign(n, vector<zint>(2, zint(0)));
        for(auto u : visited) {
            for (int j=0;j<2;j++) {
                for (auto v : g[u]) {
                    int jj = j;
                    if (v == x) jj ^= 1;
                    dp[c^1][v][jj] += dp[c][u][j];
                    if (!visited.count(v)) added.insert(v);
                }
            }
        }
        visited.insert(all(added));
    }
    cout << dp[k&1][t][0] << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
