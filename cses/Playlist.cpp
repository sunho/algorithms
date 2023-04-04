#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n, 0);
  for(int i=0;i<n;i++) cin >> A[i];
  map<int, int> p;
  int l=0;
  int ans=0;
  for(int i=0;i<n;i++){
    if (p.count(A[i])) {
      l = max(l,p[A[i]]+1);
    }
    p[A[i]] = i;
    ans = max(ans, i-l+1);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
