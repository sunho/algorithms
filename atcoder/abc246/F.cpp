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
template<int P> struct zint {
    int x;
    // assumes -P <= x <= 2P
    static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
    zint(int x = 0) : x(norm(x)) {}
    zint(ll x) : x(norm(x % P)) {}
    int val() const { return x; }
    zint operator-() const { return zint(norm(P - x)); }
    zint inv() const { assert(x != 0); return power(*this, P - 2); }
    zint &operator*=(const zint &rhs) { x = ll(x) * rhs.x % P; return *this; }
    zint &operator+=(const zint &rhs) { x = norm(x + rhs.x); return *this; }
    zint &operator-=(const zint &rhs) { x = norm(x - rhs.x); return *this; }
    zint &operator/=(const zint &rhs) { return *this *= rhs.inv();}
    friend zint operator*(const zint &lhs, const zint &rhs) { zint res = lhs; res *= rhs; return res; }
    friend zint operator+(const zint &lhs, const zint &rhs) { zint res = lhs; res += rhs; return res; }
    friend zint operator-(const zint &lhs, const zint &rhs) { zint res = lhs; res -= rhs; return res; }
    friend zint operator/(const zint &lhs, const zint &rhs) { zint res = lhs; res /= rhs; return res; }
};
using Z = zint<998244353>;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<bitset<26>> S(n);
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(char ch : s) S[i].set(ch-'a');
    }
    Z ans = 0;
    for(int mask=1; mask < (1<<n); mask++) {
        bitset<26> C;
        C.set();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(mask & (1<<i)) {
                C &= S[i];
                cnt++;
            }
        }
        Z c = (int)C.count();
        if (cnt&1) {
            ans += power(c, l);
        } else {
            ans -= power(c, l);
        }
    }
    cout << ans.val() << "\n";
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
