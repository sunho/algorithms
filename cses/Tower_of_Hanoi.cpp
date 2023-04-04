#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  vector<pair<int,int>> ans;
  auto f = [&](int start, int end, int k, auto&& self) -> void {
    if (k == 1) {
      ans.push_back({start,end});
      return;
    }
    set<int> avail = {0,1,2};
    avail.erase(start);
    avail.erase(end);
    int temp = *avail.begin();
    self(start, temp, k-1, self);
    ans.push_back({start,end});
    self(temp, end, k-1, self);
  };
  int n;
  cin >> n;
  f(0,2,n,f);
  cout << ans.size() << "\n";
  for(auto [start, end] : ans) {
    cout << start + 1 << " " << end + 1 << "\n";
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
