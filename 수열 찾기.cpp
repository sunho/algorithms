#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(11);
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  bool ok = true;
  for (int i=0;i<=10;i++) {
    if (cnt[i] > 0 && cnt[i] % 2 == 0) {
      ok = false;
    }
  }
  if (ok) {
    cout << 1;
  } else {
    cout << 0;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
