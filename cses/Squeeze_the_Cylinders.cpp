#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int m = 0;
  vector<long double> cur;

  auto dist = [&](pair<long double, long double> a, pair<long double,long double> b) -> long double {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
  };
  auto f = [&](long double x, int r) {
    for (int i=0;i<m;i++){
      if (dist({cur[i], A[i]}, {x,r}) < (ll)(r+A[i])*(r+A[i])){
        return false;
      }
    }
    if (!cur.empty() && cur.back() > x) return false;
    return x >= r;
  };
  cur.push_back(A[0]);
  m++;
  long double ans = cur.back()*2;
  for (int i=1;i<n;i++){
    long double ng = 0.0, ok = 1e9;
    int t = 128;
    while (t--) {
      long double mid = (ok+ng)/2;
      if (f(mid, A[i])) ok = mid;
      else ng = mid;
    }
    cur.push_back(ok);
    m++;
    ans = max(ans, ok+A[i]);
  }
  cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
