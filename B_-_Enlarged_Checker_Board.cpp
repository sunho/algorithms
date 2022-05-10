#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  for(int i=0;i<n;i++){
    for(int x=0;x<a;x++) {
      for(int j=0;j<n;j++){
        int c = (i^j)&1;
        for (int y=0;y<b;y++){
          if (c) cout << "#";
          else cout << ".";
        }
      }
      cout << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
  