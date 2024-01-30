#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> A(m);
  vector<vector<int>> inv(n);
  for (int i=0;i<m;i++){
    cin >> A[i];
    A[i]--;
    inv[A[i]].push_back(i);
  }
  ll cur = 0;
  for (int i=0;i<m-1;i++){
    cur += abs(A[i+1]-A[i]);
  }
  ll ans = cur;
  int ptr = 0;
  for (int i=0;i<n;i++){
    for (int j : inv[n-i-1]) {
      if (j-1 >= 0) {
        cur -= abs((A[j] + ptr) % n - (A[j-1]+ptr) % n);
        cur += abs((A[j] + ptr + 1) % n - (A[j-1]+ptr + 1) % n);
      }
      if (j+1 < m) {
        cur -= abs((A[j+1] + ptr) % n - (A[j]+ptr) % n);
        cur += abs((A[j+1] + ptr + 1) % n - (A[j]+ptr + 1) % n);
      }
    }
    ptr++;
    ans = min(ans, cur);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
