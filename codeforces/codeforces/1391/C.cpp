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

constexpr int P = 1000000007;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    // 1 2 3 ok 1 2 3
    // 3 2 1 ok 3 2 1
    // 1 3 2 ok 1 3 2
    // 2 3 1 ok 3 1 2
    // 3 1 2 no 2 3 1
    // 2 1 3 no 2 1 3

    // big 5 big
    // there exists 
    // both a[a] > a[j]
    // a[b] > a[j]
    // 
    // for all 
    // either a[a] < a[j]
    // a[b] < a[j]
    // small j small either
    // for all a[a] < a[i] -> increasing
    // for all a[i] > a[b] -> decreasing
    // all decreasing
    // all increasing
    // increasing | decreasing
    // n is always > a[a] a[b]
    // (a) n (b)
    // b: decreasing
    // a: increasing
    // if add n to a part always increasing
    // given a was increasing
    // n is the end of increasing part
    // 4 5 |  n 3 2 1
    // 1 2 3 4 n 5
    int n;
    cin >> n;

    Z ans = 1;
    rep(i,1,n+1) {
        ans *= i;
    }
    Z pot = 1;
    rep(i, 0, n-1) {
        pot *= 2;
    }
    cout << (ans - pot).val() << "\n";
    
    return 0;
}