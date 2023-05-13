#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, y0;
  cin >> n >> y0;
  const int N = 2e5 + 1000;
  vector<int> pos;
  vector<int> X(n), Y(n);
  for (int i=0;i<n;i++){
    cin >> X[i] >> Y[i];
  }
  vector<vector<int>> pts(N+10);
  vector<int> cnt(2*N);
  ll cur = 0;
  for (int i=0;i<n;i++){
    int d = abs(Y[i] - y0);
    pts[X[i]].push_back(d);
    cnt[X[i]+d+N]++;
    if (cnt[X[i]+d+N] == 1) {
      cur++;
    }
    if (cnt[X[i]+d+N] == 2) {
      cur--;
    }
    pos.push_back(X[i]);
    pos.push_back(X[i]+1);
  }
  sort(begin(pos), end(pos));
  pos.resize(unique(begin(pos), end(pos))- begin(pos));

  ll mx = -1, mn = 1e18+1;
  mx = max(mx, cur);
  mn = min(mn, cur);
  for (int x0 : pos){
    for (int d : pts[x0-1]) {
      cur--;
      cnt[x0-1-d+N]++;
      if (cnt[x0-1-d+N] == 1) {
        cur++;
      }
      if (cnt[x0-1-d+N] == 2) {
        cur--;
      }
    }
    for (int d : pts[x0]) {
      if (cnt[x0+d+N] == 2) {
        cur++;
      }
      if (cnt[x0+d+N] == 1) {
        cur--;
      }
      cnt[x0+d+N]--;
      cur++;
    }
    mx = max(mx, cur);
    mn = min(cur, mn);
  }
  cout << mn << " " << mx << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;

  int i = 0;

  while(t--) {
    solve(); 
    if (i++ > 100)
      break;
  }
}
