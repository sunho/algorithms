#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> S(n);
  for (int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  for (int i=0;i<n;i++) cin >> S[i];
  const int inf = 1e9+1;
  vector<int> color(n);
  long long ans = 0;
  auto dfs = [&](int u, auto&& self) -> void {
    color[u] = 1;
    if (color[p[u]] == 0) {
      self(p[u], self);
    } else if (color[p[u]] == 1) {
      int v = u;
      int mini = S[v];
      v = p[v];
      while(v != u) {
        mini = min(S[v], mini);
        v = p[v];
      }
      ans += mini;
    }
    color[u] = 2;
  };
  for (int i=0;i<n;i++){
    if (!color[i]) {
      dfs(i, dfs);
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
