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

void binom_coeff(int BM, vector<vector<ll>>& C) {
  C.assign(BM+1, vector<ll>(BM+1, 0));
  C[0][0] = 1;
  for (int n = 1; n <= BM; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
  }
}

void solve() {
    int n,m,b,w;
    cin >> n >> m >> b >> w;

    const int M = 2510;
    vector<vector<zint>> C(M+1, vector<zint>(M+1, 0));
    C[0][0] = 1;
    for (int n = 1; n <= M; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }

    vector<int> D= {b,w};
    vector<vector<vector<zint>>> f(2, vector<vector<zint>>(n+1, vector<zint>(m+1)));
    for(int z=0;z<2;z++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[z][i][j] = C[i*j][D[z]];
                for(int ii=1;ii<=i;ii++){
                    for(int jj=1;jj<=j;jj++){
                        if (ii == i && jj == j) continue;
                        f[z][i][j] -= C[i][ii] * C[j][jj] * f[z][ii][jj];
                    }
                }
            }
        }
    }

    zint ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int ii=1;ii<=n-i;ii++){
                for(int jj=1;jj<=m-j;jj++){
                    ans += C[n][i] * C[m][j] * C[n-i][ii] * C[m-j][jj] * f[0][i][j] * f[1][ii][jj];
                }
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
