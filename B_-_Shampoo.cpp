#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int v;
  array<int, 3> a{};
  cin >> v;
  for(int i=0;i<3;i++) cin >> a[i];
  int idx = 0;
  while (v >= 0) {
    v -= a[idx];
    idx++;
    idx %= 3;
  }
  array<string, 3> names = {"F","M","T"};
  cout << names[(idx-1+3)%3] << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
