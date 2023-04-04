#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;

  int n = s.size();
  if (n < 4) {
    cout << 0 << "\n";
    return 0;
  }
  ll ans = 0;
  int state = 0;
  int L=0,R=0,pairs=0;
  int pair_state = 0;
  auto calc = [&]() {
    ll cand1 = 0;
    ll cand2 = 0;
    for (int i=0;i<(pairs/2);i++){
      cand1 += L+1+i*4;
      cand2 += R+1+i*4;
    }
    ans += max(cand1, cand2);
    cout << dbg(cand1) dbg(cand2) dbg(ans) << "\n";
    state=0,L=0,R=0,pairs=0,pair_state=0;
  };
  for (int i=0;i<n;i++){
    if (state == 0) {
      if (s[i] == '0') {
        L++;
      } else {
        if (L>=1) {
          state = 1;
          pairs++;
          pair_state = 0;
        }
      }
    } else if (state == 1) {
      if (s[i] == '0') {
        if (pair_state == 0) {
          pair_state = 1;
        } else {
          calc();
          L++;
        }
      } else {
        if (pair_state == 1) {
          pair_state = 0;
          pairs++;
        } else {
          state = 2;
          R++;
        }
      }
    } else {
      if (s[i] == '1') {
        R++;
      } else {
        calc();
        L++;
      }
    }
    cout << dbg(i) dbg(state) dbg(L) dbg(R) dbg(s[i]) dbg(pairs) << "\n";
  }
  calc();
  cout << ans << "\n";
}
