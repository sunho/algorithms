#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n; ll k;
  cin >> n >> k;

  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<ll> pf(2*n+1);
  for (int i=0;i<2*n;i++){
    pf[i+1] = pf[i] + A[i%n];
  }

  vector<int> nxt(2*n+1);

  for (int i=0;i<2*n;i++){
    int z = upper_bound(pf.begin() + i+1, pf.begin() + min(i + 1 + n,2*n+1), pf[i] + k) - pf.begin();
    nxt[i] = z-1;
  }
  nxt[2*n] = 2*n;

  int l = ceil(log2(2*n+1));
  vector<array<int,32>> up(2*n+1);
  for (int k=0;k<l;k++){
    for (int i=0;i<2*n+1;i++){
      if (k == 0)
        up[i][k] = nxt[i];
      else
        up[i][k] = up[up[i][k-1]][k-1];
    }
  }
  
  int ans = 1e9;

  for (int i=0;i<n;i++){
    int u = i;
    int cnt = 0;
    for (int k=l-1;k>=0;k--){
      if (up[u][k] < i + n) {
        u = up[u][k];
        cnt += (1<<k);
      }
    }
    cnt++;
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}
