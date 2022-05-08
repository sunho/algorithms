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
  int scc;

  DSU(int N) { 
    e.assign(N, 1);
    p.assign(N, 0);
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
    e[x] += e[y];
    p[y] = x;
    scc--;
    return true;
	}
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  DSU dsu(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    dsu.unite(a,b);
  }
  vector<int> id(n);
  vector<bool> vis(n);
  vector<bool> chosen(n);
  int comps = 0;
  iota(all(id), 0);
  sort(all(id), [&](int a, int b) {
    return A[a] < A[b];
  });
  ll ans = 0;
  for(int i=0;i<n;i++){
    int u = id[i];
    int g = dsu.get(u);
    if (!vis[g]) {
      vis[g] = true;
      comps++;
      chosen[u] = true;
      ans += A[u];
    }
  }
  if (comps == 1) {
    cout << 0 << "\n";
    return;
  }
  if (2*(comps-1) > n) {
    cout << "Impossible" << "\n";
    return;
  }
  comps-=2;
  for(int i=0;i<n&&comps>0;i++){
    int u = id[i];
    if (!chosen[u]) {
      chosen[u] = true;
      comps--;
      ans += A[u];
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
