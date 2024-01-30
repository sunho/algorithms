#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> B(n);
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  int cnt = 0;
  for (int i=0;i<n;i++) {
    cnt += A[i] == B[i];
  }
  bool ok = cnt == n;
  auto set_a = [&](int i, int a) {
    cnt -= A[i] == B[i];
    A[i] = a;
    cnt += A[i] == B[i];
    if (cnt == n) {
      ok = true;
    }
  };
  for (int i=1;i<n;i++){
    int loc = i-1;
    int nw = A[i];
    while (loc >= 0 && nw < A[loc]) {
      set_a(loc+1, A[loc]);
      loc--;
    }
    if (loc+1 != i) {
      set_a(loc+1, nw);
    }
  }
  cout << ok;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
