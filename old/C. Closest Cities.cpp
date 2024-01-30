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
  vector<ll> pf1(n);
  for (int i=0;i<n-1;i++){
    if (i == 0 || (A[i+1] - A[i] < A[i] - A[i-1])) {
      pf1[i+1] = pf1[i] + 1;
    } else {
      pf1[i+1] = pf1[i] + A[i+1] - A[i];
    }
  }
  reverse(begin(A),end(A));
  vector<ll> pf2(n);
  for (int i=0;i<n-1;i++){
    if (i == 0 || (abs(A[i+1] - A[i]) < abs(A[i] - A[i-1]))) {
      pf2[i+1] = pf2[i] + 1;
    } else {
      pf2[i+1] = pf2[i] + abs(A[i+1] - A[i]);
    }
  }
  int m;
  cin >> m;
  while (m--) {
    int s,t;
    cin >> s >> t;
    --s,--t;
    if (s == t) {
      cout << 0 << "\n";
    } else if (s < t) {
      cout << pf1[t] - pf1[s] << "\n";
    } else {
      s = n-1-s;
      t = n-1-t;
      cout << pf2[t] - pf2[s] << "\n";
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
