#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int INF = 999999999;


int solve(int mem[200000][4][4][4], int a[200000], int i, int r, int n, int k, int maxn, int minn) {
    if (maxn != 0 && maxn - minn > k) return 0;
    int key1;
    int key2;
    if (max(maxn, a[i]) - a[i] > k) {
        key1 = 3;
    } else {
        key1 = maxn - a[i];
    }
     if (min(minn, a[i]) - minn > k) {
        key2 = 3;
    } else {
        key2 = a[i]-minn;
    }
    if (maxn != 0) {
        if (mem[i][r][key1][key2] != -INF) {
            return mem[i][r][key1][key2];
        }
    }
   
    if (r == 0) return 1;
    if (i == n) return 0;


    int key;
            //if (mem.find(key) != mem.end()) return mem[key];
    
    int out = solve(mem, a, i + 1, r - 1, n, k, max(a[i], maxn), min(a[i], minn)) + solve(mem, a, i + 1, r, n, k, maxn, minn);
    if (maxn != 0) {
        mem[i][r][key1][key2] = out;
    }
   // mem[key] = out;
    return out;
}

int main() {
  

    int a[200000];
    int mem[200000][4][4][4] = {-INF};
    int t;

    cin >> t;
    
    for (int l = 0; l < t; ++l) {
        //mem.clear();
        memset(mem, -INF, sizeof(mem));
        int n;
        cin >> n;
       // int m,k;
        //cin >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve(mem, a, 0, 3, n, 2, 0, 200001) << endl;
    }
}