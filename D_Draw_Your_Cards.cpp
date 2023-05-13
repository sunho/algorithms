#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> cards;
  set<pair<int,int>> piles;
  vector<int> A(n);
  for (int i=0;i<n;i++) {
    cin >> A[i];
    --A[i];
  }
  vector<int> ans(n, -2);
  for (int i=0;i<n;i++){
    auto it = piles.upper_bound({A[i],0});
    if (it == piles.end()) {
      if (k == 1) {
        ans[A[i]] = i;
      } else {
        piles.insert({A[i], cards.size()});
        cards.push_back({});
        cards.back().push_back(i);
      }
      continue;
    }
    int ci = it->second;
    cards[ci].push_back(i);
    piles.erase(it);
    if (cards[ci].size() == k) {
      for (int v : cards[ci]) {
        ans[A[v]] = i;
      }
    } else {
      piles.insert({A[i], ci});
    }
  }
  for (int v : ans) {
    cout << v + 1 << "\n";
  }
}
