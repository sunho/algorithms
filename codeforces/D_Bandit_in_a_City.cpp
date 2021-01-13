#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// M = max of last nodes 
// R = sum of last nodes
// n = num of last nodes

// Given a_i
// if R < M*n
//   a_i -= M*n - R
//   R = M*n
// else 
//   a_i = 0
//   dM = (a-1)/n + 1
//   M += dM
//   R += a_i - dM
int n;
vector<int> g[200002];
int nodes[200002] = {0};

struct Info {
    long long M;
    long long R;
    int n;
};

Info dfs(int i) {
    Info out;
    out.M = 0;
    out.R = 0;
    out.n = 0;

    for (auto &child : g[i]) {
        auto cc = dfs(child);
        out.M = max(out.M, cc.M);
        out.n += cc.n;
        out.R += cc.R;
    }

    if (g[i].empty()) {
        out.M = nodes[i];
        out.n = 1;
        out.R = nodes[i];
    } else {
        int a = nodes[i];
        if (out.R < out.M * out.n) {
            long long delta = min((long long)a, out.M * out.n - out.R);
            a -= delta;
            out.R += delta;
        }
        if (a != 0) {
            long long deltaM = (a-1) / out.n + 1;
            out.M += deltaM;
            out.R += a;
        }
    }

    return out;
}

int main() {
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        nodes[i] = p;
    }

    auto out = dfs(1);
    cout << out.M << endl;
    return 0;
}