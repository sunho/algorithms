#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define lb(x,a) (int)(lower_bound(all((x)),(a)) - (x).begin())
#define ub(x,a) (int)(upper_bound(all((x)),(a)) - (x).begin())
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  for(int i=0;i<n;i++) cin >> A[i];
  for(int i=0;i<n;i++) cin >> B[i];
  vector<int> a_pos(n);
  vector<int> b_pos(n);
  map<int,int> b_mp;
  map<int,int> a_mp;
  for(int i=0;i<n;i++){
    if (!b_mp.count(B[i])){
      b_mp[B[i]] = i;
    }
    if (!a_mp.count(A[i])){
      a_mp[A[i]] = i;
    } 
  }
  for(int i=0;i<n;i++){
    if (!b_mp.count(A[i])) {
      a_pos[i] = n;
    } else {
      a_pos[i] = b_mp[A[i]];
    }
    if (i != 0) {
      a_pos[i] = max(a_pos[i-1],a_pos[i]);
    }
    if (!a_mp.count(B[i])) {
      b_pos[i] = n;
    } else {
      b_pos[i] = a_mp[B[i]];
    }
    if (i != 0) {
      b_pos[i] = max(b_pos[i-1],b_pos[i]);
    }
  }
  int q;
  cin >> q;
  while (q--){
    int a,b;
    cin >> a >> b;
    --a,--b;
    if (a_pos[a] > b || b_pos[b] > a){
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }
  }

}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  solve();

  return 0;
}
