#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<pair<pair<int,int>, int>> V(n);
  for (int i=0;i<n;i++){
    int x,y,p;
    cin >> x >> y >> p;
    V[i] = {{x,y}, p};
  }
  auto f = [&](ll s) {
    for (int i=0;i<n;i++) { 
      queue<int> q;
      vector<bool> visited(n);
      visited[i] = true;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v=0;v<n;v++){
          if (v == u) continue;
          auto [x1,y1] = V[u].first;
          auto [x2,y2] = V[v].first;
          int p1 = V[u].second;
          if (visited[v]) continue;
          if ((lll)p1*s < (lll)abs(x1-x2) + abs(y1-y2)) {
            continue;
          }
          visited[v]=true;
          q.push(v);
        }
      }
      bool ok = true;
      for (int i=0;i<n;i++){
        if (!visited[i]) {
          ok = false;
        }
      }
      if (ok) return true;
    }
    return false;
  };
  
  ll ng = -1, ok = 2e10+3;
  while (ok-ng > 1) {
    ll mid = (ok + ng) / 2; 
    if (f(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
