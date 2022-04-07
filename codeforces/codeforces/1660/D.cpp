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
const int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    deque<int> A(n);
    rep(i,0,n) cin >> A[i];

    auto calc = [&](int a, int b) {
        if (a == 0) return 0;
        if (b == 0) return 0;
        if (abs(b) == 2) {
            if (a < 0) a-=2;
            else a+=2;
        }
        if (b < 0) a*=-1;
        return a;
    };
    pii maxi = {calc(1,A[0]), 0};
    pii mini = {calc(1,A[0]), 0};
    pii gmaxi = {calc(1,A[0]), 0};
    int starti = 0;
    int endi = 1;
    for (int i = 1; i < n; i++)
    {
        pii temp = max({pii{calc(1,A[i]), i}, pii{calc(maxi.x, A[i]), maxi.y}, pii{calc(mini.x, A[i]), mini.y}});
        mini = min({pii{calc(1,A[i]),i}, pii{calc(maxi.x, A[i]),maxi.y}, pii{calc(mini.x,A[i]), mini.y}});
        maxi = temp;
        if (ckmax(gmaxi, maxi)) {
            starti = gmaxi.y;
            endi = i+1;
        }
    }
    if (gmaxi.x <= 1) {
        cout << n << " " << 0 << nl;
    } else {
        cout << starti << " " << (n-endi) << nl;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
