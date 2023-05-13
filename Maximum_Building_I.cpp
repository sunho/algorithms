#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;
  vector M(n, vector<char>(m, ' '));
  vector<set<int>> cols(m);
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin >> M[i][j];
      if (M[i][j] == '*') {
        cols[j].insert(i);
      }
    }
  }

  stack<pair<int,int>> st;
  ll ans = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      auto it = cols[j].lower_bound(i);
      int h = it == cols[j].end() ? n - i : *it - i;
      while (!st.empty() && st.top().second > h) {
        auto [last, h2] = st.top();
        st.pop();
        int width = st.empty() ? j : j - st.top().first - 1;
        ans = max(ans, (ll)h2*width);
      }
      st.push({j,h});
    }
    while (!st.empty()) {
      auto [last, h2] = st.top();
      st.pop();
      int width = st.empty() ? m : m - st.top().first - 1;
      ans = max(ans, (ll)h2*width);
    }
  }
  cout << ans << "\n";
}
