#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

struct DSU {
  vector<int> e;
  vector<int> p;
  vector<vector<int>> m;
  int scc;

  DSU(int N) { 
    e.assign(N, 1);
    p.assign(N, 0);
    m.assign(N,{});
    for(int i = 0; i < N; i++) p[i] = i;
    scc = N;
  }

  // get representive component (uses path compression)
  int get(int x) { 
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
  }
  bool same_set(int a, int b) { return get(a) == get(b); }
  int size(int x) { return e[get(x)]; }
  bool unite(int x, int y) {  // union by size
    x = get(x), y = get(y);
    if (x == y) return false;
    if (e[x] < e[y]) 
      swap(x, y);
    m[x].insert(m[x].end(), all(m[y]));
    m[y].clear();
    e[x] += e[y];
    p[y] = x;
    scc--;
    return true;
	}
};

void solve() {
  int n,m;
  cin >> n >> m;

  DSU dsu(n);
  vector<int> D(n);
  
  for(int i=0;i<n;i++) cin >> D[i];
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    --a,--b;
    D[a]--;
    D[b]--;
    dsu.unite(a,b);
  }
  bool ok = true;
  set<pair<int,int>> todo;
  for(int i=0;i<n;i++){
    if (D[i] > 0) {
      int k = D[i];
      while(k--){
        dsu.m[dsu.get(i)].push_back(i);
      }
    } 
    if (D[i] < 0) {
      ok = false;
    }
  }
  for(int i=0;i<n;i++){
    if (dsu.m[i].size() > 0) {
      todo.insert({dsu.m[i].size(),i});
    }
  }
  vector<pair<int,int>> ans;
  if (!todo.empty()) {
    while(todo.size()>1) {
      auto [_,p] = *todo.begin();
      auto [__,q] = *(--todo.end());
      int u = dsu.m[p].back();
      int v = dsu.m[q].back();
      ans.emplace_back(u,v);
      dsu.m[p].pop_back();
      dsu.m[q].pop_back();
      todo.erase(todo.begin());
      todo.erase(--todo.end());
      dsu.unite(u,v);
      int np = dsu.get(u);
      todo.insert({dsu.m[np].size(), np});
    }
    auto [_,p] = *todo.begin();
    if (dsu.m[p].size() != 0 || (int)ans.size() != n-m-1 || dsu.scc != 1) ok = false;
  } else {
    if (m != n-1 || dsu.scc != 1) ok = false;
  }
  if (!ok) {
    cout << -1 << "\n";
  } else {
    for(auto [u,v] : ans) {
      cout << u + 1 << " " << v + 1 << "\n";
    }
  }

}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
