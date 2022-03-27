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

inline int mod(int i, int n) {
    return (i % n + n) % n;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi A(n);
        rep(i, 0, n) {
            cin >> A[i];
            A[i]--;
        }
        // -(i - k) mod n
        // k - i mod n
        //
        auto check = [&](int k) {
            vi B(n);
            rep(i,0,n) {
                B[mod(i-k, n)] = i;
            }
            vector<bool> vis(n);
            int cycle = 0;
            auto dfs = [&](int i, auto&& self) -> void {
                vis[i] = true;
                if (vis[B[A[i]]]) cycle++;
                else self(B[A[i]], self);
            };
            rep(i,0,n) if(!vis[i]) dfs(i, dfs);
            return n - cycle;
        };
        map<int, int> cnt;
        rep(i, 0, n) {
            cnt[mod(-A[i] + i, n)]++;
        }
        vector<pii> cnt2;
        trav(x, cnt) {
            cnt2.push_back({x.y,x.x});
        }
        sort(all(cnt2), greater<pii>());
        vi ans;
        rep(i,0,cnt2.size()) {
            if (i >= 3) break;
            if (check(cnt2[i].y) <= k) {
                ans.push_back(cnt2[i].y);
            }
        }
        sort(all(ans));
        cout << ans.size() << ' ';
        trav(x, ans) {
            cout << x << " ";
        }
        cout << '\n';

    }

    return 0;
}
