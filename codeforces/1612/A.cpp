#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  pair<int,int> B;
  cin >> B.x >> B.y;
  if ((B.x + B.y) % 2 == 1) {
    cout << "-1 -1" << "\n";
    return;
  }
  int d = (B.x + B.y) / 2;
  auto check = [&](pair<int,int> C) {
    return abs(C.x - B.x) + abs(C.y - B.y) == d && (C.x+C.y) == d;
  };
  for (int i=0;i<=d;i++) {
    for(int j=0;j<=d-i;j++) {
      if (check({i,j})) {
        cout << i << " " << j << "\n";
        return;
      }
    }
  }
  cout << "-1 -1" << "\n";
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
