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
  map<int,int> L, R;
  for (int i=0;i<n;i++){
    R[A[i]]++;
  }
  vector<int> cnt(2);
  for (int i=0;i<n-1;i++){
    R[A[i]]--;
    if (R[A[i]]==0) {
      R.erase(A[i]);
    }
    L[A[i]]++;
    int a = (--L.end())->first, b = (--R.end())->first;
    if (a > b) {
      cnt[0]++;
    } else if (a < b) {
      cnt[1]++;
    }
  }
  if (cnt[0] > cnt[1]) {
    cout << "R";
  } else if (cnt[0] < cnt[1]) {
    cout << "B";
  } else {
    cout << "X";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
