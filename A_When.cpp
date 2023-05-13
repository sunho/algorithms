#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  int t = 1260 + n;
  int h = t / 60;
  int m = t % 60;
  cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << "\n";
 }
