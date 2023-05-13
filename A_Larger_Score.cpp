#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  set<pair<int,int>> avail;
  set<int> pos;
  for (int i=k;i<n;i++){
    avail.insert({A[i],i});
    pos.insert(i);
  }
  vector<pair<int,int>> cands;
  for (int i=0;i<k;i++){
    cands.push_back({A[i], i});
  }
  sort(begin(cands), end(cands));
  int ans = n;
  for (auto [a, i] : cands){ 
    while (!avail.empty() && avail.begin()->first <= a) {
      pos.erase(avail.begin()->second);
      avail.erase(avail.begin()); 
    }
    if (avail.empty()) break;
    ans = min(ans, *pos.begin() - i);
  }
  if (ans == n) ans = -1;
  cout << ans << "\n";
}
