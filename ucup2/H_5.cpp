#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    map<vector<int>, int> cache;
    vector<int> A(n);
    vector<tuple<int,int,int>> ans_pairs;
    vector<tuple<int,int,int>> pairs;
    for (int i=0;i<n;i++) cin >> A[i];
    int ans = 1e9;
    auto dfs = [&](auto self, int cnt) -> void {
      // for (int i : A)
      //   cout << i << " ";
      // cout << "\n";
      if (cache.count(A)) {
        if (cache[A] <= cnt)
          return;
      }
      cache[A] = cnt;
      bool ok = true;
      for (int i=0;i<n;i++) {
        if (A[i] != 0) {
          ok = false;
        }
      }
      if (ok) {
        ans = min(ans, cnt);
        ans_pairs = pairs;
        return;
      }
      for (int l=0;l<n;l++){
        for (int r=l;r<n;r++){
          bool oo = true;
          for (int i=l;i<=r;i++){
            if (A[i] == 0) oo = false;
          }
          if (oo) {
            pairs.push_back({0,l,r});
            for (int i=l;i<=r;i++){
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              A[i]++;
            }
            pairs.pop_back();
          }
          oo = true;
          int cnt2 =0;
          for (int i=l;i<=r;i++){
            if (i%2 == 0 && A[i] == 0) oo = false;
            if (i%2 == 0) cnt2++;
          }
          if (oo && cnt2 > 1) {
            pairs.push_back({1,l,r});
            for (int i=l;i<=r;i++){
              if  (i%2 == 0)
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              if  (i%2 == 0)
                A[i]++;
            }
            pairs.pop_back();
          }
          oo = true;
          cnt2=0;
          for (int i=l;i<=r;i++){
            if (i%2 == 1 && A[i] == 0) oo = false;
            if (i%2 == 1) cnt2++;
          }
          if (oo && cnt2) {
            pairs.push_back({2,l,r});
            for (int i=l;i<=r;i++){
              if  (i%2 == 1)
              A[i]--;
            }
            self(self, cnt+1);
            for (int i=l;i<=r;i++){
              if  (i%2 == 1)
                A[i]++;
            }
            pairs.pop_back();
          }
        }
      }
    };
    dfs(dfs, 0);
    cout << ans << "\n";
    // for (auto [t,l,r] : ans_pairs) {
    //   cout << t << " " << l << " " << r << "\n";
    // }
  }
}
