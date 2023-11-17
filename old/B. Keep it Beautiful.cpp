#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A;
    bool lower = false;
    for (int i=0;i<n;i++){
      int a;
      cin >> a;
      if (A.empty()) {
        A.push_back(a);
        cout << "1";
        continue;
      }
      if (!lower) {
        if (A.back() <= a) {
          A.push_back(a);
          cout << "1";
        } else if (a <= A[0]) {
          A.push_back(a);
          cout << "1";
          lower = true;
        } else {
          cout << "0";
        }
      } else {
        if (A.back() <= a && a <= A[0]) {
          A.push_back(a);
          cout << "1";
        } else {
          cout << "0";
        }
      }
    }
    cout << "\n";
  }
}
