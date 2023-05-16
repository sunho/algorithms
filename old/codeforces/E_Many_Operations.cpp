#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, c;
  cin >> n >> c;

  vector<array<bool,2>> gates(30);
  for (int i=0;i<30;i++){
    gates[i][0] = 0;
    gates[i][1] = 1;
  }
  for (int i=0;i<n;i++){
    int t,x;
    cin >> t >> x;
    for (int j=0;j<30;j++){
      bool cur = x & (1<<j);
      if (t == 3) {
        gates[j][0] = cur ^ gates[j][0];
        gates[j][1] = cur ^ gates[j][1];
      } else if (t == 2) {
        gates[j][0] = cur | gates[j][0];
        gates[j][1] = cur | gates[j][1];
      } else {
        gates[j][0] = cur & gates[j][0];
        gates[j][1] = cur & gates[j][1];
      }
    }
    int nc = 0;
    for (int j=0;j<30;j++){
      nc |= (gates[j][(bool)(c & (1<<j))] << j);
    }
    c = nc;
    cout << c << "\n";
  }

}
