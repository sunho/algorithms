#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);

  for (int i = 0; i < n; i++)
    cin >> A[i];
  cout << max(0, *std::max_element(begin(A) + 1, end(A)) + 1 - A[0]) << "\n";
}
