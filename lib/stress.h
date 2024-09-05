#if 0

#if !defined(ONLINE_JUDGE)
#include "lib/stress.h"
void brute() {
}

void gen_testcase(int t) {
  int n = 10;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << rnd(-1000, 1000) << ' ';
  }
  cout << '\n';
}
#endif

signed main() {
#if !defined(ONLINE_JUDGE) && defined(STRESS)
  run_stress(100, false);
#else
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
#endif
}

#endif

ll rnd(ll mn, ll mx) {
  static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<ll> gen(mn, mx);
  return gen(rng);
}

vector<int> rnd_array(int n, int mn, int mx) {
  int in = 0;
  vector<int> A(n);
  int m = mx - mn + 1;
  for (int i = 0; i < m && in < n; ++i) {
    int rm = m - i;
    int rn = n - in;
    if (rnd(0, rm - 1) < rn)
      A[in++] = i;
  }
  assert(in == n);
  return A;
}

vector<pair<int, int>> rnd_tree(int n) {
  vector<pair<int, int>> res;
  for (int i = 2; i <= n; i++) {
    res.push_back({i, rnd(1, i - 1)});
  }
  return res;
}

void gen_testcase(int t);
void brute();
void solve();

stringstream testcase, brute_cin, brute_cout, solve_cin, solve_cout;

bool compare_outputs() {
  string bruteStr, solveStr;
  while (getline(brute_cout, bruteStr) && getline(solve_cout, solveStr)) {
    while (bruteStr.back() == ' ')
      bruteStr.pop_back();
    while (solveStr.back() == ' ')
      solveStr.pop_back();
    if (bruteStr != solveStr)
      return false;
  }
  return true;
}

void run_stress(int T, bool log) {
  for (int t = 1; t <= T; t++) {
    cout.rdbuf(testcase.rdbuf());
    gen_testcase(t);

    string testCase_str = testcase.str();
    if (log) {
      cerr << "TestCase " << t << ":\n"
        << testCase_str << endl;
    }

    brute_cin << testcase.str();
    solve_cin << testcase.str();
    cout.rdbuf(brute_cout.rdbuf());
    cin.rdbuf(brute_cin.rdbuf());
    brute();

    cout.rdbuf(solve_cout.rdbuf());
    cin.rdbuf(solve_cin.rdbuf());
    solve();
    string bruteCout_str = brute_cout.str();
    string solveCout_str = solve_cout.str();
    if (!compare_outputs()) {
      if (!log) {
        cerr << "TestCase " << t << ":\n"
          << testCase_str << endl;
      }
      cerr << "TestCase " << t << " failed!\n\n";

      cerr << "Expected Output:\n"
        << bruteCout_str << endl;
      cerr << "Received Output:\n"
        << solveCout_str << endl
        << endl;
      return;
    }
    cerr << "TestCase " << t << " passed!\n\n";
    if (log) {
      cerr << "Output:\n"
        << solveCout_str << endl
        << endl;

      cerr << "---------------------------------------\n";
    }
    testcase = stringstream();
    brute_cin = stringstream();
    brute_cout = stringstream();
    solve_cin = stringstream();
    solve_cout = stringstream();
  }
  cerr << "All TestCases Passed" << endl;
}
