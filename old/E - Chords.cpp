#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> A(2*n);
  int id = 0;
  for (int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    --l,--r;
    if (l > r) 
      swap(l,r);
    A[l] = id;
    A[r] = id;
    id++;
  }
  vector<int> vis(n);
  vector<int> st;
  for (int i=0;i<2*n;i++)  {
    if (vis[A[i]]) {
      if (st.back() != A[i]) {
        cout << "Yes" << "\n";
        return;
      }
      st.pop_back();
    } else {
      vis[A[i]] = true;
      st.push_back(A[i]);
    }
  }
  cout << "No" << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
