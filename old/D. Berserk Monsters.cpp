#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  for (int i=0;i<n;i++){
    cin >> B[i];
  }
  set<int> rem;
  for (int i=0;i<n;i++){
    rem.insert(i);
  }
  set<int> todo;
  for (int i=0;i<n;i++){
    todo.insert(i);
  }
  vector<int> ans(n);
  int cur = 0;
  while (!todo.empty() && cur < n) {
    set<int> rmv;
    auto check = [&](int i) {
      auto it = rem.find(i);
      ll dmg = 0;
      if (it != rem.begin()) {
        dmg += A[*prev(it)];
      }
      if (next(it) != rem.end()) {
        dmg += A[*next(it)];
      }
      if (dmg > B[i]) {
        rmv.insert(i);
        return true;
      }
      return false;
    };
    set<int> next_todo;
    for (int i : todo) {
      auto it = rem.find(i);
      if (it == rem.end()) continue;
      if (check(i)) {
        if (it != rem.begin())
          next_todo.insert(*prev(it));
        if (next(it) != rem.end()) 
          next_todo.insert(*next(it));
      }
      if (it != rem.begin()) {
        if (check(*prev(it)))
          next_todo.insert(i);
      }
      if (next(it) != rem.end()) {
        if (check(*next(it)))
          next_todo.insert(i);
      }
    }
    todo = next_todo;
    ans[cur++] = rmv.size();
    for (int i : rmv) {
      rem.erase(i);
      todo.erase(i);
    }
  }
  for (int i=0;i<n;i++){
    cout << ans[i] << " ";
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
