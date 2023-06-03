#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<string> ans;
  
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  vector<char> chars(26);
  iota(chars.begin(), chars.end(), 'a');
  auto go = [&]() -> bool {
    ans.clear();
    vector<unordered_set<string>> vis(10);
    unordered_set<string> words;
    string last = "aaaaaaaaaa";
    for (int i=0;i<n-1;i++){
      words.insert(last);
      ans.push_back(last);
      bool done = false;
      for (int j=0;j<10;j++){
        string cand = last.substr(0,j) + last.substr(j+1);
        if (vis[j].count(cand)) {
          continue;
        }
        bool found = false;
        string nw = last;
        shuffle(chars.begin(), chars.end(), std::default_random_engine(seed));
        for (char a : chars) {
          if (a == last[j]) continue;
          nw[j] = a;
          bool ok = true;
          for (int z=0;z<10;z++){
            string cand = nw.substr(0,z) + nw.substr(z+1);
            if (vis[z].count(cand)) {
              ok = false;
            }
          }
          if (!ok) continue;
          found = true;
          break;
        }
        if (!found) continue;
        for (int z=0;z<10;z++){
          string str = last.substr(0,z)+last.substr(z+1);
          vis[z].insert(str);
        }
        last = nw;
        done = true;
        break;
      }
      if (!done) return false;
    }
    ans.push_back(last);
    return true;
  };
  while (!go()) {
  }
  for (string s : ans) {
    cout << s << "\n";
  }
}
