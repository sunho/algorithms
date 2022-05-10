#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int n;
    cin >> n;
    pair<int,int> A,B;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    A.x--,A.y--,B.x--,B.y--;
    vector<vector<char>> M(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> M[i][j];
        }
    }
    
    vector<vector<int>> d(n, vector<int>(n,-1));
    vector<vector<vector<bool>>> dvisited(4, vector<vector<bool>>(n, vector<bool>(n, false)));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int,int>> q;
    auto is_valid = [&](pair<int,int> v) {
        return v.x >= 0 && v.x < n && v.y >= 0 && v.y < n && M[v.x][v.y] == '.';
    };
    q.push(A);
    d[A.x][A.y] = 0;
    visited[A.x][A.y] = true;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        vector<pair<int,int>> dirs = {{1,1},{-1,1}, {-1,-1}, {1,-1}};
        for (int i=0;i<dirs.size();i++) {
            auto dir = dirs[i];
            auto v = u;
            v.x += dir.x, v.y += dir.y;
            while (is_valid(v)) {
                if (dvisited[i][v.x][v.y]) break;
                if (!visited[v.x][v.y]) {
                    d[v.x][v.y] = d[u.x][u.y] + 1;
                    visited[v.x][v.y] = true;
                    q.push(v);
                }
                dvisited[i][v.x][v.y] = true;
                v.x += dir.x, v.y+= dir.y;
            }
        }
    }
    cout << d[B.x][B.y];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
