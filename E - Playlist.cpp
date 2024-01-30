#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  map<int,int> A;
  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    A[i] = a;
  }
  set<int> todo;
  for (int i=0;i<n;i++){
    todo.insert(i);
  }
  vector<int> ans;
  while (!todo.empty()) {
    set<int> ntodo; 
    for (int i : todo) {
      if (!A.count(i)) continue;
      auto it = A.find(i);
      int a = it->second;
      auto jt = next(it);
      if (jt == A.end()) {
        jt = A.begin();
      }
      int b = jt->second;
      if (gcd(a,b) == 1) {
        ans.push_back(jt->first);
        A.erase(jt);
        ntodo.insert(i);
      }
    }
    todo = ntodo;
  }
  cout << ans.size() << " ";
  for (int a : ans) {
    cout << a + 1 << " ";
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}
