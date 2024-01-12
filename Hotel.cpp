#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int,int>> A(n);
  vector<pair<int,int>> B(m);
  for (int i=0;i<n;i++){
    cin >> A[i].second >> A[i].first;
  }
  for (int i=0;i<m;i++){
    cin >> B[i].second >> B[i].first;
  }
  
  sort(begin(A),end(A));
  sort(begin(B),end(B));
  int ptr = 0;
  int ptr2 = 0;
  multiset<int> cur;
  vector<int> ans;
  for (int i=0;i<n;i++){
    int y = A[i].first;
    while (ptr2 < m && B[ptr2].first <= y) {
      cur.insert(B[ptr2].second);
      ptr2++;
    }
    while (!cur.empty() && *--cur.end() <= A[i].second) {
      cur.erase(--cur.end());
    }
    if (!cur.empty()) {
      ans.push_back(*--cur.end() - A[i].second);
      cur.erase(--cur.end());
    }
  }
  sort(rbegin(ans),rend(ans));
  ll fin = 0;
  for (int i=0;i<min(k,(int)ans.size());i++){
    fin += ans[i];
  }
  cout << fin << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
