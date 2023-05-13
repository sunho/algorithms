#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  const int N = 16;
  vector<ll> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  sort(begin(A), end(A));
  vector<string> S(n);
  for (int i=0;i<n;i++) {
    S[i] = to_string(A[i]);
  }
  vector<ll> done;
  ll ten = 1;
  ll ans = 0;
  for (int i=0;i<N;i++){
    array<vector<ll>,10> digits{};
    for (int j=0;j<n;j++){
      if (S[j].size() < i) continue;
      if (S[j].size() == i) {
        done.push_back(A[j]);
        continue;
      }
      int m = S[j].size();
      int d = S[j][m-i-1] - '0';
      ll cur = i == 0 ? 0ll :  stoll(S[j].substr(m-i));
      digits[d].push_back(cur);
    }
    for (int j=0;j<10;j++){
      sort(begin(digits[j]), end(digits[j]));
    }
    sort(begin(done), end(done));
    for (int j=0;j<n;j++){
      if (S[j].size() > i) {
        int m = S[j].size();  
        int d = S[j][m-i-1] - '0';
        ll cur = i == 0 ? 0ll : stoll(S[j].substr(m-i));
        for (int k=0;k<10;k++){
          auto& arr = digits[k];
          int carry = arr.end() - lower_bound(begin(arr), end(arr), ten-cur);
          ans += carry * ((k+d+1)%10);
          ans += (arr.size()-carry)*((k+d)%10);
        }
        int carry2 = done.end() - lower_bound(begin(done), end(done), ten-cur);
        ans += carry2 * ((d+1)%10);
        ans += (done.size()-carry2)*d;
      } else {
        for (int k=0;k<10;k++){
          auto& arr = digits[k];
          int carry = arr.end() - lower_bound(begin(arr), end(arr), ten-A[j]);
          ans += carry * ((k+1)%10);
          ans += (arr.size()-carry)*k;
        }
        int carry2 = done.end() - lower_bound(begin(done), end(done), ten-A[j]);
        ans += carry2;
      }
    }

    ten *= 10;
  }
  
  cout << ans << "\n";
}
