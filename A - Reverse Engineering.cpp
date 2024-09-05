#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<string> A(m);
  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> A[i] >> B[i];
  }
  vector<int> rm(m);
  while (true) {
    bool delta = false;
    for (int j=0;j<n;j++){
      for (int z=0;z<2;z++){
        array<int,2> cnt{};
        vector<int> cands;
        for (int i=0;i<m;i++){
          if (rm[i]) continue;
          if ((A[i][j]-'0') == z) {
            cnt[B[i]]++;
            cands.push_back(i);
          }
        }
        if (cnt[0] >= 1 && cnt[1] >= 1) {
          continue;
        }
        if (min(cnt[0],cnt[1]) == 0 && max(cnt[0],cnt[1]) >= 1) {
          for (int k : cands) {
            rm[k] = true;
          }
          delta = true;
        }
      }
    }
    if (!delta) {
      break;
    }
  }
  bool ok = true;
  for (int z : rm) {
    if (!z) {
      ok = false;
      break;
    }
  }
  array<int,2> cnt{};
  for (int i=0;i<m;i++) {
    if (!rm[i]) {
      cnt[B[i]]++;
    }
  }
  if (min(cnt[0],cnt[1]) == 0 && max(cnt[0],cnt[1]) >= 1) {
    ok = true;
  }
  if (ok){
    cout << "OK" << "\n";
  } else {
    cout << "LIE" << "\n";
  }
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
