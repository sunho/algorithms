#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  set<ll> S;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    --A[i];
    S.insert(A[i]);
  }
  ll cur = 0;
  int ptr = 0;
  while(k--) {
    while (ptr < n) {
      int d = upper_bound(begin(A), end(A), cur + ptr) - begin(A);
      if (d == ptr && !S.count(cur + ptr)) {
        break; 
      } else {
        ptr++;
      }
    }
    cur += ptr;
  }
  cout << cur + 1 << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();   
  }
}
