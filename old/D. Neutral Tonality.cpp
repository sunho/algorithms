#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  vector<int> B(m);
  for (int i=0;i<m;i++){
    cin >> B[i];
  }
  auto D = A;
  if (is_sorted(rbegin(A),rend(A))) {
    vector<int> C;
    for (int i=0;i<n;i++){
      C.push_back(A[i]);
    }
    for (int i=0;i<m;i++){
      C.push_back(B[i]);
    }
    sort(rbegin(C),rend(C));
    for (int c : C) {
      cout << c << " ";
    }
    cout << "\n";
  } else {
    sort(begin(B),end(B));
    int mx = 0;
    int ptr = 0;
    deque<int> ans;
    for (int i=n-1;i>=0;i--){
      mx = max(A[i],mx);
      for (;ptr<m;ptr++){
        if (B[ptr] <= mx) {
          ans.push_back(B[ptr]);
        } else {
          break;
        }
      }
      ans.push_back(A[i]);
    }
    for (;ptr<m;ptr++){
      ans.push_back(B[ptr]);
    }
    reverse(begin(ans),end(ans));
    for (int c : ans) {
      cout << c << " ";
    }
    cout << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
