#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector A(n, 0);
  vector pos(n+1, 0);
  for (int i=0;i<n;i++){
    cin >> A[i];
    pos[A[i]] = i;
  }
  auto calc = [&](int mini, int maxi) {
    int k = mini;
    int cur = pos[mini];
    int ans = 1;
    while (k < maxi) {
      if (cur > pos[k+1]) {
        ans++;
      }
      cur = pos[k+1];
      k++;
    }
    return ans;
  };
  int ans = calc(1,n);
  while(m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    int k1=A[a],k2=A[b];
    if (k1 > k2) swap(k1,k2);
    if (k1+1 == k2) {
      ans -= calc(max(k1-1, 1), min(k2+1,n));
    } else {
      ans -= calc(max(k1-1, 1), min(k1+1,n));
      ans -= calc(max(k2-1, 1), min(k2+1,n));
    }
    swap(pos[k1],pos[k2]);
    swap(A[a],A[b]);
    if (k1+1 == k2) {
      ans += calc(max(k1-1, 1), min(k2+1,n));
    } else {
      ans += calc(max(k1-1, 1), min(k1+1,n));
      ans += calc(max(k2-1, 1), min(k2+1,n));
    }
    cout << ans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
