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
  int k = 1;
  int cur = pos[k];
  int ans = 1;
  while (k < n) {
    if (cur > pos[k+1]) {
      ans++;
    }
    cur = pos[k+1];
    k++;
  }
  auto calc = [&](int k) -> int {
    int cont = 0;
    if (k-1 >= 1) {
      if (pos[k] < pos[k-1]) {
        cont ++;
      }
    }
    if (k+1 <= n) {
      if (pos[k] > pos[k+1]) {
        cont ++;
      }
    }
    return cont;
  };
  while(m--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    int k = A[a], k2 = A[b];
    swap(A[a], A[b]);
    int last_acont = calc(k);
    int last_bcont = calc(k2);
    pos[k] = b;
    pos[k2] = a;
    int new_acont =  calc(k);
    int new_bcont =  calc(k2);
    ans += new_acont + new_bcont - last_acont - last_bcont;
    cout << ans << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
