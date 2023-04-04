#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  set<int> S;
  for (int i=0;i<n;i++) S.insert(A[i]);
  for (int i=n-1;i>=0;i--) {
    if (S.count(A[i]-x) || S.count(A[i]+x)) {
      cout << "Yes";
      return 0;
    }
  }
  

  cout << "No";
}
