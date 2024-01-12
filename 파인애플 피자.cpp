#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct fenwick_tree {
  int n;
  vector<ll> bits;
  fenwick_tree(int n) : n(n), bits(n + 1) {}
  void update(int v, int delta) {
    for (++v; v <= n; v += v & (-v))
      bits[v] += delta;
  }
  ll query(int r) {
    ll res = 0;
    for (++r; r > 0; r -= r & (-r))
      res += bits[r];
    return res;
  }
  ll query(int l, int r) { return query(r) - query(l - 1); }
};

vector<int> compress(vector<int> A) {
  auto vals = A;
  sort(begin(vals),end(vals));
  vals.resize(unique(begin(vals),end(vals))-begin(vals));
  for (int i=0;i<A.size();i++){
    A[i] = lower_bound(begin(vals), end(vals), A[i]) - begin(vals);
  }
  return A;
}

void solve() {
  int n,m;
  cin >> n >> m;
  vector<int> A(n);
  vector<int> B(m);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  A = compress(A);
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  for (int i=0;i<n;i++){
    A.push_back(A[i]);
  }
  B = compress(B);
  n*=2;
  vector<int> cnt(n+m);
  fenwick_tree ft(n+m);
  vector<int> M(m), M2(m);
  for (int i=0;i<m;i++){
    M[i] = ft.query(0,B[i]-1);
    M2[i] = ft.query(B[i]+1,n+m-1);
    if (cnt[B[i]] == 0) {
      ft.update(B[i], 1);
    }
    cnt[B[i]] ++;
  }
  ft = fenwick_tree(n+m);
  cnt = vector(n+m,0);

  auto match = [&](int i, int a) {
    if (i == m) return false;
    return ft.query(0, a-1) == M[i] && ft.query(a+1, n+m-1) == M2[i];
  };
  vector<int> pf(m);
  for (int i=1;i<m;i++){
    int j = pf[i-1];
    while (j > 0 && !match(j, B[i])) {
      for (int k=i-j;k<i-pf[j-1];k++){
        cnt[B[k]]--;
        if (cnt[B[k]] == 0) {
          ft.update(B[k], -1);
        }
      }
      j = pf[j-1];
    }
    if (match(j, B[i])) {
      if (cnt[B[i]] == 0) {
        ft.update(B[i], 1);
      }
      cnt[B[i]]++;
      j++;
    }
    pf[i] = j;
  }
  ft = fenwick_tree(n+m);
  cnt = vector(n+m,0);
  int ans = 0;
  int len = 0;
  for (int i=0;i<n/2+m;i++){
    while (len > 0 && !match(len, A[i])) {
      int nxt = pf[len-1];
      for (int k=i-len;k<i-nxt;k++){
        cnt[A[k]]--;
        if (cnt[A[k]] == 0) {
          ft.update(A[k], -1);
        }
      }
      len = nxt;
    }
    if (match(len, A[i])) {
      if (cnt[A[i]] == 0) {
        ft.update(A[i], 1);
      }
      cnt[A[i]]++;
      len++;
    }
    if (i >= m && len == m) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
