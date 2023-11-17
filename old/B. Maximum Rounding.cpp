#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int last = 0;
    int last_round = n;
    for (int i=n-1;i>=0;i--){
      int d = s[i] - '0';
      if (last_round == i) {
        d++;
      }
      if (d >= 5)
        last_round = i-1;
    }
    if (last_round == -1) {
      cout << 1;
      for (int i=0;i<n;i++) cout << 0;
      cout << "\n";
      continue;
    }
    for (int i=0;i<last_round;i++){
      cout << s[i];
    }
    if (last_round != n)
      cout << (char)(s[last_round] + 1);
    for (int i=last_round+1;i<n;i++)
      cout << 0;
    cout << "\n";
  }
}
