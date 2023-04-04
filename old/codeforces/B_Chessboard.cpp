#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  array<array<char, 8>, 8> A;
  for (int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      cin >> A[i][j];
      if (A[i][j] == '*') {
        cout << (char)(j + 'a') << (char)((8-i-1) + '1') << "\n";
      }
    }
  }
  
}
