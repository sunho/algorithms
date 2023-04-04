#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n-2);
  vector<int> deg(n);
  for (int i=0;i<n-2;i++){
    cin >> A[i];
    A[i]--;
    deg[A[i]]++;
  }
  deg[A[n-3]]++;
  set<int> cur;
  for (int i=0;i<n;i++){
    if (deg[i] == 0) {
      cur.insert(i);
    }
  }
  for (int i=0;i<n-2;i++){
    int k = *cur.begin();
    cout << k+1 << " " << A[i]+1 << "\n";
    cur.erase(k);
    deg[A[i]]--;
    if (deg[A[i]] == 0) {
      cur.insert(A[i]);
    }
  }
  cout << *cur.begin()+1 << " " << A[n-3]+1 << "\n";
}
