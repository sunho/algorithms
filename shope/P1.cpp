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

    vector<vi> M(n, vi(m));
    vector<vi> seen(n, vi(m));
    map<int, vector<pii>> portals;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> M[i][j];
            int cell = M[i][j];
            if (cell != 0) {
                portals[cell].push_back({i,j});
            }
        }
    }

    auto isvalid = [&](pii v) {
        if (v.x < 0 || v.x >= n || v.y < 0 || v.y >= m) {
            return false;
        }
        return true;
    };
    queue<pii> q;
    vector<vi> d(n, vi(m));
    q.push({0,0});
    seen[0][0]=1;
    while (!q.empty()) {
        pii v = q.front();
        q.pop();
        vector<pii> dirs = {{v.x-1, v.y}, {v.x+1,v.y}, {v.x,v.y-1}, {v.x,v.y+1}};
        int cell = M[v.x][v.y];
        trav(dir, portals[cell]) {
            if (isvalid(dir) && !seen[dir.x][dir.y]) {
                q.push(dir);
                d[dir.x][dir.y] = d[v.x][v.y];
                seen[dir.x][dir.y] = 1;
            }   
        }
        trav(dir, dirs) {
            if (isvalid(dir) && !seen[dir.x][dir.y]) {
                q.push(dir);
                d[dir.x][dir.y] = d[v.x][v.y] + 1;
                seen[dir.x][dir.y] = 1;
            }
        }
    } 

    cout << d[n-1][m-1] << '\n';
    return 0;
}
