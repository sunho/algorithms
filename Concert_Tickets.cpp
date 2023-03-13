#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,m;
  cin >> n >> m;
  multiset<int> tickets;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    tickets.insert(a);
  }
  while (m--) {
    int x;
    cin >> x;
    auto it = tickets.upper_bound(x);
    if (it == tickets.begin()) {
      cout << "-1" << "\n";
      continue;
    }
    --it;
    cout << *it << "\n";
    tickets.erase(it);
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
