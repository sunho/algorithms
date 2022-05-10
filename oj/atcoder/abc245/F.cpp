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
    vector<vi> g(n);
    vi deg(n);
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        g[b].push_back(a);
        deg[a]++;
    }

    int cnt = n;

    queue<int> q;
    rep(i,0,n) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt--;
        trav(v, g[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
