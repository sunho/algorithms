#include <bits/stdc++.h>
using namespace std;

void gen(int x) {
    cout << x << endl;
    for (int i = 1; i <= x; i++)
        cout << 1000000000 << " \n"[i == x];
    for (int i = 1; i <= x; i++)
        cout << 1000000000 << " \n"[i == x];
}

int main() {
    cout << 1 << endl;
    gen(300000);
    return 0;
}
