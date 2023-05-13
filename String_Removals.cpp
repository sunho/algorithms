#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  map<char,int> cnt;
  ll total = 0;  
  for (int i=0;i<s.size();i++){
    int old = (total+1) % MOD;
    total = (old + total - cnt[s[i]] + MOD) % MOD;
    cnt[s[i]] = old;
  }
  cout << total << "\n";
}
