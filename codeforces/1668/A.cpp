#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  vector<int> p(2);
  for(int i=0;i<2;i++) {
    cin >> p[i];
  }
  sort(all(p));
  if (p[0] == 1) {
    if (p[1] == 1) {
      cout << 0 << "\n";
      return;
    }
    if (p[1] == 2) {
      cout << 1 << "\n";
      return;
    }
    if (p[1] > 2) {
      cout << -1 << "\n";
      return;
    }
  }
  int k = min(p[0],p[1]);
  int c = k-1 + k-1;
  int d = p[1]-p[0];
  if (d%2 == 0) {
    c+=d*2;
  } else {
    c+=d*2-1;
  }
  cout << c << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
