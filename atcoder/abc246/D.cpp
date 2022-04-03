#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll M = 1049960;
template<ll N> struct g_sint {
    ll x;
    static ll norm(ll x) { if (x > N) return N; return x; }
    g_sint(ll x) : x(x) {}
    ll val() const { return x; }
    g_sint operator-() const { return g_sint(norm(-x)); }
    g_sint &operator*=(const g_sint &rhs) { 
        if (rhs.x > 0 && x > N / rhs.x) {
            x = N;
            return *this;
        }
        x *= rhs.x;
        return *this; 
    }
    g_sint &operator+=(const g_sint &rhs) { x = norm(x + rhs.x); return *this; }
    g_sint &operator-=(const g_sint &rhs) { x -= rhs.x; return *this; }
    g_sint &operator/=(const g_sint &rhs) { x /= rhs.x; return *this; }
    friend g_sint operator*(const g_sint &lhs, const g_sint &rhs) { g_sint res = lhs; res *= rhs; return res; }
    friend g_sint operator+(const g_sint &lhs, const g_sint &rhs) { g_sint res = lhs; res += rhs; return res; }
    friend g_sint operator-(const g_sint &lhs, const g_sint &rhs) { g_sint res = lhs; res -= rhs; return res; }
    friend g_sint operator/(const g_sint &lhs, const g_sint &rhs) { g_sint res = lhs; res /= rhs; return res; }
    friend ostream & operator << (ostream &out, const g_sint &rhs) { out << rhs.val(); return out; }
    friend istream & operator >> (istream &in, g_sint &rhs) { ll x; in >> x; rhs = g_sint(x); return in; }
};
using sint = g_sint<1000000000000000000>;
void solve() {
    unsigned long long N;
    cin >> N;
    ll mini = 1e18 + 10;
    auto calc = [&](sint a, sint m) {
        sint aa = a*a;
        sint mm = m*m;
        return aa*a + a*mm + m*aa + mm*m;
    };
    for(ll a=0;a<=M;a++){
        int l = -1, r = a+1;
        while (r-l > 1) {
            ll m = (l+r) / 2;
            sint f = calc(a,m);
            if (f.val() >= N) r = m;
            else l = m;
        }
        ll cand = calc(a,r).val();
        if (cand >= N && ckmin(mini,cand)) {
        }
    }
    cout << mini << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}