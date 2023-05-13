#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,a;
  cin >> n >> a;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> S(n);
  for (int i=0;i<n;i++){
    S[i] = A[(i-1+n)%n] + A[i] + A[(i+1)%n];
  }
  sort(rbegin(S), rend(S));
  int ans = 3*n;
  for (int i=0;i<a;i++){
    ans -= (3-S[i]);
  }
  cout << ans << "\n";
}
