#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> P(n, -1);
  vector<int> M(n, -1);
  for (int i=0;i<m;i++){
    int a;
    char t;
    int v;
    cin >> a >> t >> v;
    --a;
    if (t == 'P') {
      P[a] = v;
    } else {
      M[a] = v;
    }
  }
  int mn = 0, mx = 0;
  for (int i=0;i<n;i++){
    if (M[i] == 1 || P[i] == 0) continue;
    if (M[i] == 0 && P[i] == 1) {
      mn ++, mx ++;
    } else {
      mx ++;
    }
  }
  cout << mn << " " << mx << "\n";
}
