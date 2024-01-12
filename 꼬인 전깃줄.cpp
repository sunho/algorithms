#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int j = lower_bound(begin(lis), end(lis), A[i]) - lis.begin();
    if (j == lis.size()) {
      lis.push_back(A[i]);
    } else {
      lis[j] = A[i];
    }
  }
  cout << n - lis.size() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
