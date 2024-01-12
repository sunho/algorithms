#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  ll d;
  cin >> d;
  vector<int> A;
  vector<int> B;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 2) {
      A.push_back(y);
    } else {
      B.push_back(y);
    }
  }
  sort(begin(A), end(A));
  sort(begin(B), end(B));
  int ptr = 0;
  for (int i = 0; i < A.size(); i++) {
    while (ptr < B.size() && d > B[ptr]) {
      d += B[ptr];
      ptr++;
    }
    d *= A[i];
    d = min((ll)1e9 + 1, d);
  }
  while (ptr < B.size() && d > B[ptr]) {
    d += B[ptr];
    ptr++;
  }
  cout << ptr + A.size() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
