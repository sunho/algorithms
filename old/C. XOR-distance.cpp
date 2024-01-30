#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  ll a,b,r;
  cin >> a >> b >> r;
  auto work = [&](ll a, ll b) {
    ll ans = 0;
    bool flag = false;
    for (int i=62;i>=0;i--){
      bool a_set = (a>>i&1);
      bool b_set = (b>>i&1);
      if (!flag) {
        if (!a_set && b_set) {
          if (!flag) {
            if ((ans + (1ll<<i)) <= r) {
              ans += 1ll<<i;
            }
          }
          flag = true;
          continue;
        } else if (a_set && !b_set) {
          flag = true;
          continue;
        }
      }
      if (a_set && !b_set) {
        if ((ans + (1ll<<i)) <= r) {
          ans += 1ll<<i;
        }
      }
    }
    return abs((a^ans) - (b^ans));
  };
  cout << min(work(a,b), work(b,a)) << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}

// 101000110100001100101110001100110010101101010101010010111100
// 110010111000110110011001001100000111001110101010101000010011
//    101110011000101001000111111001010011100000000000101010001
//    
//  11010001100111010110111000000110101100011111111111010101111
