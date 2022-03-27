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

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n,m;
    cin >> n >> m;

    vector<vector<char>> M(n, vector<char>(m));
    vector<vector<char>> visited(n, vector<char>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> M[i][j];

    if (n < 3 || m < 3) {
        cout << "NO" << '\n';
        return 0;
    }

    auto dfs = [&](pii u, pii dir, auto&& self) {
        visited[u.x][u.y] = 1;
        vector<pii> nexts = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
        trav(next, nexts) {
            pii v = u + next;
            if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= m) continue;
            if (M[v.x][v.y] == '.') continue;
            if (visited[v.x][v.y]) continue;
            if (dir != pii(0,0) && dir != next) return false;
            if (!self(v, next, self)) return false;
        }
        M[u.x][u.y] = '.';

        return true;
    };

    int cnt = 0;
    vector<char> pat = {'.','*','.','*','*','*','.','*','.'};
    rep(i, 0, n-2) {
        rep(j, 0, m-2) {
            vector<char> val = { M[i][j], M[i][j+1], M[i][j+2], M[i+1][j], M[i+1][j+1], M[i+1][j+2], M[i+2][j], M[i+2][j+1], M[i+2][j+2]};
            if (pat == val) {
                if (dfs({i+1,j+1}, {0,0}, dfs)) cnt++;
            }
        }
    }

    bool ans = true;
    if (cnt != 1) ans = false;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (M[i][j] == '*') ans = false;
        }
    }

    if (ans) cout << "YES" << '\n'; else cout << "NO" << '\n';

    return 0;
}
