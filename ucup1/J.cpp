#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    if (a == 0)
      m--;
    else
      A.push_back(a);
  }
  n = A.size();
  if (m < 0) {
    cout << "Impossible" << "\n";
    return;
  }
  if (m == n) {
    cout << "Richman" << "\n";
    return;
  }
  ll ans = 0;
  for (int i=0;i<m;i++){
    ans += A[i];
  }
  ans += *min_element(begin(A)+m, end(A))-1;
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for(int i=0;i<t;i++)
    solve();
}
