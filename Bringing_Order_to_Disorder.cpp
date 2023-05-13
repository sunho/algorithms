#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 14;
vector<ll> facts(N+1);

ll multin(array<int,10> cnt, int n) {
  ll res = facts[n];
  for (int v : cnt) {
    if (v != 0) res /= facts[v];
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  facts[0] = 1;
  for (int i=1;i<=N;i++){
    facts[i] = i * facts[i-1];
  }

  string s;
  cin >> s;
  int n = s.size();
  
  vector<int> A(n);
  for (int i=0;i<n;i++) A[i] = s[i]-'0';
  int sum = 0;
  for (int i=0;i<n;i++) sum += A[i];
  ll prod = 1;
  for (int v : A) prod *= (v+1);
  if (sum == 0) {
    cout << 0 << "\n";
    return 0;
  }

  vector<ll> dp(sum);
  dp[0] = 1;
  for (int i=0;i<n;i++){
    vector<ll> next(sum);
    for (int j=0;j<sum;j++){
      for (int d=0;d<=9;d++){
        if (j+d < sum) {
          next[j+d] += dp[j];
        }
      }
    }
    dp = move(next);
  }

  ll ans = 0;
  for (ll v : dp) ans += v;

  vector<int> cur;
  auto dfs = [&](auto self, int i, int sum, int last) -> void {
    if (sum > 9*(n-i))
      return;
    if (i == n) {
      if (sum != 0) return;
      ll p = 1;
      for (int v : cur) p *= (v+1);
      if (p > prod)
        return;
      array<int,10> cnt{};
      for (int v : cur) cnt[v]++;
      if (p == prod) {
        for (int j=0;j<n;j++){
          for (int d=0;d<A[j];d++){
            if (!cnt[d]) continue;
            cnt[d]--;
            ans += multin(cnt,n-j-1);
            cnt[d]++;
          }
          if (!cnt[A[j]])
            break;
          cnt[A[j]]--;
        }
      } else {
        ans += multin(cnt,n);
      }
      return;
    }
    for (int d=last;d<=9;d++){
      if (sum - d >= 0) {
        cur.push_back(d);
        self(self, i+1, sum-d,d);
        cur.pop_back();
      }
    }
  };
  dfs(dfs, 0, sum, 0);

  cout << ans << "\n";
}
