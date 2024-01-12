#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll x1,x2;
  int a,b,c,d,e;
  cin >> x1 >> x2 >> a >> b >> c >> d >> e;
  auto F = [&](ll x) {
    return a*x*x*x/3 + (b-d)*x*x/2 + (c-e)*x;
  };
  cout << F(x2) - F(x1) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
