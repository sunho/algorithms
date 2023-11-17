#include <bits/stdc++.h>

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  
  vector<int> A(k);
  for (int i=0;i<k;i++) {
    cin >> A[i];
  }
  
  set<int> rem;
  for (int i=1;i<=n;i++) {
    rem.insert(i);
  }

  vector<int> ans;
  for (int i=0;i<k-1;i++) {
    if (A[i] != *rem.begin()) {
      ans.push_back(A[i]);
      rem.erase(A[i]);
    }
    ans.push_back(*rem.begin());
    rem.erase(rem.begin());
  }
  for (auto it = rem.rbegin(); it != rem.rend(); ++it) {
    ans.push_back(*it);
  }
  for (int a : ans) {
    cout << a << " " ;
  }
  
}
