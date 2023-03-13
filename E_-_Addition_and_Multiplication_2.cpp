#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  array<int, 9> C;
  for (int i=0;i<9;i++){
    cin >> C[i];
  }
  pair<int,int> mm;
  for (int i=0;i<9;i++){
    ckmax(mm, {n/C[i], i});
  }
  int max_cnt = mm.first;
  int mi = mm.second;
  int cost = n - max_cnt * C[mi];
  string ans;
  for (int i = 8; i >= 0; i--) {
    while (cost + (-C[i] + C[mi]) >= 0) {
      cost += -C[i] + C[mi];
      ans.push_back('1'+i);
    }
  }
  cout << ans;
  for (int i=0;i<max_cnt - ans.size();i++){
    cout << (char)('1' + mi);
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
