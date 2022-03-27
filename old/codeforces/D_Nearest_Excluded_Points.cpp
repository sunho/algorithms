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

const int N = 1e6;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    map<pii, int> P;
    rep(i, 0, n) {
        pii p;
        cin >> p.x >> p.y;
        P[p] = i;
    }


    set<pii> next;
    trav(x, P) {
        auto [v, i] = x;
        vector<pii> adj = {{v.x+1, v.y}, {v.x-1, v.y}, {v.x, v.y+1}, {v.x, v.y-1}};
        trav(p, adj) {
            if (p.x < -N || p.x > N || p.y < -N || p.y > N) continue;
            if (P.count(p)) continue;
            next.insert(p);
        }
    }

    vector<int> d(n);
    d.assign(n, 1e9);
    vector<pii> ans(n);

    queue<pii> q;
    set<pii> seen;
    trav(x, next) q.push(x);
    while (!q.empty()) {
        pii v = q.front();
        q.pop();

        vector<pii> adj = {{v.x+1, v.y}, {v.x-1, v.y}, {v.x, v.y+1}, {v.x, v.y-1}};
        trav(p, adj) {
            if (p.x < -N || p.x > N || p.y < -N || p.y > N) continue;
            if (!P.count(p)) continue;
            if (seen.count(p)) continue;
            seen.insert(p);
            q.push(p);
            if (P.count(v)) {
                if (ckmin(d[P[p]], d[P[v]] + 1)) {
                    ans[P[p]] = ans[P[v]];
                }
            } else {
                d[P[p]] = 1;
                ans[P[p]] = v;
            }
        }
    }

    rep(i,0,n) {
        cout << ans[i].x << " " << ans[i].y << endl;
    }

    return 0;
}
