#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
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

int inf = 1e9 + 10;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int s, e;
        cin >> s >> e;
        --s, --e;

        vector<vi> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<int> used(n);
        vector<int> d(n), p(n);
        vector<Z> cnt(n);

        queue<pii> q;
        q.push({s,0});
        d.assign(n, inf);
        used[s] = 1;
        cnt[s] = 1;
        p[s] = -1;
        d[s] = 0;
        vector<Z> cnt2(n);
        cnt[s] = 1;
        cnt2[s] = 0;
        while (!q.empty()) {
            auto x = q.front();
            int v = x.first;
            q.pop();
            for (int u : g[v]) {
                if (d[u] == d[v]) {
                    cnt2[v] += cnt[u];
                }
            }
            for (int u : g[v]) {
                int nd = d[v] + 1;
                if (!used[u]) {
                    q.push({u, nd});
                    used[u]++;
                    d[u] = nd;
                    cnt[u] = cnt[v];
                    cnt2[u] = cnt2[v];
                } else if (d[u] == nd) {
                    cnt[u] += cnt[v];
                    cnt2[u] += cnt2[v];
                }
            }

        }
        cout << (cnt[e] + cnt2[e]).val() << '\n';
    }

    return 0;
}

