#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  sort(begin(A),end(A));
  vector<ll> diff;
  for (int i=1;i<n;i++){
    if (A[i] - A[i-1] > x) {
      diff.push_back(A[i]-A[i-1]);
    }
  }
  sort(begin(diff),end(diff));
  int ans = diff.size() + 1;
  for (ll d : diff) {
    ll need = (d - x + x - 1) / x;
    if (k >= need) {
      ans --;
      k -= need;
    }
  }
  cout << ans << "\n";
}
