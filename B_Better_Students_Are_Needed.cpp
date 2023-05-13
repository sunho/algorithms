#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n,x,y,z;
  cin >> n >> x >> y >> z;

  vector<int> A(n);
  vector<int> B(n);
  for (int i=0;i<n;i++) cin >> A[i];
  for (int i=0;i<n;i++) cin >> B[i];
  vector<tuple<int,int,int>> cands;
  for (int i=0;i<n;i++){
    cands.push_back({A[i],B[i],i});
  }
  sort(begin(cands), end(cands), [&](auto a, auto b) {
    if (get<0>(a) == get<0>(b)) return get<2>(a) > get<2>(b);
    return get<0>(a) < get<0>(b);
  });
  vector<int> admitted;
  while (!cands.empty() && x != 0) {
    admitted.push_back(get<2>(cands.back()));
    cands.pop_back();
    x--;
  }
  sort(begin(cands), end(cands), [&](auto a, auto b) {
    if (get<1>(a) == get<1>(b)) return get<2>(a) > get<2>(b);
    return get<1>(a) < get<1>(b);
  });
  while (!cands.empty() && y != 0) {
    admitted.push_back(get<2>(cands.back()));
    cands.pop_back();
    y--;
  }
  sort(begin(cands), end(cands), [&](auto a, auto b) {
    if (get<0>(a) + get<1>(a) == get<0>(b) + get<1>(b)) return get<2>(a) > get<2>(b);
    return get<0>(a) + get<1>(a) < get<0>(b) + get<1>(b);
  });
   while (!cands.empty() && z != 0) {
    admitted.push_back(get<2>(cands.back()));
    cands.pop_back();
    z--;
  }
  sort(begin(admitted), end(admitted));
  for (int x : admitted) {
    cout << x + 1 << "\n";
  }
}
