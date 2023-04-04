#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> K(n);
  for (int i=0;i<n;i++){
    cin >> K[i];
  }
  sort(begin(K), end(K));
  while (m--) {
    ll a,b,c;
    cin >> a >> b >> c;
    ll bb = abs(b);
    vector<int> cands;
    cands.push_back((int)(upper_bound(begin(K), end(K), bb)-begin(K))-1);
    cands.push_back(upper_bound(begin(K), end(K), bb)-begin(K));
    cands.push_back(upper_bound(begin(K), end(K), -bb)-begin(K));
    cands.push_back((int)(upper_bound(begin(K), end(K), -bb)-begin(K))-1);
    bool found = false;
    for (int i : cands) {
      if (i>=0 && i < n) {
        if ((b-K[i])*(b-K[i]) < 4*a*c) {
          cout << "YES" << "\n";
          cout << K[i] << "\n";
          found = true;
          break;
        }
      }
    }
    if (!found) {
      cout << "NO" << "\n";
    }
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
