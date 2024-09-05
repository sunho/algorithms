#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int pow3(int n) {
  int res = 1;
  while (n--){
    res *= 3;
  }
  return res;
}

gp_hash_table<ll,int> brute(vector<int>& A) {
  gp_hash_table<ll,int> cnt;
  int n = (int)A.size();
  vector<int> sign(n);
  auto dfs = [&](auto&& self, int i) {
    if (i == n) {
      bool okay = false;
      ll sum = 0;
      for (int j=0;j<n;j++){
        if (sign[j] != 0) okay = true;
        sum += sign[j] * A[j];
      }
      if (okay)
        cnt[sum]++;
      return;
    }
    for (int s : {-1,0,1}) {
      sign[i] = s;
      self(self, i+1);
    }
  };
  dfs(dfs, 0);
  return cnt;
}

void solve() {
  int n;
  cin >> n;
  int N = 28;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  if (n > N) {
    cout << 0 << "\n";
    return;
  }
  int m = n / 2;
  auto L = vector<int>(A.begin(), A.begin() + m);
  auto R = vector<int>(A.begin() + m, A.end());
  auto cnt1 = brute(L), cnt2 = brute(R);
  if (cnt1.find(0) != cnt1.end() || cnt2.find(0) != cnt2.end()) {
    cout << 0 << "\n";
    return;
  }
  for (auto [l, _] : cnt1) {
    if (cnt2.find(-l) != cnt2.end())  {
      cout << 0 << "\n";
      return;
    }
  }
  for (auto [r, _] : cnt2) {
    if (cnt1.find(-r) != cnt1.end())  {
      cout << 0 << "\n";
      return;
    }
  }
  if (n > 14) {
    for (ll i=0;i<40;i++){
      ll target = 1ll << i;
      for (auto [l, _] : cnt1) {
        if (cnt2.find(target-l) != cnt2.end())  {
          cout << 1 << "\n";
          return;
        }
      }
      for (auto [r, _] : cnt2) {
        if (cnt1.find(target-r) != cnt1.end())  {
          cout << 1 << "\n";
          return;
        }
      }
    }
    cout << 2 << "\n";
    return;
  }
  //assert(n <= 14 && "it's so over");
  auto D = brute(A);
  int ans = 20;
  for (auto [x,_] : D) {
    if (x >= 0)
      ans = min(ans, __builtin_popcountll(x));
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
