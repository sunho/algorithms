#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int,int>> A(n);
    for (int i=0;i<n;i++){
      int l,r,a,b;
      cin >> l >> r >> a >> b;
      A[i] = {l,b};
    }
    sort(begin(A),end(A));
    vector<pair<int,int>> fin;
    int ptr = 0;
    while (ptr < n) {
      int l = A[ptr].first;
      int r = A[ptr].second;
      ptr++;
      while (ptr < n && r >= A[ptr].first) {
        r = max(r,A[ptr].second);
        ptr++;
      }
      fin.push_back({l,r});
    }
    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;
      auto it = upper_bound(begin(fin),end(fin),make_pair(x,(int)1e9));
      if (it == begin(fin)) {
        cout << x << " ";
        continue;
      }
      --it;
      if (it->first > x) {
        cout << x << " ";
        continue;
      }
      cout << max(x,it->second) << " ";
    }
    cout << "\n";
  }
}
