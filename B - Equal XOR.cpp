#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(2*n);
  for (int i=0;i<2*n;i++)
    cin >> A[i];
  map<int,int> cnt;
  vector<int> C,L,R;
  for (int i=0;i<n;i++){
    cnt[A[i]]++;
  }
  for (int i=1;i<=n;i++){
    if (cnt[i] == 2) {
      L.push_back(i);
    } else if (cnt[i] == 0) {
      R.push_back(i);
    } else {
      C.push_back(i);
    }
  }
  vector<int> ans1, ans2;
  for (int i=0;i<k;i++){
    if (L.empty()) {
      ans1.push_back(C.back());
      ans2.push_back(C.back());
      C.pop_back();
      ans1.push_back(C.back());
      ans2.push_back(C.back());
      C.pop_back();
    } else {
      ans1.push_back(L.back());
      ans1.push_back(L.back());
      L.pop_back();
      ans2.push_back(R.back());
      ans2.push_back(R.back());
      R.pop_back();
    }
  }
  for (int a : ans1) {
    cout << a << " ";
  }
  cout << "\n";
  for (int a : ans2) {
    cout << a << " ";
  }
  cout << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
