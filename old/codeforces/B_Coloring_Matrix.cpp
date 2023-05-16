#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> rotate(const vector<vector<int>>& vec) {
  int n = vec.size();
  vector<vector<int>> res(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      res[j][n-i-1] = vec[i][j];
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  vector<vector<int>> B(n, vector<int>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> A[i][j];
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> B[i][j];
    }
  }
  auto check = [&]() {
    bool ok = true;
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        if (A[i][j] && !B[i][j]) {
          ok = false;
        }
      }
    }
    return ok;
  };
  for (int i=0;i<4;i++){
    if (check()) {
      cout << "Yes" << "\n";
      return 0;
    }
    A = rotate(A);
  }
  cout << "No" << "\n";
}
