#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
  }
  ll sum = 0;
  auto f = [&](auto&& self, int turn, int even, int odd) -> int {
    if (odd % 3 == 1) {
      return odd / 3 + 1;
    } else if (odd % 3 == 2) {
      return odd / 3;
    } else {
      return odd / 3;
    }
  };
  int odd = 0, even = 0;
  for (int i=0;i<n;i++) {
    sum += A[i];
    if (A[i] % 2 == 0) {
      even++;
    } else {
      odd++;
    }
    if (i == 0) {
      cout << sum << " ";
    } else {
      ll last = odd % 2 == 1 ? (sum+1)/2*2 : (sum)/2*2;
      if (even == 0) {
        if (odd > 2) {
          last -= (f(f, 0, even, odd-3)+1);
        } else {
          last -= f(f, 0, even, odd-2);
        }
      } else {
        last -= f(f, 0, even, odd);
      }
      cout << (last)/2*2 << " ";
    }
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)
  solve();
}
