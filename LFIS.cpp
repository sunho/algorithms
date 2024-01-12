#include <bits/stdc++.h>
#include <queue>

using namespace std;
using ll = long long;

template<typename T>
struct pred_max_stack {
  map<int,T> st;
  // return maximum y_i such that x_i <= x
  T query(int x) {
    auto it = st.upper_bound(x);
    if (it == st.begin()) {
      return T();
    }
    return (--it)->second;
  }
  // maintain invariant that x_1 < x_2 < x_3 < ... and y_1 < y_2 < y_3 < ...
  void update(int x, T val) {
    auto it = st.upper_bound(x);
    while (it != st.end() && !(val < it->second)) {
      it = st.erase(it);
    }
    // shouldn't insert when prev y is smaller
    if (it != st.begin() && !(prev(it)->second < val)) return;
    st[x] = val;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> dp(n);
  int cnt = 0;
  int mn = A[0];
  int ans = 0;
  pred_max_stack<pair<int,int>> stk;
  for (int i=0;i<n;i++) {
    auto [new_dp, cur] = stk.query(A[i]);
    if (new_dp != 0)
      new_dp++;
    cur *= -1;
    if (A[i] == 0) {
      ++cnt;
      if (new_dp <= cnt) { 
        dp[i] = cnt;
        cur = 0;
      } else {
        dp[i] = new_dp;
      }
    } else if (i != 0){
      if (new_dp <= 2) {
        dp[i] = 2;
        cur = mn;
      } else {
        dp[i] = new_dp;
      }
    }
    if (dp[i] != 0) {
      stk.update(cur+A[i], {dp[i], -A[i]});
    }
    ans = max(ans, dp[i]);
    mn = min(A[i], mn);
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
