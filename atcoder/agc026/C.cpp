#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string st;
  st = s.substr(n);
  bool is_palin = false;
  {
    string t = s.substr(0,n);
    reverse(all(t));
    if (t == st) {
      is_palin = true;
    }
  }
  const int N = 19;
  ll ans = 0;
  for(int mask = 0; mask <(1<<n); mask++){
    string a,b;
    for(int i=0;i<n;i++){
      if (mask >> i & 1) {
        a.push_back(s[i]);
      } else {
        b.push_back(s[i]);
      }
    }
    reverse(all(a));
    reverse(all(b));
    int k = (int)a.size();
    int m = (int)b.size();
    if (k == 0 || m == 0) {
      if (is_palin) {
        ans++;
      }
      continue;
    }
    array<array<ll, N>, N> dp{};
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
      array<array<ll, N>, N> next{};
      for(int j=0;j<=k;j++){
        for(int z=0;z<=m;z++){
          next[j][z] += dp[j][z];
          if (j < k && st[i] == a[j]) next[j+1][z] += dp[j][z];
          if (z < m && st[i] == b[z]) next[j][z+1] += dp[j][z];
        }
      }
      dp = next;
    }
    ans += dp[k][m];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
