#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  map<int,int> B;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    A[i]--;
    B[A[i]] = i;
  }
  const int inf = 1e9;
  vector<int> rem(n);
  priority_queue<pair<int,int>> pq;
  for (int i=1;i<n;i++) {
    pq.push({-A[i],i});
    rem[i] = i;
  }
  sort(begin(A),end(A));
  int cur = 0;
  vector<int> ans;
  for (int i=0;i<n*n;i++) {
    if (cur != n && A[cur] == i) {
      cur++;
      if (rem[B[i]]) {
        cout << "No";
        return 0;
      }
      ans.push_back(B[i]);
      rem[B[i]] = n-B[i]-1;
      if (rem[B[i]])
        pq.push({-inf,B[i]});
    } else {
      if (pq.empty()) {
        cout << "No" << "\n";
        return 0;
      }
      auto [_, c] = pq.top();
      rem[c]--;
      ans.push_back(c);
      if (rem[c] == 0) {
        pq.pop();
      }
    }
  }
  cout << "Yes" << "\n";
  for (int a : ans) {
    cout << a + 1 << " ";
  }
}
