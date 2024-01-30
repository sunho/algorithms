#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> cur(k, -1);
  for (int i=0;i<n;i++){
    int a = A[i];
    pair<int,int> mx = {-1,-1};
    for (int j=0;j<k;j++){
      if (cur[j] < a) {
        mx = max(mx, {cur[j],j});
      }
    }
    if (mx.first == -1) {
      int found = -1;
      for (int j=0;j<k;j++){
        if (cur[j] == -1) {
          found = j;
        }
      }
      if (found == -1) {
        cout << "NO";
        return;
      }
      cur[found] = a;
    } else {
      cur[mx.second] = a;
    }
  }
  cout << "YES";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
