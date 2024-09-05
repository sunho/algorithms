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
  sort(begin(A),end(A),[](ll a, ll b) {
    int ca = 0, cb = 0;
    while (a % 3 == 0) {
      ca++;
      a /= 3;
    }
    while (b % 3 == 0) {
      cb ++;
      b /= 3;
    }
    return pair<ll,ll>(-ca,a) < pair<ll,ll>(-cb,b);
  });
  for (ll a : A) {
    cout << a << " ";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
