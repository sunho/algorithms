#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n+1) {}
  void update(int v, int delta) { 
    for (++v; v <= n; v += v&(-v)) bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r&(-r)) res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l-1); }
};

ll solve1(vector<int> A) {
  const int n = A.size();

  fenwick_tree ft(n);
  ll res = 0;
  for (int i=0;i<n;i++){
    res += A[i] == n-1 ? 0 : ft.query(A[i]+1, n-1);
    ft.update(A[i], 1);
  }
  return res;
}

ll solve2(vector<int> A) {
  const int n = A.size();

  vector<pair<int,int>> B;
  vector<int> cnt(n);
  for (int i=0;i<n;i++){
    B.push_back({A[i], cnt[A[i]]++});
  }
  auto vals = B;
  sort(vals.begin(), vals.end());
  for (int i=0;i<n;i++) A[i] = lower_bound(vals.begin(), vals.end(), B[i]) - vals.begin();

  vector<bool> vis(n);
  ll res = 0;
  for (int i=0;i<n;i++){
    int cur = i;
    int len = 0;
    while (!vis[cur]) {
      len++;
      vis[cur] = true;
      cur = A[i];
    }
    if (len) {
      res += len - 1;
    }
  }
  return res;
}

ll solve3(vector<int> A) {
  const int n = A.size();

  vector<vector<int>> vals(n);
  for (int i=0;i<n;i++){
    vals[A[i]].push_back(i);
  }

  fenwick_tree ft(n);

  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  ll res = 0;
  for (auto& arr : vals) {
    for (int i : arr) {
        ft.update(i,-1);
      int c = ft.query(i);
      if (c) {
        res ++;
      }
    }
  }
  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  ll res2 = 0;
  for (auto it = vals.rbegin(); it != vals.rend(); it++) {
    auto& arr = *it;
    for (int i : arr) {
      ft.update(i,-1);
      int c = ft.query(i, n-1);
      if (c) {
        res2 ++;
      }
    }
  }
  return min(res,res2);
}

ll solve4(vector<int> A) {
  const int n = A.size();

  vector<vector<int>> vals(n);
  for (int i=0;i<n;i++){
    vals[A[i]].push_back(i);
  }

  fenwick_tree ft(n);

  for (int i=0;i<n;i++){
    ft.update(i,1);
  }
  ll res = 0;
  for (auto it = vals.rbegin(); it != vals.rend(); it++) {
    auto& arr = *it;
    for (auto jt = arr.rbegin(); jt != arr.rend(); jt++) {
      ft.update(*jt,-1);
      int c = ft.query(*jt, n-1);
      if (c) {
        res ++;
      }
    }
  }
  return res;
}



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  auto vals = A;
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end())-vals.begin());
  for (int i=0;i<n;i++) A[i] = lower_bound(vals.begin(), vals.end(), A[i]) - vals.begin();
  cout << solve1(A) << " " << solve2(A) << " " << solve3(A) << " " << solve4(A);
}
