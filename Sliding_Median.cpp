#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  multiset<int> L, R;
  int inf = 1e9;
  L.insert(-inf);
  R.insert(inf);
  vector<int> A(n);
  auto balance = [&]() {
    if (L.size() > R.size() + 1) {
      int c = *--L.end();
      L.erase(--L.end());
      R.insert(c);
    }
    if (L.size() < R.size()) {
      int c = *R.begin();
      R.erase(R.begin());
      L.insert(c);
    }
  };
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (i < k) {
      if (A[i] >= *R.begin()) {
        R.insert(A[i]);
      } else {
        L.insert(A[i]);
      }
      balance();
    }
  }
  for (int i=0;i<n-k+1;i++){
    cout << *--L.end() << " ";
    int remove = A[i];
    int add = A[i+k];
    if (remove >= *R.begin()) {
      R.erase(R.find(remove));
    } else {
      L.erase(L.find(remove));
    }
    balance();
    if (add >= *R.begin()) {
      R.insert(add);
    } else {
      L.insert(add);
    }
    balance();
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
