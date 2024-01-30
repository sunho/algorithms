#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e9;

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
  int n, m;
  cin >> n >> m;
  m*=2;
  m--;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  slide_window window;
  for (int i=0;i<m;i++){
    window.add(A[i]);
  }
  cout << window.query() << " ";
  for (int i=0;i<n-m;i++){
    window.remove();
    window.add(A[i+m]);
    cout << window.query() << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
