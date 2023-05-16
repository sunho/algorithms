#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> id(q);
  iota(begin(id), end(id), 0);
  vector<pair<int,int>> queries(q);
  for (int i=0;i<q;i++){
    cin >> queries[i].first >> queries[i].second;
    --queries[i].first, --queries[i].second;
  }
  sort(begin(id), end(id), [&](int i, int j){
    return queries[i] < queries[j];
  });
  sort(begin(queries), end(queries));
  vector<int> close(n, n);
  vector<ll> pf(n+1);
  for (int i=0;i<n;i++){
    pf[i+1] = pf[i] + A[i];
  }
  vector<ll> sf(n+1);
  set<int> active;
  active.insert(n);
  stack<pair<int,int>> stack;
  vector<ll> ans(q);
  for (int i=n-1;i>=0;i--) {
    while (!stack.empty() && stack.top().first < A[i]) { 
      active.erase(stack.top().second);
      stack.pop();
    }
    if (!stack.empty()) close[i] = stack.top().second;
    stack.push({A[i], i});
    active.insert(i);
    if (close[i] == n) {
      sf[i] = A[i]*(n-i) - (pf[n] - pf[i]);
    } else {
      sf[i] = A[i]*(close[i]-i) - (pf[close[i]] - pf[i]) + sf[close[i]];
    }
    while (!queries.empty() && queries.back().first == i) {
      auto [l,r] = queries.back();
      queries.pop_back();
      int res_id = id.back();
      id.pop_back();
      int rr = *active.upper_bound(r);
      int ll = rr == i ? i : *--active.upper_bound(r);
      ans[res_id] = sf[i] - sf[rr] - (A[ll]*(rr-r-1) - (pf[rr] - pf[r+1]));
    }
  }

  for (int i=0;i<q;i++){
    cout << ans[i] << "\n";
  }
}
