#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// sieves + lp
// works when N <= 10^7
// O(n log n) time
void sieves(int PN, vector<ll> &lp, vector<ll> &pr) {
  lp.assign(PN + 1, 0);
  for (int i = 2; i <= PN; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= PN;
         ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

void solve() {
  int n;
  cin >> n;

  const int N = 1e7;
  vector<ll> lp, pr;
  sieves(N, lp, pr);


  for (int i=0;i<n;i++){
    string s;
    cin >> s;
    int ans= 0;
    do {
      int k = stoi(s);
      if (lp[k] == k && k != 1) {
        ans ++;
      }
    } while(next_permutation(begin(s),end(s)));
    cout << ans <<"\n";
  }

}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
