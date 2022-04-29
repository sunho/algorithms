#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  --k;
  const int N = 2e5;
  vector<int> A(n);
  vector<int> mf(N+1, -1);
  for(int i=0;i<n;i++) cin >> A[i];
  vector<int> dp(n+1);
  dp[n] = -1;
  for(int i=n-1;i>=0;i--){
    if (mf[A[i]] == -1) {
      dp[i] = A[i];
    } else {
      dp[i] = dp[mf[A[i]]+1];
    }
    mf[A[i]] = i;
  }
  map<int,int> idx;
  vector<int> cycle_pos;
  int cur = dp[0];
  if (cur == -1) {
    cout << "\n";
    return;
  }
  int cur_pos = 0;
  while(!idx.count(cur)) {
    idx[cur] = (int)cycle_pos.size();
    cycle_pos.push_back(cur_pos);
    cur_pos = mf[cur]+1;
    if (dp[cur_pos] == -1) {
      cycle_pos.push_back(n);
      cur = dp[0];
      break;
    } else {
      cur = dp[cur_pos];
    }
  }
  int b = idx[cur];
  if (k >= b) {
    k -= b;
    cycle_pos.erase(cycle_pos.begin(), cycle_pos.begin() + b);
  }
  int c = (int)cycle_pos.size();
  k %= c;
  set<int> ins;
  vector<int> ans;
  for(int i=cycle_pos[k];i<n;i++){
    if (ins.count(A[i])) {
      ins.erase(A[i]);
      while (ans.back() != A[i]) {
        ins.erase(ans.back());
        ans.pop_back();
      }
      ans.pop_back();
    } else {
      ins.insert(A[i]);
      ans.push_back(A[i]);
    }
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
