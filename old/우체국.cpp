#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int,2>> A(n);
  ll sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i][0] >> A[i][1];
    sum += A[i][1];
  }
  sort(begin(A),end(A));
  ll cur = 0;
  for (int i=0;i<n;i++){
    cur += A[i][1];
    if (2*cur >= sum) {
      cout << A[i][0] << "\n";
      return;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
