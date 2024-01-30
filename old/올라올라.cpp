#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int inf = 1e9;

struct slide_window {
  deque<pair<int,int>> q;
  int l = 0, r = 0;
  slide_window() = default;
  void add(int x) {
    while (!q.empty() && q.back().first <= x) {
      q.pop_back();
    }
    q.push_back({x,r});
    ++r;
  }
  void remove() {
    if (q.front().second == l) q.pop_front();
    ++l;
  }
  int query() {
    return q.empty() ? -inf : q.front().first;
  }
  size_t size() { return r-l; }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  auto check = [&](int k) {
    slide_window win;
    for (int i=0;i<k;i++){
      win.add(A[i]);
    }
    vector<int> B;
    B.push_back(win.query());
    for (int i=k;i<n;i++){
      win.remove();
      win.add(A[i]);
      B.push_back(win.query());
    }
    return is_sorted(begin(B),end(B));
  };
  int ng = 0, ok = n+1;
  while (ok - ng > 1) {
    int mid = (ok+ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok  << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
