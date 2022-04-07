#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define all(x) begin(x), end(x)
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  ll x = 0;
  vector<int> pos(n, -1);
  vector<ll> sums(n);
  int idx=0;
  while (k && pos[x % n] == -1) {
    pos[x % n] = idx;
    sums[x % n] = x;
    x += A[x % n];
    idx++;
    k--;
  }
  
  if (k == 0) {
    cout << x << "\n";
    return;
  }
  int t = idx - pos[x % n];
  x += k/t * (x - sums[x % n]);
  k %= t;
  while(k) {
    x += A[x%n];
    k--;
  }
  cout << x << "\n";
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
