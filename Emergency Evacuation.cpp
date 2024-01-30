#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, p;

void solve() {
  cin >> n >> m >> p;
  vector<int> A;
  for (int i=0;i<p;i++){
    int x,y;
    cin >> x >> y;
    --x,--y;
    if (y >= m) {
      y++;
    }
    x = n-x;
    A.push_back(x+abs(y-m));
  }
  sort(begin(A),end(A));
  ll ans = 0;
  for (int i=0;i<p;i++){
    if (i != 0) {
      if (A[i-1] >= A[i]) {
        A[i] = A[i-1]+1;
      }
    }
  }
  cout << A.back() << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
