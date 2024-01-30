#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,d,m;
  cin >> n >> d >> m;
  vector<vector<int>> A(n);
  for (int i=0;i<m;i++){
    int a;
    cin >> a;
    --a;
    A[a].push_back(i);
  }
  vector<vector<int>> ans(n);
  auto check = [&](int x) {
    ans.assign(n,{});
    queue<pair<int,int>> q;
    for (int i=0;i<n;i++){
      for (int y : A[i]) {
        q.push({i+d, y});
      }
      int rem = x;
      while (rem > 0 && !q.empty()) {
        auto [dd, j] = q.front();
        q.pop();
        ans[i].push_back(j);
        rem--;
      }
      if (!q.empty() && q.front().first == i) {
        return false;
      }
    }
    return q.empty();
  };
  int ng = 0, ok = 1e9;
  while (ok-ng>1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  check(ok);
  cout << ok << "\n";
  for (int i=0;i<n;i++) {
    for (int x : ans[i]) {
      cout << x + 1 << " ";
    }
    cout << 0 << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
