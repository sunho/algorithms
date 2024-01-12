#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  vector<int> A = {425, 450, 495, 570, 590, 620, 781};
  vector<string> B = {"Violet", "Indigo", "Blue", "Green",
                      "Yellow", "Orange", "Red"};
  int x;
  cin >> x;
  for (int i = 0; i < A.size(); i++) {
    if (x < A[i]) {
      cout << B[i];
      return;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
