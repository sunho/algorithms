#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  string t;
  set<char> S;
  for(int i=0;i<n;i++){
    if (S.count(s[i])) {
      break;
    }
    t.push_back(s[i]);
    S.insert(s[i]);
  }
  bool ans = true;
  int idx = 0;
  int m = (int)t.size();
  for(int i=0;i<n;i++){
    if (s[i] != t[idx]) {
      ans = false;
    }
    idx++;
    idx %= m;
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
  while (t--) {
    solve();
  }

  return 0;
}
