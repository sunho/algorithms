#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> cur;
  for (int i=0;i<n;i++){
    int j = lower_bound(begin(cur),end(cur), A[i]) - cur.begin();
    if (j == cur.size()) {
      cur.push_back(A[i]);
    } else {
      cur[j] = A[i];
    }
  }
  cout << cur.size() << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
