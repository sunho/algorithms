#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n) {
  string s = to_string(n);
  int table[] = {1,0,0,0,1,0,1,0,2,1};
  int sum = 0;
  for (int i=0;i<s.size();i++){
    sum += table[s[i]-'0'];
  }
  return sum;
}

void solve() {
  int x,k;
  cin >> x >> k;
  for (int i=0;i<k;i++){
    if (x == 0) {
      x = (k-i)%2;
      break;
    } else {
      x = f(x);
    }
  }
  cout << x << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}
