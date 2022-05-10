#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n,m;
  cin >> n >> m;
  int x,y;
  cin >> x >> y;
  --x,--y;
  array<pair<int,int>, 4> cands = {{{x-1,y},{x+1,y},{x,y-1},{x,y+1}}};
  int cnt = 0;
  for(auto cand : cands) {
    if (cand.first < 0 || cand.first >= n || cand.second < 0 || cand.second >= m) continue;
    cnt++;
  }
  cout << cnt << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
