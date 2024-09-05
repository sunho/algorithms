#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<tuple<ll,ll,ll>> A(n);
  vector<ll> X;
  vector<ll> Y;
  for (int i=0;i<n;i++){
    int a,b,c;
    cin >> a >> b >> c;
    A[i] = {a,b,c};
    X.push_back(a);
    Y.push_back(b);
  }
  sort(begin(X),end(X));
  sort(begin(Y),end(Y));
  int ans = n;
  for (int i0=0;i0<n;i0++){
    for (int i1=i0;i1<n;i1++){
      for (int j0=0;j0<n;j0++){
        for (int j1=j0;j1<n;j1++){
          ll x0 = X[i0], x1 = X[i1];
          ll y0 = Y[j0], y1 = Y[j1];
          ll s = 2*(x1-x0) + 2*(y1-y0);
          int cand = 0;
          ll rem = 0;
          vector<ll> ins;
          for (int i=0;i<n;i++){
            auto [x,y,w] = A[i];
            if (x < x0 || x > x1 || y < y0 || y > y1) {
              cand++;
              rem += w;
            } else {
              ins.push_back(w);
            }
          }
          sort(rbegin(ins),rend(ins));
          for (ll w : ins) {
            if (rem < s) {
              cand++;
              rem += w;
            }
          }
          if (rem < s) 
            continue;
          ans = min(ans, cand);
        }
      }
    }
  }
  cout << ans;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
