#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int la = -1;
        int mscore = 0;
        int score = 0;
        while(n--) {
            int a;
            cin >> a;
            if (la != a) {
                la = a;
                score = 0;
            }
            mscore = max(mscore, ++score);
        }
        cout << mscore << endl;
    }
}