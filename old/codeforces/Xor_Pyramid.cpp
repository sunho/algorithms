#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ilog2(ll n) {
  int cnt = 0;
  while (n) cnt++, n /= 2;
  return cnt;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];

  int ans = 0;

  auto f = [&](auto self, int i, int n) -> void {
    if (n == 0) {
      return;
    }
    if (n == 1) {
      ans ^= A[i];
      return; 
    }
    int pw = 1 << (ilog2(n-1)-1);
    self(self, i, n - pw);
    self(self, i + pw, n - pw);
  };
  f(f,0,n);
  cout << ans << "\n";
}
