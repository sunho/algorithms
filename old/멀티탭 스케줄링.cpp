#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// 1 2 1 2 1 2 3 3 3 3 
//

void solve() {
  int n,k;
  cin >> n >> k;
  vector<int> A(k);
  vector<int> last(k);
  for (int i=0;i<k;i++) {
    cin >> A[i];
    A[i]--;
    last[A[i]] = i;
  }
  set<int> cur;
  int ans = 0;
  for (int i=0;i<k;i++){
    if (cur.count(A[i])) continue;
    if (cur.size() == n) {
      int found = -1;
      for (int x : cur) {
        if (last[x] <= i) {
          found = x;
        }
      }
      set<int> vis;
      if (found == -1) {
        for (int j=i+1;j<k;j++){
          if (!vis.count(A[j]) && cur.count(A[j])) {
            vis.insert(A[j]);
            found = A[j];
          }
        }
      }
      cur.erase(found);
      ans++;
    }
    cur.insert(A[i]);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
