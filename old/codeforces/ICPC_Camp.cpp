#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, p, q, s;
  cin >> n >> p >> q >> s;
  vector<int> A(p), B(q);
  for (int i=0;i<p;i++){
    cin >> A[i];
  }
  for (int i=0;i<q;i++){
    cin >> B[i];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  auto check = [&](int D) {
    int rem = n;
    multiset<int> S(B.begin(), B.end());
    for (int i=p-1;i>=0;i--){
      int r = min(s - A[i], A[i]+D);
      auto it = S.upper_bound(r);
      if (it == S.begin())
        continue;
      --it;
      if (abs(A[i] - *it) > D)
        continue;
      rem--;
      if (rem == 0) {
        return true;
      }
      S.erase(it);
    }
    return false;
  };

  const int inf = 1e9;
  int ng = -1, ok = inf + 1;
  while (ok - ng > 1) {
    int mid = (ok+ng)/2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  if (ok == inf + 1) {
    cout << -1 << "\n";
  } else {
    cout << ok << "\n";
  }
}
