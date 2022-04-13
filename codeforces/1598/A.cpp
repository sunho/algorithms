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
  int n;
  cin >> n;
  vector<vector<int>> M(2, vector<int>(n));
  for(int i=0;i<2;i++){
    for(int j=0;j<n;j++){
      char c;
      cin >> c;
      M[i][j] = c == '1' ? 1 : 0;
    }
  }
  bool ans = true;
  for(int i=0;i<n;i++){
    if (M[0][i] == 1 && M[1][i] == 1) {
      ans = false;
    }
  }
  if (ans) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
