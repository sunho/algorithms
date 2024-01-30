#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  map<int,int> S;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    S[i] = A[i];
  }
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id),end(id),[&](int i, int j) {
    return A[i] > A[j];
  });
  bool yes = true;
  for (int i : id) {
    if (!S.count(i)) continue;
    auto it = S.find(i);
    while (it != S.begin() && prev(it)->second == it->second+1) {
      S.erase(prev(it));
    }
    while (next(it) != S.end() && next(it)->second == it->second+1) {
      S.erase(next(it));
    }
  }
  if (S.size() != 1 || S.begin()->second != 0) {
    yes = false;
  }
  if (yes) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
