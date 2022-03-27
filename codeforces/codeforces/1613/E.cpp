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

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        vector<vector<char>> M(n, vector<char>(m,0));
        vector<vector<char>> seen(n, vector<char>(m,0));
        pii L;
        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> M[i][j];
                if (M[i][j] == 'L') L = {i,j};
            }
        }

        auto isvalid = [&](pii dir) {
            if (dir.x < 0 || dir.x >= n || dir.y < 0 || dir.y >= m) return false;
            return M[dir.x][dir.y] == '.';
        };
        auto dfs = [&](pii u, auto&& self) -> void {
            vector<pii> dirs = { {u.x-1, u.y}, {u.x+1,u.y}, {u.x, u.y-1}, {u.x, u.y+1} };
            int al = 0;
            trav(dir, dirs) if (isvalid(dir)) al++;
            if (M[u.x][u.y] == 'L') {
                trav(dir, dirs) if (isvalid(dir)) self(dir,self);
            } else if (al <= 1) {
                M[u.x][u.y] = '+';
                trav(dir, dirs) if (isvalid(dir)) self(dir,self);
            }
        };
        dfs(L, dfs);
        trav(row, M) {
            trav(cell, row) cout << cell;
            cout << '\n';
        }
    }

    return 0;
}
