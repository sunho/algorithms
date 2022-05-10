#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


void solve() {
  int t;
  int n,m;
  cin >> t;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  cin >> m;
  vector<int> B(m);
  for(int i=0;i<m;i++) cin >> B[i];
  hash_table<ll, int> left;
  hash_table<ll, int> right;
  for(int i=0;i<n;i++){
    ll sum = 0;
    for(int j=i;j<n;j++){
      sum += A[j];
      left[sum]++;
    }
  }
  for(int i=0;i<m;i++){
    ll sum = 0;
    for(int j=i;j<m;j++){
      sum += B[j];
      right[sum]++;
    }
  }
  ll ans = 0;
  for(auto [a, cnt] : left) {
    if (right.find(t-a) != right.end()) {
      ans += (ll)cnt * right[t-a];
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
