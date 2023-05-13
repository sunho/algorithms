#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i],--A[i];
  vector<int> inv(n);
  ll ans = 0;
  int p = 0;
  for (int i=0;i<n;i++){
    if (A[i] == i) {
      p++;
    } else if (A[A[i]] == i) {
      ans++;
    }
  }
  ans/=2;
  ans += (ll)p*(p-1)/2;
  
  cout << ans << "\n";
}
