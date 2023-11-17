#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  deque<int> A(n);
  for (int i=0;i<n;i++)
    cin >> A[i];
  vector<int> id(n);
  iota(begin(id),end(id),0);
  sort(begin(id), end(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  sort(begin(A), end(A));
  vector<int> pos;
  vector<int> neg;
  for (int a=n;a>=1;a--){
    if (A.front() - pos.size() == 0 && A.back() - pos.size() == a) {
      cout << "NO" << "\n";
      return;
    }
    if (A.front() - pos.size() == 0) {
      neg.push_back(-a);
      A.pop_front();
    } else if (A.back() - pos.size() == a) {
      pos.push_back(a);
      A.pop_back();
    } else {
      cout << "NO" << "\n";
      return;
    }
  }
  reverse(begin(pos), end(pos));
  vector<int> B(begin(neg), end(neg));
  B.insert(B.end(), pos.begin(), pos.end());
  vector<int> ans(n);
  for (int i=0;i<n;i++){
    ans[id[i]] = B[i];
  }
  cout << "YES" << "\n";
  for (int a : ans) 
    cout << a << " ";
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
