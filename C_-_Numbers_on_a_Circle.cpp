#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  for(int i=0;i<n;i++) {
    cin >> A[i];
  }
  for(int i=0;i<n;i++) {
    cin >> B[i];
  }

  set<int> q;
  for(int i=0;i<n;i++) {
    if (A[i] > B[i]) {
      cout << "-1" << "\n";
      return;
    }
    if (A[i] < B[i]) {
      q.insert(i);
    }
  }

  ll ans = 0;

  while (!q.empty()) {
    int i = *q.begin();
    q.erase(q.begin());
    int pi = (i-1 + n)%n;
    int ni = (i+1)%n;
    if (B[i] <= B[pi] + B[ni]) {
      continue;
    }
    int p = B[pi] + B[ni];
    int d = B[i] - A[i];
    B[i] = A[i] + d % p;
    ans += d / p;
    if (B[pi] > B[(pi-1+n)%n] + B[i]) {
      q.insert(pi);
    }
    if (B[ni] > B[(ni+1)%n] + B[i]) {
      q.insert(ni);
    }
  }
  if (A != B) {
    cout << -1 << "\n";
    return;
  }

  cout << ans << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
