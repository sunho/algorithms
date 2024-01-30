#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A),end(A));
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  ll g = 0;
  for (int i=0;i<n-1;i++){
    g = gcd(g,A[i+1]-A[i]);
  }
  ll mn = *min_element(begin(A),end(A));
  if (mn < 0) {
    for (int i=0;i<n;i++) {
      A[i] -= mn;
    }
  }
  vector<ll> B(n);
  set<ll> S;
  for (int i=0;i<n;i++){
    B[i] = A[i] / g;
    S.insert(B[i]);
  }
  ll mx = *max_element(begin(B),end(B));
  ll mn_left = -1;
  for (ll z=mx;z>=0;z--){
    if (!S.count(z)) {
      mn_left = z;
      break;
    }
  }
  auto calc = [&](ll x) {
    B.push_back(x);
    ll ans = 0;
    ll mx = *max_element(begin(B),end(B));
    for (int i=0;i<B.size();i++){
      ans += mx - B[i];
    }
    B.pop_back(); 
    return ans;
  };
  cout << min(calc(mn_left), calc(mx+1)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
