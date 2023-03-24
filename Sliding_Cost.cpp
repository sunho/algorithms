#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  multiset<int> L, R;
  ll l_sum = 0, r_sum = 0;
  int inf = 1e9;
  L.insert(-inf);
  R.insert(inf);
  vector<int> A(n);
  auto balance = [&]() {
    if (L.size() > R.size() + 1) {
      int c = *--L.end();
      l_sum -= c;
      r_sum += c;
      L.erase(--L.end());
      R.insert(c);
    }
    if (L.size() < R.size()) {
      int c = *R.begin();
      r_sum -= c;
      l_sum += c;
      R.erase(R.begin());
      L.insert(c);
    }
  };
  auto add = [&](int c) {
    if (c >= *R.begin()) {
      R.insert(c);
      r_sum += c;
    } else {
      L.insert(c);
      l_sum += c;
    }
    balance();
  };
  auto remove = [&](int c) {
    if (c >= *R.begin()) {
      R.erase(R.find(c));
      r_sum -= c;
    } else {
      L.erase(L.find(c));
      l_sum -= c;
    }
    balance();
  };
 
  ll cur = 0;
  for (int i=0;i<n;i++){
    cin >> A[i];
    if (i < k) {
      add(A[i]);
    }
  }
  for (int i=0;i<n-k+1;i++){
    int mid = *--L.end();
    cout << (r_sum - (R.size()-1)*mid) + ((L.size()-1)*mid - l_sum) << " ";
    remove(A[i]);
    add(A[i+k]);
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
