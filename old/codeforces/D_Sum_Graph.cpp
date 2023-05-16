#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << "! 1 2 2 1" << endl;
    int c;
    cin >> c;
    return;
  }

  auto connect = [&](int x) {
    cout << "+ " << x << endl;
    int c;
    cin >> c;
  };

  connect(n+1);
  connect(n+2);

  auto query = [&](int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int d;
    cin >> d;
    return d;
  };

  vector<int> dist(n);
  for (int i=1;i<n;i++){
    dist[i] = query(0, i);
  }
  int mi = max_element(begin(dist), end(dist)) - begin(dist);
  vector<int> dist2(n);
  dist2[0] = dist[mi];
  for (int i=0;i<n;i++){
    if (i == mi) continue;
    if (i == 0) continue;
    dist2[i] = query(mi, i);
  }
  vector<int> id(n);
  iota(begin(id), end(id), 0);
  sort(begin(id), end(id), [&](int i, int j) {
    return dist2[i] < dist2[j];
  });
  auto construct = [&](auto& cand) -> vector<int> {
    vector<int> res(n);
    for (int i=0;i<n;i++) {
      if (i%2 == 0) res[i/2] = cand[i];
      else res[n-i/2-1] = cand[i];
    }
    return res;
  };
  auto invert = [&](const auto& A) -> vector<int> {
    vector<int> res(n);
    iota(begin(res), end(res), 0);
    for (int i=0;i<n;i++){
      res[A[i]] = i;
    }
    return res;
  };
  auto ans1 = invert(construct(id));
  reverse(begin(id), end(id));
  auto ans2 = invert(construct(id));
  cout << "! ";
  for (int i=0;i<n;i++){
    cout << ans1[i]+1  << " ";
  }
  for (int i=0;i<n;i++){
    cout << ans2[i]+1 << " ";
  }
  cout << endl;
  int c;
  cin >> c;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
