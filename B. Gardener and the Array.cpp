#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> A;
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    vector<int> S(m);
    for (int j=0;j<m;j++) {
      cin >> S[j];
    }
    A.push_back(S);
  }
  const int N = (int)2e5 + 1;
  map<int,int> cnt;
  for (int i=0;i<n;i++){
    for (int j : A[i]) {
      cnt[j] ++;
    }
  }
  for (int i=0;i<n;i++){
    bool yes = true;
    for (int j : A[i]) {
      if (cnt[j] == 1) yes = false;
    }
    if (yes) {
      cout << "Yes" << "\n";
      return;
    }
  }
  cout << "No" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
