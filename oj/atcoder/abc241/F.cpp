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
    int h,w,n;
    cin >> h >> w >> n;
    map<int, set<int>> M1;
    map<int, set<int>> M2;
    pair<int,int> s,t;
    cin >> s.x >> s.y >> t.x >> t.y;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        M1[x].insert(y);
        M2[y].insert(x);
    }

    auto next_pos = [&](int pos0, int pos1, int dir, map<int, set<int>>&M, int& next) {
        if(!M.count(pos0)) {
            return false;
        }
        if (dir == 1) {
            auto it = M[pos0].upper_bound(pos1);
            if (it == M[pos0].end()) {
                return false;
            }
            next = *it-1;
        } else {
            auto it = M[pos0].lower_bound(pos1);
            if (it == M[pos0].begin()) {
                return false;
            }
            --it;
            if (it == M[pos0].end()) {
                return false;
            }
            next = *it+1;
        }
        return true;
    };
    queue<tuple<int, pair<int,int>, int>> q;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>, array<int,4>> dist;
    q.push({0, s, 0});
    while(!q.empty()){
        auto [d, u, ind] = q.front();
        q.pop();
        if (!dist.count(u)) {
            dist[u] = {-1,-1,-1,-1}; 
            dist[u][ind] = d;
        } else if(dist[u][ind] == -1) {
            dist[u][ind] = d;
        } else {
            continue;
        }
        for (int i=0;i<4;i++) {
            auto dir = dirs[i];
            auto v = u;
            if(dir.x == 0) {
                if (next_pos(v.x, v.y, dir.y, M1, v.y)) {
                    q.push({d+1, v, i});
                }
            } else {
                if (next_pos(v.y, v.x, dir.x, M2, v.x)) {
                    q.push({d+1, v, i});
                }
            }
        }
    }
    if (!dist.count(t)) {
        cout << -1 << "\n";
    } else {
        int mini = 1e9;
        for(int i=0;i<4;i++){
            if (dist[t][i] != -1) ckmin(mini, dist[t][i]);
        }
        cout << mini << "\n";
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    solve();

    return 0;
}
