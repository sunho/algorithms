#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  int sum = 0;
  for(int i=0;i<n;i++){
    cin >> A[i];
    sum += A[i];
  }
  vector<int> divisors;
  for(int i=1;i*i<=sum;i++){
    if (sum % i == 0) {
      divisors.push_back(i);
      if (i * i != sum) {
        divisors.push_back(sum / i);
      }
    }
  }
  int ans = 1;
  for(int d : divisors) {
    int rem = k;
    multiset<int> m;
    for(int i=0;i<n;i++) {
      int p = A[i] % d;
      if (p != 0) m.insert(p);
    }
    while (!m.empty() && m.size() != 1) {
      int a = *m.begin();
      int b = *--m.end();
      m.erase(m.begin());
      m.erase(--m.end());
      int di = min(a, d-b);
      rem -= di;
      a -= di;
      b += di;
      if (a != 0) m.insert(a);
      if (b != d) m.insert(b);
    }
    if (m.size() == 1 || rem < 0) {
      continue;
    }
    ckmax(ans, d);
  }
  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
