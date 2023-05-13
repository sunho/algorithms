#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<char>> A(n, vector<char>(n));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      char c;
      cin >> c;
      A[i][j] = c;
    }
  }
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i==j) continue;
      if ((A[i][j] == 'W' && A[j][i] != 'L') ||
        (A[i][j] == 'L' && A[j][i] != 'W') ||
        (A[i][j] == 'D' && A[j][i] != 'D')
      ) {
        cout << "incorrect" << "\n";
        return 0;
      }
    }
  }
  cout << "correct" << "\n";
}
