#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  sort(begin(A), end(A));
  int limi = A[n-1] - A[0];
  multiset<int> rem;
  for (int i=0;i<n;i++){
    rem.insert(A[i]);
  }
  pair<int,int> balance;
  vector<int> ans;
  if (abs(A[n-1]) > A[0]) {
    balance = {max(A[n-1],0), min(A[n-1],0)};
    ans.push_back(A[n-1]);
    rem.erase(rem.find(A[n-1]));
  } else {
    balance = {max(A[0],0), min(A[0],0)};
    ans.push_back(A[0]);
    rem.erase(rem.find(A[0]));
  }
  while (!rem.empty()) {
    auto it = rem.upper_bound(-balance.first);
    if (it != rem.begin()) {
      --it;
    }
    auto jt = rem.lower_bound(-balance.second);
    if (jt == rem.end()) {
      --jt;
    }
    int a = *it, b = *jt;
    pair<int,int> canda = {max({balance.first + a, 0}),min({balance.second + a, 0})};
    pair<int,int> candb = {max({balance.first + b, 0}),min({balance.second + b, 0})};
    if (canda.first - canda.second < candb.first - candb.second) {
      rem.erase(it);
      balance = canda;
    } else {
      a = b;
      rem.erase(jt);
      balance = candb;
    }
    ans.push_back(a);
    if (balance.first >= limi) {
      cout << "No" << "\n";
      return;
    }
    if (-balance.second >= limi) {
      cout << "No" << "\n";
      return;
    }
  }
  if (balance.first >= limi) {
    cout << "No" << "\n";
    return;
  }
  if (-balance.second >= limi) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--)
    solve();
}
