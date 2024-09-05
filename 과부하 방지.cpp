#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  sort(rbegin(A),rend(A));
  sort(begin(B),end(B));
  auto check = [&](int s) {
    map<int,ll> dist;
    auto subtract = [&](int k) {
      dist[k]--;
      if (dist[k] == 0) {
        dist.erase(k);
      }
    };
    dist[0] = k;
    int ptr = 0;
    for (int i=m-s;i<m;i++){
      if (dist.empty()) {
        return false;
      }
      while (dist.begin()->first < B[i] && ptr < n) {
        int d = dist.begin()->first;
        subtract(d);
        dist[d+1] += A[ptr];
        ptr++;
      }
      if (dist.begin()->first <= B[i]) {
        subtract(dist.begin()->first);
      } else {
        return false;
      }
    }
    return true;
  };
  int ok = -1, ng = m+1;
  while (ng-ok>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
