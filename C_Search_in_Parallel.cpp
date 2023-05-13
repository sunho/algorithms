#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n,s1,s2;
  cin >> n >> s1 >> s2;
  vector<int> R(n);
  for (int i=0;i<n;i++){
    cin >> R[i];
  }
  vector<int> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) {
    return R[i] < R[j];
  });
  sort(begin(R), end(R));
  vector<int> S1,S2;
  while (!R.empty()) {
    if ((ll)R.back() * s1 * (S1.size()+1) <= (ll)R.back() * s2 * (S2.size()+1)) {
      S1.push_back(id.back());
    } else {
      S2.push_back(id.back());
    }
    id.pop_back();
    R.pop_back();
  }
  cout << S1.size() << " ";
  for (int v : S1) {
    cout << v + 1 << " ";
  }
  cout << "\n";

  cout << S2.size() << " ";
  for (int v : S2) {
    cout << v + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--)
    solve();
}
