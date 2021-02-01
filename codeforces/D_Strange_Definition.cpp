#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;

#define N 1000001
#define endl '\n'
bool spvst[N];
int sp[N];
bool spqvst[N];
int spq[N];
int spn[N];

int classify(int a) {
    int out = 1;
    while (a != 1) {
        int i = sp[a];
        int k = 0;
        int back = a;
        if (!spqvst[a]) {
            while (a % i == 0) {
                a /= i;
                ++k;
            }
            spq[back] = a;
            spn[back] = k;
            spqvst[back] = true;
        } else {
            k = spn[a];
            a = spq[a];
        }
       
        if (k % 2 == 1) {
            out *= i;
        }
    }
    return out;
}

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < N; i += 2) {
        sp[i] = 2;
    }
    for (int i = 3; i < N; i += 2) {
        if (!spvst[i]) {
            sp[i] = i;
            for (ll j = i; (j*i) < N; j += 2) {
                if(!spvst[j*i]) {
                    spvst[j*i] = true;
                    sp[j*i] = i;
                }
            }
        }
    }


    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int maxfst = 0;
        map<int, int> count;
        while(n --) {
            int a;
            cin >> a;
            int k = classify(a);
            if (count.find(k) == count.end()) {
                count[k] = 0;
            }
            auto& cc = count[k];
            cc++;
            maxfst = max(maxfst, cc);
        }

        int evens = 0;
        for (auto [k, cc] : count) {
            if (cc % 2 == 0 || k == 1) {
                evens += cc;
            }
        }

        int q;
        cin >> q;
        while(q--) {
            ll w;
            cin >> w;
            if (w > 0) {
                cout << max(maxfst,evens) << endl;
            } else {
                cout << maxfst << endl;
            }
        }
    }
       
    return 0;
}