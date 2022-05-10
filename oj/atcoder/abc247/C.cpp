#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  auto f = [&](int n, auto&& self) -> vector<int> {
    if (n == 1) {
      return { 1 };
    }
    auto a = self(n-1, self);
    vector<int> out;
    out.insert(out.end(), all(a));
    out.push_back(n);
    out.insert(out.end(), all(a));
    return out;
  };
  auto A = f(n,f);
  for (int x : A) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
