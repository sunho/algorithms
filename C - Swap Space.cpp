#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  vector<pair<int,int>> B, C;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    if (A[i].first <= A[i].second) {
      B.push_back(A[i]);
    } else {
      C.push_back(A[i]);
    }
  }
  sort(begin(B),end(B),[&](auto a, auto b) {
    return pair<int,int>(a.first, -a.second) < pair<int,int>(b.first, - b.second);
  });
  sort(begin(C),end(C),[&](auto a, auto b) {
    return pair<int,int>(-a.second, a.first) < pair<int,int>(-b.second, b.first);
  });
  ll ans = 0;
  ll cur = 0;
  for (auto [x,y] : B) {
    if (cur < x) {
      ans += x-cur;
      cur = 0;
    } else {
      cur -= x;
    }
    cur += y;
  }
  for (auto [x,y] : C) {
    if (cur < x) {
      ans += x-cur;
      cur = 0;
    } else {
      cur -= x;
    }
    cur += y;
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
