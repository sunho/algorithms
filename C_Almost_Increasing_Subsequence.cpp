#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 200005
#define SIZE 200005

long long bit[SIZE];
 
long long sum(int i)
{
    i++;
    long long sum = 0;
    while (i > 0)
    {
        sum += bit[i];
        i -= (i) & -(i);
    }
    return sum;
}
 
void add(int i, long long delta)
{
    i++;
    while (i <= SIZE)
    {
        bit[i] += delta;
        i += (i) & -(i);
    }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> A(n);
  for (int i=0;i<n;i++) cin >> A[i];
  vector<pair<int,int>> queries(q);
  for (int i=0;i<q;i++){
    cin >> queries[i].first >> queries[i].second;
    --queries[i].first, --queries[i].second;
  }
  vector<int> id(q);
  iota(begin(id),end(id), 0);
  sort(begin(id), end(id), [&](auto a, auto b) {return queries[a].second < queries[b].second;});
  sort(begin(queries), end(queries), [&](auto a, auto b) {return a.second < b.second;});
  vector<vector<int>> blocks;
  vector<int> ans(q);
  for (int i=0,rr=0;i<q;i++){
    auto [l,r] = queries[i];
    while (rr <= r) {
      if (blocks.size() == 0) {
        blocks.push_back({A[rr]});
        add(rr,1);
      } else {
        if (blocks.back().back() >= A[rr]) {
          blocks.back().push_back(A[rr]);
          add(rr,1);
          if (blocks.back().size() > 2) {
            add(rr-2,-1);
          }
        } else {
          blocks.push_back({A[rr]});
          add(rr,1);
        }
      }
      rr++;
    }
    ans[id[i]] = sum(r) - sum(l-1);
  }
  for (int i=0;i<q;i++){
    cout << ans[i] << "\n";
  }
}
