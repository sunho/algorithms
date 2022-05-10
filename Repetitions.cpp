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
  int cnt = 0;
  int ans = 0;
  char last;
  for(int i=0;i<(int)s.size();i++){
    if (i == 0) {
      last = s[i];
      cnt = 1;
    } else {
      if (s[i] != last) {
        last = s[i];
        cnt = 1;
      } else {
        cnt++;
      }
    }
    ckmax(ans, cnt);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}

