#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
  int m,n;
  cin >> m >> n;
  vector<ull> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  A.push_back(0);
  sort(begin(A),end(A));
  ull ans = 0;
  ull cur = 0;
  int cnt = 0;
  while (!A.empty()) {
    ull a = A.back();
    if (cnt == 0) {
      cur = a;
      cnt = 1;
      A.pop_back();
      continue;
    }
    int k = (int)min((ull)(cur-a)*cnt,(ull)m);
    if (cur != a && (ull)k < (ull)(cur-a)*cnt) {
      ull nn = cur-k/cnt;
      ans += nn*nn*(cnt-k%cnt);
      ans += (nn-1)*(nn-1)*(k%cnt);
      break;
    }
    A.pop_back();
    m -= k;
    cur = a;
    cnt++;
  }
  for (ull a : A) {
    ans += a*a;
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
