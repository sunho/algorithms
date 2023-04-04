#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  ll k;
  cin >> n >> k;
  ll cur = 0;
  deque<int> ans;
  int i = 0;
  while (cur < k) {
    ll rem = k - cur;
    if (rem <= i) {
      ans.insert(ans.begin() + (i-rem), i+1);
      i++;
      break;
    }
    ans.push_front(i+1);
    cur += i;
    i++;
  }
  for (;i<n;i++){
    ans.push_back(i+1);
  }
  for (int v : ans) {
    cout << v << " ";
  }
}
