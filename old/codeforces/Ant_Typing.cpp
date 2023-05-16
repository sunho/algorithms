#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  const int n = s.size();
  map<pair<int,int>, int> cnt;
  for (int i=0;i<n-1;i++){
    int d = s[i]-'0', d2 = s[i+1]-'0';
    cnt[{d,d2}]++;
  }
  ll ans = 1e18;
  vector<int> keys(9);
  iota(keys.begin(), keys.end(), 0);
  do {
    ll cand = n + keys[s[0]-'0'-1];
    for (auto [key,c] : cnt) {
      auto [d,d2] = key;
      cand += abs((ll)keys[d-1] - keys[d2-1])*c;
    }
    ans = min(ans, cand);
  } while (next_permutation(keys.begin(), keys.end()));
  cout << ans << "\n";
}
