#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> A(n);
  for (int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    A[i] = {b,a};
  }
  sort(begin(A),end(A));
  multiset<int> members;
  for (int i=0;i<k;i++){
    members.insert(0);
  }
  int ans = 0;
  for (int i=0;i<n;i++){
    auto [r,l] = A[i];
    // l *= -1;
    auto it = members.upper_bound(l);
    if (it == members.begin()) {
      continue;
    }
    --it;
    members.erase(it);
    members.insert(r);
    ans++;
  }
  cout << ans << "\n";
  
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
