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
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  vector<ll> ans(n+2);
  array<ll,3> crit{};
  array<ll,3> critf{};
  for(int i=0;i<3;i++) {
    for(int j=i;j<n-1;j+=3) {
      crit[i] = crit[i]-A[j+1]+A[j];
      critf[i] = max(critf[i], crit[i]);
    }
  }
  if (critf[0] + critf[1] + critf[2] > A[0]) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
  ans[0] = critf[0];
  ans[1] = critf[1];
  ans[2] = A[0] - critf[0] - critf[1];
  for(int i=0;i<n-1;i++) {
    ans[i+3] = A[i+1]-A[i] + ans[i];
  }
  for(int i=0;i<n+2;i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
