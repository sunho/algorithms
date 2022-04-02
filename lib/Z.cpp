template<int P> struct zint {
    int x;
    // assumes -P <= x <= 2P
    static int norm(int x) { if (x < 0) { x += P; } if (x >= P) { x -= P; } return x; }
    template<class T> T power(T a, ll b) { T res = 1; for (; b; b /= 2, a *= a) { if (b % 2) { res *= a; } } return res; }
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
using Z = zint<1000000007>;