#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m,p;
  cin >> n >> m >> p;
  vector<vector<pair<int,int>>> g(n);
  for(int i=0;i<m;i++){
    int a,b,w;
    cin >> a >> b >> w;
    --a,--b;
    g[a].push_back({b,-(w-p)});
  }
  const ll inf = 1e18;
  vector<ll> d(n, inf);
  vector<int> cnt(n, 0);
  vector<bool> inqueue(n, false);
  vector<bool> negcyc(n);
  queue<int> q;

  d[0] = 0;
  q.push(0);
  inqueue[0] = true;
  cnt[0]++;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inqueue[u] = false;

    for (auto [v, w] : g[u]) {
      if (negcyc[u]) {
        if (!negcyc[v] && !inqueue[v]) {
          inqueue[v] = true;
          q.push(v);
        }
        negcyc[v] = true;
      } else if (!negcyc[v] && d[u] + (ll)w < d[v]) {
        d[v] = d[u] + (ll)w;
        if (!inqueue[v]) {
          cnt[v]++;
          if (cnt[v] <= n) {
            inqueue[v] = true;
            q.push(v);
          } else {
            inqueue[v] = true;
            negcyc[v] = true;
            q.push(v);
          }
        }
      } 
    }
  }
  
  if (negcyc[n-1]) {
    cout << -1 << "\n";
    return;
  }
  cout << max(-d[n-1],0ll) << "\n"; 

}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
