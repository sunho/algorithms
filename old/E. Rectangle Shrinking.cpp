#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  using Rect = pair<int, pair<int,int>>;
  vector<Rect> A(n);
  for (int i=0;i<n;i++){
    int u,l,d,r;
    cin >> u >> l >> d >> r;
    if (u == 1 && d == 2) {
      A[i] = {2,{l,r}};
    } else {
      A[i] = {u-1,{l,r}};
    }
  }
  vector<int> order(n);
  iota(begin(order),end(order),0);
  sort(begin(order),end(order),[&](int i, int j) {
    return make_pair(A[i].second, -A[i].first) < make_pair(A[j].second, -A[j].first);
  });
  vector<int> done(2);
  for (int i : order) {
    auto& [l,r] = A[i].second;
    auto& t = A[i].first;
    for (int z : {0,1}) {
      if (t == z) {
        if (r <= done[z]) {
          t = -1;
        } else if (l <= done[z]) {
          l = done[z]+1;
          done[z] = r;
        } else {
          done[z] = r;
        }
      }
    }
    if (t == 2) {
      bool o = false;
      for (int z : {0,1}) {
        if (r <= done[z]) {
          o = true;
          if (r <= done[z^1]) {
            t = -1;
          } else if (l <= done[z^1]){
            t = z^1;
            l = done[z^1] + 1;
            done[z^1] = r;
          } else {
            t = z^1;
            done[z^1] = r;
          }
          break;
        }
      }
      if (!o) {
        if (l <= min(done[0],done[1])) {
          l = min(done[0],done[1]) + 1;
          done[0] = r;
          done[1] = r;
        } else {
          done[0] = r;
          done[1] = r;
        }
      }
    }
  }
  done.assign(2, 2e9);
  iota(begin(order),end(order),0);
  sort(begin(order),end(order),[&](int i, int j) {
    return make_pair(-A[i].second.second, -A[i].first) < make_pair(-A[j].second.second, -A[j].first);
  });
  for (int i : order) {
    auto& [l,r] = A[i].second;
    auto& t = A[i].first;
    if (t == -1) continue;
    for (int z : {0,1}) {
      if (t == z) {
        if (l >= done[z]) {
          t = -1;
        } else if (r >= done[z]) {
          r = done[z]-1;
          done[z] = l;
        } else {
          done[z] = l;
        }
      }
    }
    if (t == 2) {
      bool o = false;
      for (int z : {0,1}) {
        if (l >= done[z]) {
          o = true;
          if (l >= done[z^1]) {
            t = -1;
          } else if (r >= done[z^1]){
            t = z^1;
            r = done[z^1] - 1;
            done[z^1] = l;
          } else {
            t = z^1;
            done[z^1] = l;
          }
          break;
        }
      }
      if (!o) {
        if (r >= max(done[0],done[1])) {
          r = max(done[0],done[1]) + 1;
          done[0] = l;
          done[1] = l;
        } else {
          done[0] = l;
          done[1] = l;
        }
      }
    }
  }
  int ans = 0;
  for (int i=0;i<n;i++) {
    auto [l,r] = A[i].second;
    auto t = A[i].first;
    if (t == 0 || t == 1) {
      ans += (r-l+1);
    } else if (t == 2) {
      ans += (r-l+1)*2;
    }
  }
  cout << ans << "\n";
  for (int i=0;i<n;i++) {
    auto [l,r] = A[i].second;
    auto t = A[i].first;
    if (t == 0) {
      cout << 1 << " " << l << " " << 1 << " " << r << "\n";
    } else if (t == 1){
      cout << 2 << " " << l << " " << 2 << " " << r << "\n";
    } else if (t == 2) {
      cout << 1 << " " << l << " " << 2 << " " << r << "\n";
    } else {
      cout << 0 << " " << 0 << " " << 0 << " " << 0 << "\n";
    }
  }
  
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
