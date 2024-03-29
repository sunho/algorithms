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

