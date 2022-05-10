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
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  if (n <= 3) {
    cout << "NO SOLUTION" << "\n";
    return;
  }
  if (n == 4) {
    cout << "2 4 1 3" << "\n";
    return;
  }
  for(int i=2;i<=n;i+=2) {
    cout << i << " ";
  }
  for(int i=1;i<=n;i+=2) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
