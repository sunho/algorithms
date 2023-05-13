#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<bitset<3000>> adj(n);
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      adj[i][j] = c-'0';
    }
  }

  ll ans = 0;

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (adj[i][j]) {
        ans += (adj[i] & adj[j]).count();
      }
    }
  }

  cout << ans/6 << "\n";
}
