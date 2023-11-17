#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> T(n+2), V(n+2);
  for (int i=1;i<=n;i++){
    cin >> T[i];
  }
  for (int i=1;i<=n;i++){
    cin >> V[i];
  }
  T[0] = 0;
  V[0] = 0;
  T[n+1] = 0;
  V[n+1] = 0;
  n+=2;
  for (int i=0;i<n;i++) {
    T[i] *= 2;
  }
  for (int i=1;i<n;i++) {
    T[i] += T[i-1];
  }
  for (int i=0;i<n;i++) {
    V[i] *= 2;
  }
  long long ans = 0;
  int tend = T.back();
  for (int i=0;i<tend;i++) {
    int max_speed = 200;
    for (int j=0;j<n;j++) {
      if (i > T[j]) {
        max_speed = min(max_speed, (i-T[j])+V[j]);
      } else if (i != 0 && i < T[j-1]) {
        max_speed = min(max_speed, (T[j-1]-i)+V[j]);
      } else {
        max_speed = min(max_speed, V[j]);
      }
    }
    ans += max_speed;
  }
  cout << setprecision(15) << fixed << ans / 4.0 << "\n";
}
