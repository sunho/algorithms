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
 int nn = n/2*2;
 pair<int,int> ans = {0,0};
 for (int t : {0,1}) {
    int alice = 0;
    for(int i=t; i<t+nn;i++) {
      alice += (int)(s[i]-'a')+1;
    }
    int b = 0;
    if (n%2 == 1) {
      if (t == 0) {
        b = s.back()-'a'+1;
      } else {
        b = s[0]-'a'+1;
      }
    }
    ans = max(ans, {alice, b});
  }
  int diff = abs(ans.first - ans.second);
  if (ans.first > ans.second) {
    cout << "Alice" << " " << diff << "\n";
  } else {
    cout << "Bob" << " " << diff << "\n";
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
