#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i=0;i<n;i++)
      cin >> A[i];
    for (int i=0;i<n;i++)
      cin >> B[i];
    vector<int> C(n);
    for (int i=0;i<n;i++)
      C[i] = A[i] - B[i];
    int mx = *max_element(begin(C), end(C));
    vector<int> ans;
    for (int i=0;i<n;i++){
      if (C[i] == mx)
        ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int a : ans)
      cout << a + 1 << " ";
    cout << "\n";
  }
}
