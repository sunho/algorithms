#include <bits/stdc++.h>

using namespace std;

#define double long double

const int N = 1 << 15;
const int M = 50;
char done[N][2][M+1][15+1];
double dp[N][2][M+1][15+1];

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

  auto get_rem = [&](int used, int sel) {
    int rem = 0;
    for (int i : B[sel]) {
      if (!((used >> i) & 1)) {
        rem++;
      }
    }
    return rem;
  };

  auto f = [&](auto&& self, char turn, int used, int sel, int times) -> double {
    double& tdp = dp[used][turn==team][sel][times];
    if (done[used][turn==team][sel][times]) {
      return tdp;
    }
    if (sel == 0) {
      if (turn == team) {
        double res = 0.0;
        for (int i=0;i<m;i++) {
          for (int j=1;j<=get_rem(used, i);j++) {
            res = max(res, self(self, turn, used, i+1, j));
          }
        }
        done[used][turn==team][sel][times] = 1;
        return tdp = res;
      } else {
        double res = 1.0;
        for (int i=0;i<m;i++) {
          for (int j=1;j<=get_rem(used, i);j++) {
            res = min(res, self(self, turn, used, i+1, j));
          }
        }
        done[used][turn==team][sel][times] = 1;
        return tdp = res;
      }
    }
    double res = 0.0;
    int rem = get_rem(used, sel-1);
    int team_rem = 0;
    int rev_team_rem = 0;
    char rev_team  = turn == 'R'?'B':'R';
    for (int i=0;i<n;i++) {
      if (!((used >> i) & 1)) {
        if (S[i] == turn) {
          team_rem ++;
        } else if (S[i] == rev_team) {
          rev_team_rem ++;
        }
      }
    }
    assert(rem != 0);
    if (times == 0) {
      done[used][turn==team][sel][times] = 1;
      return tdp=self(self, rev_team, used, 0, 0);
    }
    for (int i : B[sel-1]) {
      if (!((used >> i) & 1)) {
        if (S[i] == 'A') {
          if (turn == team) {
            res += 0.0;
          } else {
            res += 1.0/rem;
          }
        } else if (S[i] == 'I') {
          res += 1.0/rem*self(self, rev_team, used | (1 << i), 0, 0);
        } else if (S[i] == turn) {
          if (team_rem == 1) {
            if (turn == team) {
              res += 1.0/rem;
            } else {
              res += 0.0;
            }
          } else if (rem == 1) {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), 0, 0);
          } else {
            res += 1.0/rem*self(self, turn, used | (1 << i), sel, times-1);
          }
        } else if (S[i] == rev_team) {
          if (rev_team_rem == 1) {
            if (turn == team) {
              res += 0.0;
            } else {
              res += 1.0/rem;
            }
          } else {
            res += 1.0/rem*self(self, rev_team, used | (1 << i), 0, 0);
          } 
        }
      }
    }
    done[used][turn==team][sel][times] = 1;
    return tdp = res;
  };
  cout << fixed << setprecision(15) << f(f, team, 0, 0, 0) << "\n";
}
