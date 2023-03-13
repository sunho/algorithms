#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using lll = __int128;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef tree<
pair<ll,int>,
null_type,
less<pair<ll,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ll iceil(ll a,ll b){
	ll res=a/b;
	if(b*res!=a)res+=(a>0)&(b>0);
	return res;
}

void solve() {
  int q;
  cin >> q;
  set<ll> zeroes;
  int minus = 0;
  bool all_zero = false;
  ordered_set pos;
  ordered_set neg;
  int b_min = 0;
  int id=0;
  while(q--) {  
    int c;
    cin >> c;
    if (c == 1) {
      ll a,b;
      cin >> a >> b;
      if (a == 0) {
        if (b == 0) {
          all_zero = true;
        }
        if (b < 0) {
          minus++;
        }
        continue;
      }
      if (b%a == 0) {
        zeroes.insert(-b/a);
      }
      if (a > 0) {
        pos.insert({iceil(-b,a),id++});
      } else {
        neg.insert({-b/a,id++});
      }
      if (b<0) {
        b_min ++;
      }
    } else {
      ll x;
      cin >> x;
      if (all_zero) {
        cout << 0 << "\n";
        continue;
      }
      if (zeroes.count(x)) {
        cout << 0 << "\n";
        continue;
      }
      if (x == 0) {
        if (b_min % 2 == 0) {
          cout << '+' << "\n";
        } else {
          cout << '-' << "\n";
        }
        continue;
      }
      int mm = minus;
      int k1 = pos.size() - pos.order_of_key({x, 1e9});
      int k2 = neg.order_of_key({x, 0});
      mm += k1;
      mm += k2;
      if (mm % 2 == 0) {
        cout << '+' << "\n";
      } else {
        cout << '-' << "\n";
      }
    }
  }
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
