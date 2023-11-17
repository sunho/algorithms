#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  vector<set<ll>> S(n);
  int cur = 0;
  ll cur_sum = 0;
  ll global_sum = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    S[i].insert(A[i]);
    cur_sum ^= 1;
  }
  if (!cur_sum) {
    cur ^= 1;
  }
  bool done = false;
  for (int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    --u,--v;
    cur_sum ^= S[u].size();
    cur_sum ^= S[v].size();
    if (S[u].size() < S[v].size()) {
      for (ll a : S[u]) {
        S[v].insert(a);
      }
      S[u].clear();
    } else {
      for (ll a : S[v]) {
        S[u].insert(a);
      }
      swap(S[u],S[v]);
      S[u].clear();
    }
    cur_sum ^= S[v].size();
    if (S[v].size() != 1) {
      done = true;
    }
    if (done) {
      if (!cur_sum) {
        cur ^= 1;
      } else {
        break::
      }
    } else {
      if (!cur_sum) {
        cur ^= 1;
      }
    }
  }
  if (!cur) {
    cout << "Sejong" << "\n";
  } else {
    cout << "Areum" << "\n";
  }
}
