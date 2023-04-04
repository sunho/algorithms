#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector A(n, 0);
  vector pos(n, 0);
  for(int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
    pos[A[i]]=i;
  }
  int ans = 0;
  int cur = n;
  for (int i=0;i<n;i++){
    if (cur > pos[i]) {
      ans++;
    }
    cur = pos[i];
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
