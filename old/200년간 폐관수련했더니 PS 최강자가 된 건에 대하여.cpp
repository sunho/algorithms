#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<array<int,2>> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i][0] >> A[i][1];
  }
  ll sum = 0;
  pair<int,int> mx = {0,-1};
  int take = -1;
  for (int i=0;i<n;i++){
    mx = max(mx, {A[i][1],i});
    if (take == -1 && sum > A[i][0]) {
      take = mx.second;
    }
    sum += A[i][1];
  }
  sum = 0; 
  bool ok = true;
  for (int i=0;i<n;i++) {
    if (i != take && sum > A[i][0]) {
      ok = false;
    }
    if (i != take) {
      sum += A[i][1];
    }
  }
  if (ok) {
    cout << "Kkeo-eok";
    return;
  }
  bool flag = false;
  sum = 0;
  ok = true;
  for (int i=0;i<n;i++) {
    if (sum > A[i][0]) {
      if (flag) {
        ok = false;
      } else {
        sum -= A[i][1];
        flag = true;
      }
    }
    sum += A[i][1];
  }
  if (ok) {
    cout << "Kkeo-eok";
    return;
  }
  cout << "Zzz";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
