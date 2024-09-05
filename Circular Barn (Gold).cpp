#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// int128_t output
istream &operator>>(istream &is, __int128_t &v) {
  string s;
  is>>s;
  v=0;
  for(auto &it:s) if(isdigit(it)) v=v*10+it-'0';
  if(s[0]=='-') v*=-1;
  return is;
}

ostream &operator<<(ostream &os,const __int128_t &v) {
  if(v==0) return (os<<"0");
  __int128_t num=v;
  if(v<0) os<<'-',num=-num;
  string s;
  for(;num>0;num/=10) s.push_back((char)(num%10)+'0');
  reverse(begin(s),end(s));
  return (os<<s);
}


void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i=0;i<n;i++){
    cin >> A[i];
  }
  int pf = 0;
  pair<int,int> st = {0,n};
  for (int i=0;i<n;i++){
    pf += A[i]-1;
    if (A[i] == 0) {
      st = min(st, {pf, i});
    }
  }
  rotate(begin(A),begin(A)+((st.second+1)%n), end(A));
  int lst = n-1;
  __int128_t ans = 0;
  for (int i=n-1;i>=0;i--){
    if (A[i] == 0) {
      while (A[lst] == 0) {
        lst --;
      }
      A[lst]--;
      ans += (ll)(i-lst)*(i-lst);
      A[i] = 0;
    } else {
      A[i] = 0;
    }
  }
  cout << ans << "\n";
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();
}
