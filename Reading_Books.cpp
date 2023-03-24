#include <algorithm>
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
  ll sum = 0;
  for (int i=0;i<n;i++){
    sum += A[i];
  }
  int maxi = *max_element(begin(A),end(A));
  if (maxi > sum-maxi) {
    cout << (ll)2*maxi << "\n";
  } else {
    cout << sum << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
