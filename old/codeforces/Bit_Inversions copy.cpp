#include <bits/stdc++.h>
#include <cfloat>
using namespace std;
using ll = long long;

#define dbg(x) "(" << #x <<": " << (x) << ") "
template<class TupType, size_t... I>
void print(ostream& os, const TupType& _tup, std::index_sequence<I...>)
{
    os << "{";
    (..., (os << (I == 0? "" : ", ") << std::get<I>(_tup)));
    os << "}";
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const tuple<Ts...>& p){
	print(os, p, std::make_index_sequence<sizeof...(Ts)>());
  return os;
}
template<typename ...Ts>
ostream& operator<<(ostream& os, const pair<Ts...>& p){
	return os<<"{"<<p.first<<", "<<p.second<<"}";
}
template<typename Ostream, typename Cont>
enable_if_t<is_same_v<Ostream,ostream>, Ostream&> 
operator<<(Ostream& os, const Cont& v){
	os<<"[";
	for(auto& x:v){os<<x<<", ";}
	return os<<"]";
}



int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  string s;
  cin >> s;
  set<tuple<int,int,int>> islands;
  set<pair<int,int>> pq;
  int ans = 0;
  for (int l=0;l<s.size();) {
    int start = l;
    char c = s[l++];
    int cnt = 1;
    while (l < s.size() && s[l] == c) {
      cnt++;
      l++;
    }
    islands.insert({start, c-'0', cnt});
    pq.insert({cnt, start});
  }
  
  int q;
  cin >> q;
  while (q--) {
    int k;
    cin >> k;
    --k;
    auto it = --islands.upper_bound({k,3,0});
    auto [i,b,cnt] = *it;
    if (i == k) {
      auto kt = it != islands.end() ? next(it) : islands.end();
      auto jt = it;
      if (it != islands.begin()) {
        jt = prev(it);
        islands.erase({i,b,cnt});
        pq.erase({cnt,i});
        auto [j,_,cnt2] = *jt;
        islands.erase({j,b^1,cnt2});
        pq.erase({cnt2,j});
        jt = islands.insert({j,b^1,cnt2+1}).first;
        pq.insert({cnt2+1,j});
      } else {
        islands.erase({i,b,cnt});
        pq.erase({cnt,i});
        jt = islands.insert({i,b^1,1}).first;
        pq.insert({1,i});
      }
      if (kt != islands.end()) {
        auto [z, b3, cnt3] = *kt;
        if (b3 == (b^1)) {
          auto [j,_,cnt2] = *jt;
          islands.erase({z,b3,cnt3});
          pq.erase({cnt3,z});
          islands.erase({j,b^1,cnt2});
          pq.erase({cnt2,j});
          islands.insert({j,b3,cnt3+cnt2});
          pq.insert({cnt3+cnt2,j});
        } else if (cnt-1 != 0) {
          islands.insert({i+1,b,cnt-1}); 
          pq.insert({cnt-1,i+1});
        }
      } else if (cnt-1 != 0) {
        islands.insert({i+1,b,cnt-1}); 
        pq.insert({cnt-1,i+1});
      }
    } else if (k == i+cnt-1) {
      if (it != islands.end()) {
        auto jt = next(it);
        islands.erase({i,b,cnt});
        pq.erase({cnt,i});
        auto [j,_,cnt2] = *jt;
        islands.erase({j,b^1,cnt2});
        islands.insert({j,b^1,cnt2+1});
        pq.erase({cnt2,j});
        pq.insert({cnt2+1,j});
      } else {
        islands.erase({i,b,cnt});
        pq.erase({cnt,i});
        islands.insert({k,b^1,1});
        pq.insert({1,k});
      }
      if (cnt-1 != 0) {
        islands.insert({i,b,cnt-1}); 
        pq.insert({cnt-1,i});
      }
    } else {
      islands.erase({i,b,cnt});
      pq.erase({cnt,i});
      int L = k-i;
      int R = cnt+i-k;
      islands.insert({k, b^1, 1});
      pq.insert({1, k});
      if (L) {
        islands.insert({i,b,L});
        pq.insert({L,i});
      }
      if (R) {
        islands.insert({k+1,b,R});
        pq.insert({R,k+1});
      }
    }
    cout << dbg(pq) << "\n" dbg(islands) << "\n";
    cout << (*--pq.end()).first << " ";
  }
}
