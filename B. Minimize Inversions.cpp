#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i].first;
  }
  for (int i=0;i<n;i++){
    cin >> A[i].second;
  }
  ranges::sort(A,[&](auto a, auto b) {
    return a.first+a.second < b.first+b.second;
  });
  for (int i=0;i<n;i++){
    cout << A[i].first << " ";
  }
  cout << "\n";
  for (int i=0;i<n;i++){
    cout << A[i].second << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
