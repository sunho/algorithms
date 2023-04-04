#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  ll sum = (ll)n*(n+1)/2;
  if (sum % 2) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  vector<int> A,B;
  if (n%2) {
    A.push_back(1);
    A.push_back(2);
    B.push_back(3);
    for (int i=0;i<(n-3)/2;i++) {
      if (i%2) {
        A.push_back(i+4);
        A.push_back(n-i);
      } else {
        B.push_back(i+4);
        B.push_back(n-i);
      }
    }
  } else {
    for (int i=0;i<n/2;i++) {
      if (i%2) {  
        A.push_back(i+1);
        A.push_back(n-i);
      } else {
        B.push_back(i+1);
        B.push_back(n-i);
      }
    }
  }
  cout << A.size() << "\n";
  for (auto x : A) cout << x << " ";
  cout << "\n";
  cout << B.size() << "\n";
  for (auto x : B) cout << x << " ";
  cout << "\n";
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
