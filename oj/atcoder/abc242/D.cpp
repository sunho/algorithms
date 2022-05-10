#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

template<ll N> struct g_sint {
    ll x;
    static ll norm(ll x) { if (x > N) return N; return x; }
    g_sint(ll x) : x(x) {}
    ll val() const { return x; }
    g_sint operator-() const { return g_sint(norm(-x)); }
    g_sint& operator*=(const g_sint& rhs) { if (rhs.x > 0 && x > N / rhs.x) { x = N; return *this; } x *= rhs.x; return *this; }
    g_sint& operator+=(const g_sint& rhs) { x = norm(x + rhs.x); return *this; }
    g_sint& operator-=(const g_sint& rhs) { x -= rhs.x; return *this; }
    g_sint& operator/=(const g_sint& rhs) { x /= rhs.x; return *this; }
    friend g_sint operator*(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res *= rhs; return res; }
    friend g_sint operator+(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res += rhs; return res; }
    friend g_sint operator-(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res -= rhs; return res; }
    friend g_sint operator/(const g_sint& lhs, const g_sint& rhs) { g_sint res = lhs; res /= rhs; return res; }
    friend ostream& operator<<(ostream& out, const g_sint& rhs) { out << rhs.val(); return out; }
    friend istream& operator>>(istream& in, g_sint& rhs) { ll x; in >> x; rhs = g_sint(x); return in; }
};
using sint = g_sint<1000000000000000000>;

int ilog2(int x) {
    return 32 - __builtin_clz(x) -1;
}

void solve() {
    const ll inf = 1e18;
    string S;
    cin >> S;
    int q;
    cin >> q;
    while (q--) {
        ll t,k;
        cin >> t >> k;
        --k;
        int t0 = 0;
        ll n = 1;
        while (t0 < t && n < inf) {
            t0++;
            n <<= 1;   
        }
        ll j = k / n;
        k %= n;
        ll a = t-t0;
        while (n != 1) {
            if (k >= n/2) {
                a += 2;
                k -= n/2;
            } else {
                a++;
            }
            n/=2;
        }
        a += S[j]-'A';
        string B = "ABC";
        cout << B[((a % 3) + 3)%3] << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
