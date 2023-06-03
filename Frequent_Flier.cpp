#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> flights(n);

  for (int i=0;i<n;i++){
    cin >> flights[i];
  }

  vector<int> used(n);
  deque<int> unfinished;
  ll cur = 0;
  for (int i=0;i<n+m-1;i++){
    if (i >= m) {
      if (!unfinished.empty() && i - unfinished.front() == m) {
        unfinished.pop_front();
      }
      cur -= used[i-m];
    }
    if (i < n) unfinished.push_back(i);
    while (!unfinished.empty() && cur < k) {
      int b = unfinished.back();
      int rem = flights[b] - used[b];
      int add = 0;
      if (rem > k-cur) {
        add = k-cur;
      } else {
        add = rem;
      }
      used[b] += add;
      cur += add;
      if (used[b] == flights[b]) {
        unfinished.pop_back();
      }
    }
  }
  ll ans = 0;
  for (ll x : used) ans += x;
  cout << ans;
}
