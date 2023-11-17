#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  auto sum = [&](string s) {
    int res = 0;
    for (char c : s) {
      res += c-'0';
    }
    return res;
  };
  map<int,map<int,int>> cnt;
  for (int i=0;i<n;i++){
    string s = A[i];
    cnt[s.size()][sum(A[i])]++;
  }
  
  long long ans = 0;
  for (int i=0;i<n;i++) {
    string s = A[i];
    for (int j=1;j<s.size();j++){
      if ((s.size() + j) % 2 == 0) {
        int len = (s.size()+j)/2;
        ans += cnt[j][sum(s.substr(0,len))-sum(s.substr(len))];
        auto t = s;
        reverse(begin(t),end(t));
        ans += cnt[j][sum(t.substr(0,len))-sum(t.substr(len))];
      }
    }
    ans += cnt[s.size()][sum(s)];
  }
  cout << ans << "\n";
}
