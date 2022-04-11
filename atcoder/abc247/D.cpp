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
  deque<pair<int, int>> q;
  while (n--) {
    int c;
    cin >> c;
    if (c == 1) {
      int x,k;
      cin >> x >> k;
      q.push_back({x,k});
    } else {
      int k;
      cin >> k;
      ll sum = 0;
      while (!q.empty() && k > 0) {
        auto [x, rem] = q.front();
        q.pop_front();
        ll d = min(rem, k);
        rem -= d;
        k -= d;
        sum += d*x;
        if (rem != 0) {
          q.push_front({x, rem});
        }
      }
      cout << sum << "\n";
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
