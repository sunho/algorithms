#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int win = 0, lose = 0;
  for (int x=1;x<=n;x++){
    for (int y=1;y<=n;y++){
      int cur_a = 0, cur_b = 0;
      int win_a = 0, win_b = 0;
      for (int i=0;i<n;i++){
        if (s[i] == 'A')  {
          cur_a++;
        } else {
          cur_b++;
        }
        if (cur_a == x) {
          win_a++;
          cur_a = 0, cur_b = 0;
        }
        if (cur_b == x) {
          win_b++;
          cur_a = 0, cur_b = 0;
        }
        if (win_a == y) {
          if (i == n-1) {
            win++;
          } else {
            break;
          }
        }
        if (win_b == y) {
          if (i == n-1) {
            lose++;
          } else {
            break;
          }
        }
      }
    }
  }
  if (lose == 0) {
    cout << "A" << "\n";
  } else if (win == 0) {
    cout << "B" << "\n";
  } else {
    cout << "?" << "\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--){
    solve();
  }
}
