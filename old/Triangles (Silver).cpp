#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Modular Integer
// does arithmetics (mod P) automatically
const int MOD = 1000000007; // 998244353
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

void solve() {
  int n;
  cin >> n;
  vector<pair<int,int>> A(n);
  map<int, vector<int>> Y, X;
  map<int, vector<ll>> pf_x, pf_y;
  for (int i=0;i<n;i++){
    cin >> A[i].first >> A[i].second;
    Y[A[i].first].push_back(A[i].second);
    X[A[i].second].push_back(A[i].first);
  }
  for (auto& [k, a] : X) {
    sort(begin(a),end(a));
    pf_x[k] = vector<ll>(a.size()+1);
    for (int i=0;i<a.size();i++) {
      pf_x[k][i+1] = pf_x[k][i] + a[i];
    }
  }
  for (auto& [k, a] : Y) {
    sort(begin(a),end(a));
    pf_y[k] = vector<ll>(a.size()+1);
    for (int i=0;i<a.size();i++) {
      pf_y[k][i+1] = pf_y[k][i] + a[i];
    }
  }

  mint ans = 0;
  for (int i=0;i<n;i++){
    auto [x,y] = A[i];
    mint xx = 0, yy = 0;
    auto yit = lower_bound(Y[x].begin(), Y[x].end(), y);
    yy += pf_y[x].back() - pf_y[x][yit-Y[x].begin()];
    yy -= (mint)y*(Y[x].end()-yit);
    yy += (mint)y*(yit-Y[x].begin());
    yy -= pf_y[x][yit-Y[x].begin()];
    auto xit = lower_bound(X[y].begin(), X[y].end(), x);
    xx += pf_x[y].back() - pf_x[y][xit-X[y].begin()];
    xx -= (mint)x*(X[y].end()-xit);
    xx += (mint)x*(xit-X[y].begin());
    xx -= pf_x[y][xit-X[y].begin()];
    mint cont = xx*yy;
    ans += cont;
  }
  cout << ans.x << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
