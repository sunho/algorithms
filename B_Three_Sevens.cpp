#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int, int> last_;
  for (int i=0;i<n;i++){
    int m;
    cin >> m;
    for (int j=0;j<m;j++){
      int k;
      cin >> k;
      --k; 
      last_[k] = i;
    }
  }
  int N = last_.size();
  vector<pair<int,int>> last;
  for (auto [i, sz] : last_) {
    last.push_back({sz,i});
  }
  sort(begin(last), end(last));
  vector<int> ans;
  int cur = 0;
  for (int i=0;i<n;i++){
    while (cur < N && last[cur].first != i) {
      cur++;
    }
    if (cur != N) {
      ans.push_back(last[cur].second);
    } else {
      cout << "-1" << "\n";
      return;
    }
  }
  for (int i=0;i<n;i++){
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
    solve();
}
