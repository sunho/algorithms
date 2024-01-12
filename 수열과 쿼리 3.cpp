#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct merge_sort_tree {
  int n;
  vector<vector<int>> tree;
  merge_sort_tree(const vector<int>& A) : n(A.size()), tree(2*n) {
    for(int i=0; i<n; i++) {
      tree[i+n].push_back(A[i]);
    }
    for(int i=n-1; i > 0; i--){
      tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
      merge(begin(tree[i*2]), end(tree[i*2]), begin(tree[i*2+1]), end(tree[i*2+1]), tree[i].begin());
    }
  }
  int query(int l, int r, int k){
    int ret = 0;
    for (l+=n, r+=n; l <= r; l >>= 1, r >>= 1) {
      if(l & 1) ret += tree[l].end() - upper_bound(begin(tree[l]), end(tree[l]), k), l++;
      if(~r & 1) ret += tree[r].end() - upper_bound(begin(tree[r]), end(tree[r]), k), r--;
    }
    return ret;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  merge_sort_tree mt(A);
  int q;
  cin >> q;
  int last_ans = -1;
  while(q--){
    int l,r,k;
    cin >> l >> r >> k;
    if (last_ans != -1) {
      l ^= last_ans;
      r ^= last_ans;
      k ^= last_ans;
    }
    --l,--r;
    last_ans = mt.query(l,r,k);
    cout << last_ans << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
