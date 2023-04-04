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

void solve() {
  pair<ll,ll> h = {-1,-1};
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a,b,n;
      cin >> a >> b >> n;
      pair<ll,ll> newi = {(ll)(a-b)*(n-1), a + (ll)(a-b)*(n-1)};
      if (n != 1) {
        pair<ll, ll> remove = {(ll)(a-b)*(n-2), a+(ll)(a-b)*(n-2)};
        newi.first = max(remove.second+1, newi.first);
      }

      if (h.first == -1) {
        h = newi;
        cout << 1 << " ";
      } else {
        if (h.first <= newi.second && newi.first <= h.second) {
          h.first = max(h.first, newi.first);
          h.second = min(h.second, newi.second);
          cout << 1 << " ";
        } else {
          cout << 0 << " ";
        }
      }
    } else {
      int a,b;
      cin >> a >> b;
      if (h.first == -1) {
        cout << -1 << " ";
        continue;
      }
      ll km = h.first <= a ? 0 : (h.first-a+a-b-1)/(a-b);
      ll km2 = h.second <= a ? 0 : (h.second-a+a-b-1)/(a-b);
      if (km != km2) {
        cout << -1 << " ";
      } else {
        cout << km + 1 << " ";
      }
    }
  }
  cout << "\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--)
    solve();
}
