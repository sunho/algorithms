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
  string s;
  cin >> s;
  bool ans = true;
  char last_c = s[0];
  int cnt = 1;
  for(int i=1;i<s.size();i++) {
    if (s[i] == last_c) {
      cnt++;
    } else {
      if (cnt == 1) {
        ans = false;
      }
      last_c = s[i];
      cnt = 1;
    }
  }
  if (cnt == 1) ans = false;
  if(ans) cout << "YES" << "\n";
  else cout << "NO" << "\n";
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
