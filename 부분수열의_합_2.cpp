#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, s;
  cin >> n >> s;
  map<int, ll> left;
  map<int, ll> right;
  ll ans = 0;
  vector<int> A(n);
  for(int i=0;i<n;i++) cin >> A[i];
  int m = n/2;
  int m2 = n - m;
  for(int i=1;i<(1<<m);i++){
    int sum = 0;
    for(int j=0;j<m;j++){
      if (i & (1<<j)) {
        sum += A[j];
      }
    }
    left[sum]++;
    if (sum == s) ans++;
  }
  for(int i=1;i<(1<<m2);i++){
    int sum = 0;
    for(int j=0;j<m2;j++){
      if (i & (1<<j)) {
        sum += A[m+j];
      }
    }
    right[sum]++;
    if (sum == s) ans++;
  }
  for(auto [a, cnt] : left) {
    if (right.count(s-a)) {
      ans += cnt * right[s-a];
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
