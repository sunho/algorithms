#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// disjoint subset union
struct DSU {
  vector<int> e;
  vector<int> p;
  vector<char> elec;
  int scc;
  int el_num;

  DSU(int N) { 
    e.assign(N, 1);
    p.assign(N, 0);
    elec.assign(N, false);
    for(int i = 0; i < N; i++) p[i] = i;
    scc = N;
    el_num = 0;
  }

  // get representive component (uses path compression)
  int get(int x) { 
    if (x == p[x]) return x;
    int np = get(p[x]);
    elec[np] |= elec[x];
    return p[x] = np;
  }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] < e[y]) 
      swap(x, y);
    if (elec[x] && !elec[y]) {
      el_num += e[y];
    }
    if (!elec[x] && elec[y]) {
      el_num += e[x];
    }
    elec[x] |= elec[y];
    e[x] += e[y];
    p[y] = x;
    scc--;
    return true;
  }
};

void solve() {
  int n,m,k;
  cin >> n >> m >> k;
  DSU dsu(n+m);
  vector<pair<int,int>> edges;
  edges.reserve(k);
  for(int i=n;i<n+m;i++){
    dsu.elec[i] = true;
  }
  for(int i=0;i<k;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    edges.push_back({a,b});
  }
  int kk;
  cin >> kk;
  vector<int> qu;
  qu.reserve(kk);
  vector<int> disabled(k);
  for(int i=0;i<kk;i++){
    int x;
    cin >> x;
    --x;
    disabled[x] = true;
    qu.push_back(x);
  }
  for(int i=0;i<k;i++){
    if (!disabled[i]) {
      dsu.unite(edges[i].first, edges[i].second);
    }
  }
  vector<int> ans(kk);
  for(int i=0;i<kk;i++){
    int x = qu.back();
    qu.pop_back();
    ans[kk-i-1] = dsu.el_num;
    dsu.unite(edges[x].first, edges[x].second);
  }
  for(int i=0;i<kk;i++){
    cout << ans[i] << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
