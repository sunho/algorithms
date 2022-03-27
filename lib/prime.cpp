vector<int> d;
vector<vector<int>> factors;
d.assign(N, 1);
factors.resize(N);
for (int i = N-1; i > 1; i--)
    for (int j = i; j < N; j += i)
        d[j] = i;
for (int i = 1; i < N; i++)
    for (int x = i; x != 1; x /= d[x])
        factors[i].push_back(d[x]);


trav(p, factors[r1]) f[p]--;

