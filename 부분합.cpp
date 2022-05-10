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
  ll S;
  cin >> n >> S;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  const int inf = 1e9;
  int ans = inf;
  ll sum = 0;
  for(int i=0,p=0;i<n;i++){
    while(p<n && sum < S) {
      sum += A[p];
      p++;
    }
    while(p > 0 && sum - A[p-1] >= S) {
      sum -= A[p-1];
      p--;
    }
    if (sum >= S) ans = min(ans, p-i);
    if (i < p) {
      sum -= A[i];
    }
  }
  if (ans == inf) cout << 0 << "\n";
  else cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
