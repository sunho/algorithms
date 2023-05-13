#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9;
struct seg_tree {
  int n;
  vector<int> bits;
  seg_tree(int n) : n(n), bits((n+1)*2, inf) {}

  int combine(int a, int b) { return min(a,b); }
  void update(int k, int x) {
    k += n, bits[k] = x;
    for (k /= 2; k; k /= 2) bits[k] = combine(bits[k*2], bits[k*2+1]);
  }
  int query(int l, int r) {
    int res = inf;
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
      if (l & 1) res = combine(res, bits[l++]);
      if (!(r & 1)) res = combine(res, bits[r--]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  vector<int> inv(n);
  seg_tree st(n+1);
  for (int i=0;i<n;i++){
    cin >> A[i];
    A[i]--;
    inv[A[i]] = i;
    st.update(i, A[i]);
  }

  vector<int> ans;
  int l=0;
  int rem=k;
  for (;l<n&&rem>0;){
    int term = st.query(l, min(l+rem,n));
    if (term == inf) break;
    ans.push_back(term);
    rem -= inv[term] - l;
    l = inv[term]+1;
  }
  for (;l<n;l++){
    ans.push_back(A[l]);
  }
  while (rem) {
    ans.pop_back();
    rem--;
  }
  int sf = st.query(n-k, n);
  if (sf != inf) {
    int rotated = n-inv[sf];
    rotate(begin(A), begin(A) + inv[sf], end(A));
    for (int i=0;i<n;i++){
      st.update(i, A[i]);
      inv[A[i]] = i;
    }
    vector<int> cand2;
    for (int i=0;i<rotated;){
      int term = st.query(i, k);
      if (term == inf) break;
      if (inv[term] < rotated)
        cand2.push_back(term);
      i = inv[term]+1;
    }
    k -= rotated;
    int l = rotated;
    int rem = k;
    for (;l<n&&rem>0;){
      int term = st.query(l, min(l+rem,n));
      if (term == inf) break;
      cand2.push_back(term);
      rem -= inv[term] - l;
      l = inv[term]+1;
    }
    for (;l<n;l++){
      cand2.push_back(A[l]);
    }
    while (rem) {
      cand2.pop_back();
      rem--;
    }
    ans = min(ans, cand2);
  }
  for (int v : ans) cout << v + 1 << " ";
}
