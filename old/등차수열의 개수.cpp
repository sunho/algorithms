#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  const int N = *max_element(begin(A),end(A));
  vector<ll> left(3*N+2);
  vector<ll> right(3*N+2);
  ll ans = 0;
  for (int i=0;i<n;i++){
    right[A[i]+N] ++;
  }
  for (int i=0;i<n;i++){
    right[A[i]+N]--;
    for (int k=1;k<=N;k++){
      ans += right[k+N]*left[(A[i]<<1)-k+N];
    }
    left[A[i]+N]++;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
