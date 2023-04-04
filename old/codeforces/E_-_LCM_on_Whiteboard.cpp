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
  set<int> dup;
  map<int, int> cur;
  map<int, int> mmx;
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      int p, r;
      cin >> p >> r;
      if (r == mmx[p]) {
        dup.insert(p);
      } else if (r > mmx[p]) {
        mmx[p] = r;
        cur[p] = i;
        dup.erase(p);
      }
    }
  }
  set<int> used;
  for (auto [p, r] : mmx) {
    if (!dup.count(p)) {
      used.insert(cur[p]);
    }
  }
  cout << min((int)used.size()+1, n) << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
