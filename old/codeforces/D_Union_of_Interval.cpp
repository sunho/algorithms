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
  vector<pair<int,int>> Rs(n);
  for (int i=0;i<n;i++) {
    cin >> Rs[i].first >> Rs[i].second;
  }
  sort(all(Rs));
  int i=0;
  while (i < n) {
    int start = Rs[i].first;
    int cur = Rs[i].second;
    for (;i<n;i++){
      if (Rs[i].first > cur) {
        break;
      }
      cur = max(cur, Rs[i].second);
    }
    cout << start << " " << cur << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
