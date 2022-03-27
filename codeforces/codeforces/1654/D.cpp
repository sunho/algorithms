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

constexpr int P = 998244353;
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

const int N =  2e5+5;

int main() {
    #ifdef _DEBUG
        freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    vector<int> d;
    vector<vector<int>> factors;
    d.assign(N, 1);
    factors.resize(N);
    for (int i = N-1; i > 1; i--)
        for (int j = i; j < N; j += i)
            d[j] = i;
    for (int i = 1; i < N; i++)
        for (int x = i; x != 1; x /= d[x])
            factors[i].push_back(d[x]);
    vector<int> wf(N); // max bound
    vector<int> f(N); // current bound
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, pii>>> g(n);
        wf.assign(N,0);
        f.assign(N,0);
        set<int> distinct_primes;
        rep(i, 0, n-1) {
            int a,b,r1,r2;
            cin >> a >> b >> r1 >> r2;
            a--;b--;
            g[a].push_back({b,{r2,r1}});
            g[b].push_back({a,{r1,r2}});

            for (int z : factors[r1])
                distinct_primes.insert(z);
            for (int z : factors[r2])
                distinct_primes.insert(z);
        }
        vector<bool> vis(n);
        auto dfs = [&](int i, auto&& self) -> void{
            vis[i] = true;
            trav(x, g[i]) {
                if (vis[x.x]) continue;
                auto [r1, r2] = x.y; // r1: x , r2: y times x/y
                trav(p, factors[r1]) { 
                    f[p]--;
                }
                trav(p, factors[r2]) { 
                    f[p]++;
                    wf[p] = max(wf[p], f[p]);
                }
                self(x.x, self);
                trav(p, factors[r1]) { 
                    f[p]++;
                }
                trav(p, factors[r2]) { 
                    f[p]--;
                }
            }
        };
        dfs(0, dfs);
        Z cnt = 1;
        trav(x, distinct_primes) {
            rep(j,0,wf[x]) {
                cnt *= x;
            }
        }
        vis.assign(n, false);
        Z cur = cnt;
        auto dfs2 = [&](int i, auto&& self) -> void{
            vis[i] = true;
            trav(x, g[i]) {
                if (vis[x.x]) continue;
                auto [r1, r2] = x.y; // r1: x , r2: y times x/y
                Z tmp = cur;
                trav(p, factors[r1]) { 
                    tmp*=p;
                }
                trav(p, factors[r2]) { 
                    tmp/=p;
                }
                cnt += tmp;
                auto back = cur;
                cur = tmp;
                self(x.x, self);
                cur = back;
            }
        };
        dfs2(0, dfs2);
        cout << cnt.val() << '\n';
    }

    return 0;
}


// d = k * c/d
// d = lcm(y) * x / y
// d = p1^n*p2^m * p1^a*p^2b / (p1^c*p2^d) 
// n - a + c >= k
// n >= k - (c-a)
// 
// int if and only if n+a-c >= 0 and m + b - d >= 0
// n >= c-a
// n >= k
// we can't
// 1 -(3)> 2 -(-2)> 3
//
// d = lcm(lcm(y), k) p * z / k
// 
//
// c = d * y/x
// 