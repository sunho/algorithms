#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define _0 first
#define _1 second
template<class T> using pqg = priority_queue<T, vector<T>, greater<T> >;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int a,b,c;
  cin >> a >> b >> c;
  int d,e,f;
  cin >> d >> e >> f;
  int x;
  cin >> x;
  int x0 = x/(a+c)*b*a + (min(x%(a+c),a))*b;
  int x1 = x/(d+f)*e*d + (min(x%(d+f),d))*e;
  if (x0 > x1) {
    cout << "Takahashi" << "\n";
  } else if (x0 < x1) {
    cout << "Aoki" << "\n";
  } else {
    cout << "Draw" << "\n";
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
