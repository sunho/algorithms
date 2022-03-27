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

#define inf 1e11+10
template<class T>
struct ConstSegTree {
    ConstSegTree() = delete;
    ConstSegTree(int N) : N(N), t(2 * N) {
    }
 
    T combine(T a, T b) {
        return max(a,b);
    }
 
    void build(const vector<T>& arr) {  // build the tree
        n = arr.size();
        for (int i=0;i<n;i++) t[i+n] = arr[i];
        for (int i = n - 1; i > 0; --i) t[i] = combine(t[i*2], t[i*2+1]);
    }
 
    void modify(int p, T value) {  // set value at position p
        for (t[p += n] = value; p > 1; p /= 2) t[p/2] = combine(t[p], t[p^1]);
    }
 
    T query(int l, int r) {  // sum on interval [l, r)
        T res = -inf;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l&1) res = combine(res, t[l++]);
            if (r&1) res = combine(res, t[--r]);
        }
        return res;
    }
 
    int N;
    vector<T> t;
    int n;
};

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n,m,d;
    cin >> n >> m >> d;
    map<int, vector<pii>> F;
    rep(i, 0, m) {
        int ai,bi,ti;
        cin >> ai >> bi >> ti;
        ai--;
        F[ti].push_back({ai,bi});
    }
    int tm = F.size();
    vector<vector<ll>> rewards(tm, vector<ll>(n));
    vector<ll> times;
    {
        int t=0;
        trav(ft, F) { // ft: fireworks at each timing
            times.push_back(ft.first);
            trav(f, ft.second) {
                rep(i, 0, n) {
                    rewards[t][i] += f.y - abs(i-f.x);
                }
            }
            t++;
        }
    }
    vector<ll> avail(tm); // distance allowed t=0 -> t=times[i]
    rep(i, 0, tm) {
        if (i==0) {
            avail[i] = times[i] * d;
        } else {
            avail[i] = (times[i]-times[i-1]) * d;
        }
    }

    /*
    500 499 498 497 496 495 494 493 492 491 
    992 993 994 995 996 996 996 996 1000 999 
    1496 1497 1498 1499 1500 1499 1498 1497 1496 1495 
    */
    // trav(x, avail) {
    //     cout << x << ' ';
    // }
    // trav(x, rewards) {
    //     trav(y, x) {
    //         cout << y << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<ll>> dp(2, vector<ll>(n));
    rep(i,0,n) {
        dp[0][i] = rewards[0][i];
    }
    rep(i,1,tm) {
        ConstSegTree<ll> st(n);
        st.build(dp[(i-1)%2]);
        rep(j,0,n) {
            dp[i%2][j] = st.query(max(j-avail[i], (ll)0), min(j+avail[i] + 1, (ll)n)) + rewards[i][j];
        }
    }
    ll maxi = -inf;
    rep(i,0,n) {
        ckmax(maxi, dp[(tm-1)%2][i]);
    }
    cout << maxi << '\n';

    return 0;
}