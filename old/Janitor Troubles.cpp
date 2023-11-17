#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  char team;
  cin >> team;
  
  vector<string> A(n);
  map<string, int> M;
  for (int i=0;i<n;i++) {
    cin >> A[i];
    M[A[i]] = i;
  }
  vector<char> S(n);
  for (int i=0;i<n;i++){
    cin >> S[i];
  }

  int m;
  cin >> m;
  vector<vector<int>> B(m);
  for (int i=0;i<m;i++){
    int k;
    cin >> k;
    for (int j=0;j<k;j++){
      string s;
      cin >> s;
      B[i].push_back(M[s]);
    }
  }

  auto f = [&](auto&& self, char turn, int used, int sel) -> double {
    if (sel == 0) {
      vector<int> avail;
      for (int i=0;i<m;i++){
        bool ok = false;
        for (int j : B[i]) {
          if ((used >> j)&1) {
            ok = true;
          }
        }
        if (ok){
          avail.push_back(i);
        }
      }
      if (turn == team) {
        double res = 0.0;
        for (int i : avail) {
          res = max(res, self(self, turn, used, i));
        }
        return res;
      } else {
        double res = 1.0;
        for (int i : avail) {
          res = min(res, self(self, turn, used, i));
        }
        return res;
      }
    }
    double res = 0.0;
    int rem = 0;
    int team_rem = 0;
    int rev_team_rem = 0;
    char rev_team  = turn == 'R'?'B':'R';
    for (int i : B[sel]) {
      if (!((used >> i) & 1)) {
        rem++;
      }
    }
    for (int i=0;i<n;i++) {
      if (!((used >> i) & 1)) {
        if (S[i] == turn) {
          team_rem ++;
        } else if (S[i] == rev_team) {
          rev_team_rem ++;
        }
      }
    }
    for (int i : B[sel]) {
      if (!((used >> i) & 1)) {
        if (S[i] == 'A') {
          res += 0.0;
        } else if (S[i] == 'I') {
          res += 1.0/rem*self(self, rev_team, used | (1 << i), 0);
        } else if (S[i] == team) {
          if (team_rem == 1) {
            res += 1.0;
          } else if (rem == 1) {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), 0);
          } else {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), sel);
          }
        } else if (S[i] == rev_team) {
          if (rev_team_rem == 1) {
            res += 0.0;
          } else if (rem == 1) {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), 0);
          } else {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), sel);
          }
        }
      }
    }
    return res;
  };
  cout << f(f, team, 0, 0) << "\n";
}
