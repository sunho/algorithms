#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
  }
  // (x1,y1), (x2,y2)
  // (a-x1)^2 + (b-y1)^2 = (a-x2)^2 + (b-y2)^2
  // -2ax1 -2by1 + 2ax2 + 2by2  
  // + x1^2 + y1^2 - x2^2 - y2^2 = 0
  // 
  pair<ld, ld>
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
