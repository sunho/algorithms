#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, vector<int>> S;
  for (int i=0;i<n;i++){
    S[s[i]].push_back(i);
  }
  vector<pair<int,string>> cands;
  for (int m=1;m<=26;m++){
    if (n%m != 0) continue;
    int cnt = n/m;
    vector<int> dels;
    auto A = S;
    vector<pair<int,char>> rems;
    set<char> used;
    for (auto& [k,v] : A) {
      while (v.size() > cnt) {
        dels.push_back(v.back());
        v.pop_back();
      }
      rems.push_back({v.size(), k});
      used.insert(k);
    }
    sort(rbegin(rems),rend(rems));
    while (rems.size() > m) {
      for (int i : A[rems.back().second]) {
        dels.push_back(i);
      }
      used.erase(rems.back().second);
      rems.pop_back();
    }
    int ans_cnt = dels.size();
    auto ans = s;
    int need = m;
    int new_need = m-used.size();
    for (char c='a';c<='z'&&need>0;c++){
      if (used.count(c)) {
        for (int z=0;z<cnt-A[c].size();z++){
          ans[dels.back()] = c;
          dels.pop_back();
        }
        need--;
      } else if (new_need > 0) {
        for (int z=0;z<cnt;z++){
          ans[dels.back()] = c;
          dels.pop_back();
        }
        need--;
        new_need--;
      }
    }
    for (int i : dels) {
      cout << m << " " << i << "\n";
    }
    assert(dels.empty());
    cands.push_back({ans_cnt, ans});
  }
  sort(begin(cands),end(cands));
  cout << cands[0].first << "\n";
  cout << cands[0].second << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
